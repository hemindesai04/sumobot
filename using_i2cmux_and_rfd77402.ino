/*
  Example of controlling SparkFun Distance Sensor RFD77402 
  using i2c mux and Arduino Uno
*/

// SparkFun RFD77402 Distance Sensor - VCSEL Time of Flight - Version: Latest 
#include <SparkFun_RFD77402_Arduino_Library.h>
#include <Wire.h>

// i2c mux address
#define TCAADDR 0x70

//Hook objects to the library
RFD77402 myDistance1;
RFD77402 myDistance2;
RFD77402 myDistance3;
RFD77402 myDistance4;
RFD77402 myDistance5;

/**
 *  Function to initialize sensors connected to i2c mux 
 */
void tca_select (uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

/**
 * Function to get distance of the nearest object
 * using the given sensor.
 */
int get_distance(int sensor, RFD77402 myDistance) {
  tca_select(sensor);
  myDistance.takeMeasurement();
  return myDistance.getDistance(); //Retrieve the distance value
}

/**
 * Helper function to print distance of the nearest object from
 * the given sensor.
 */
void print_helper(int number, int distance) {
  String disp_string = "Sensor " + number;
  String dist_string = disp_string + ": distance = ";
  Serial.print(dist_string);
  Serial.print(distance);
  Serial.print("mm");
  Serial.println();
}

void setup() {
  // initialize sensor1 through sensor5 connected to 
  // SD0 and SC0 through SD4 and SC4
  for (int i = 0; i < 5; i++) {
    tca_select(i);
  }
  Serial.begin(9600);
  while (!Serial);
  Serial.println("RFD77402 Testing");
}

void loop() {
  RFD77402 distance[5] = {myDistance1, myDistance2, myDistance3,
                          myDistance4,myDistance5};
  for (int i = 0; i < 5; i++) {
    unsigned int distance_mm = get_distance(i, distance[i]);
    print_helper(i, distance_mm);
  }
}
