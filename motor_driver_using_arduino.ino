/*
 Code to drive two motors using motor driver IC L293D and Arduino.
*/

// initializing pins
const int pwm1 = 5;   // pin 5 as pwm for motor1
const int pwm2 = 3;   // pin 3 as pwm for motor2
const int out1 = 8;   // pin 8 as the first output pin for motor1
const int out2 = 9;   // pin 9 as the second output pin for motor1
const int out3 = 10;  // pin 10 as the first output pin for motor2
const int out4 = 11;  // pin 11 as the second output pin for motor2

void driveMotor(int output1, int output1_value, 
                int output2, int output2_value, 
                int pwm_output, int pwm_output_value) {
  // for clockwise motion: out1 = low and out2 = high
  // for anti-clockwise motion: out1 = high and out2 = low
  
  digitalWrite(output1, output1_value);
  digitalWrite(output2, output2_value);
  analogWrite(pwm_output, pwm_output_value);
}

void brake(int output1, int output2) {
  digitalWrite(output1, HIGH);
  digitalWrite(output2, HIGH);
}

void setup() {
    // Let's set the modes of the pwm and output pins
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);
    pinMode(out4, OUTPUT);
}

void loop() {
  
  // drive motor1 and motor2 in clockwise direction for 5 seconds
  driveMotor(out1, LOW, out2, HIGH, pwm1, 255);
  driveMotor(out3, LOW, out4, HIGH, pwm2, 255);
  delay(5000);
  
  // brake
  brake(out1, out2);
  brake(out3, out4);
  delay(2000);
  
  // drive motor1 and motor2 in anti-clockwise direction for 5 seconds
  driveMotor(out1, HIGH, out2, LOW, pwm1, 255);
  driveMotor(out3, HIGH, out4, LOW, pwm2, 255);
  delay(5000); 
}
