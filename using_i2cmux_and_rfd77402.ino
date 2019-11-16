/*
  Example of controlling SparkFun Distance Sensor RFD77402 
  using i2c mux and Arduino Uno
*/

// SparkFun RFD77402 Distance Sensor - VCSEL Time of Flight - Version: Latest 
#include <SparkFun_RFD77402_Arduino_Library.h>
#include <Wire.h>

// i2c mux address
#define TCAADDR 0x70

RFD77402 myDistance; //Hook object to the library

/**
 *  Function to initialize sensors connected to i2c mux 
 */
void tca_select (uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

int get_distance(int sensor) {
  tca_select(sensor);
  myDistance.takeMeasurement();
  return myDistance.getDistance(); //Retrieve the distance value
}

void setup() {
  // initialize sensor1 connected to SD0 and SC0
  tca_select(0);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("RFD77402 Testing");
}

void loop() {
  unsigned int distance = get_distance(0);
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("mm");
  Serial.println();
}
