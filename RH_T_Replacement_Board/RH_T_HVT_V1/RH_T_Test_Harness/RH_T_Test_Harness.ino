/*
Greener GreenHouses RH/T Test Harness
authors: mkaltman@ucsc.edu , tikraeme@ucsc.edu
Date Created : 7/17/2023  2:19pm
Last Edited : 7/19/2023   11:36pm
*/

#include <HDC2080.h>
#include <SD.h>
#include <SPI.h>

#define ADDR 0x40
#define CS 10

#define ARGUS_GH_Humidity "ARGH_H.txt"
#define ARGUS_GH_Temp "ARGH_T.txt"
#define GGH_GH_Humidity "GGGH_H.txt"
#define GGH_GH_Temp "GGGH_T.txt"
//=====================================================
#define GGH_GRO_Humidity "GGGO_H.txt"   
#define GGH_GRO_Temp "GGGO_T.txt"
#define ARGUS_GRO_Humidity "ARGO_H.txt"
#define ARGUS_GRO_Temp "ARGO_T.txt"

File ARG_H;
File ARG_T;
File GGH_H;
File GGH_T;

HDC2080 sensor(ADDR);

float temperature = 0, humidity = 0;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  sensor.begin();

  sensor.reset();

  sensor.setMeasurementMode(TEMP_AND_HUMID);
  sensor.setRate(ONE_HZ);
  sensor.setTempRes(FOURTEEN_BIT);
  sensor.setHumidRes(FOURTEEN_BIT);
  pinMode(CS,OUTPUT);
  sensor.triggerMeasurement();
}

void loop() {
  
  //making sure that the sd reader is initialized correctly
  if(!SD.begin(CS)){
    Serial.println("Initialization Failed...");
    return;
  }
  Serial.println("SD Initialization Complete");

//easy #ifdef to switch between which sensor is being used, ARGUS or GGH

  #ifdef ARG
  //reading and storing ARGUS humidity value
  ARG_H = SD.open(ARGUS_GRO_Humidity,FILE_WRITE);
  ARG_H.println(" %d ",sensor.readHumidity()); 
  ARG_H.close();

//reading and storing ARGUS temperature value
  ARG_T = SD.open(ARGUS_GRO_Temp,FILE_WRITE);
  ARG_T.println(" %d ",sensor.readTemp());
  ARG_T.close();
  #endif

  #ifdef GGH
//reading and storing GGH humidity value
  GGH_H = SD.open(GGH_GRO_Humidity,FILE_WRITE);
  GGH_H.println(" %d ",sensor.readHumidity());
  GGH_H.close();

//reading and storing GGH temp value
  GGH_T = SD.open(GGH_GRO_Temp,FILE_WRITE);
  GGH_T.println(" %d ",sensor.readTemp());
  GGH_T.clos();

  #endif

  delay(1000);
}
