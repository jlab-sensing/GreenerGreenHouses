/*
Greener GreenHouses RH/T Test Harness
authors: mkaltman@ucsc.edu , tikraeme@ucsc.edu
Date Created : 7/17/2023  2:19pm
Last Edited : 7/17/2023   2:20pm
*/

#include <HDC2080.h>

#define ADDR 0x40

HDC2080 sensor(ADDR);

float temperature = 0, humidity = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial);

  sensor.begin();

  sensor.reset();

  sensor.setMeasurementMode(TEMP_AND_HUMID);
  sensor.setRate(ONE_HZ);
  sensor.setTempRes(FOURTEEN_BIT);
  sensor.setHumidRes(FOURTEEN_BIT);

  senor.triggerMeasurement();
}

void loop() {
  
  //add in SD Card data recording

  delay(1000);
}
