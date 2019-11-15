/*
  Code to measure distance of the nearest object using ultrasonic
  sensors and arduino uno.
*/

// initializing pins
const int trig_pin = 13;   // pin 13 as a trigger pin for ultrasonic sensor
const int echo_pin = 12;   // pin 12 as an echo pin for ultrasonic sensor

long duration;
int distance_cm, distance_inche;

long trigger_ultrasonic_sensor(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  return pulseIn(echo, HIGH);
}

int distance_in_cm(long duration) {
  return duration * 0.0340 / 2;
}

int distance_in_inch(long duration) {
  return duration * 0.01330 / 2;
}

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  duration = trigger_ultrasonic_sensor(trig_pin, echo_pin);
  Serial.print("Distance in cm: ");
  Serial.println(distance_in_cm(duration));
  Serial.print("Distance in inch: ");
  Serial.println(distance_in_inch(duration));
}
