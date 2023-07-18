/*
Greener GreenHouses RH/T Test Harness
authors: mkaltman@ucsc.edu , tikraeme@ucsc.edu
Date Created : 7/17/2023  2:19pm
Last Edited : 7/18/2023   4:05pm
*/

#include <HDC2080.h>
#include <SD.h>
#include <SPI.h>

#define ADDR 0x40

#define ARGUS_GH_Humidity "ARGH_H.txt"
#define ARGUS_GH_Temp "ARGH_T.txt"
#define GGH_GH_Humidity "GGGH_H.txt"
#define GGH_GH_Temp "GGGH_T.txt"
//=====================================================
#define GGH_GRO_Humidity "GGGO_H.txt"   
#define GGH_GRO_Temp "GGGO_T.txt"
#define ARGUS_GRO_Humidity "ARGO_H.txt"
#define ARGUS_GRO_Temp "ARGO_T.txt"

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

  sensor.triggerMeasurement();
}

void loop() {
  
  //add in SD Card data recording

  delay(1000);
}
