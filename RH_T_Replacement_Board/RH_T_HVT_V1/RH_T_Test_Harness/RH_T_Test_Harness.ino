/*
Greener GreenHouses RH/T Test Harness
authors: mkaltman@ucsc.edu , tikraeme@ucsc.edu
Date Created : 7/17/2023  2:19pm
Last Edited : 7/27/2023   11:00am
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

//File ARG_H;
//File ARG_T;
//File GGH_H;
//File GGH_T;

HDC2080 sensor(ADDR);

float temperature = 0, humidity = 0;

void setup() {
  Serial.begin(9600);

  sensor.begin();

  sensor.reset();

  sensor.setMeasurementMode(TEMP_AND_HUMID);
  sensor.setRate(ONE_HZ);
  sensor.setTempRes(FOURTEEN_BIT);
  sensor.setHumidRes(FOURTEEN_BIT);

  sensor.triggerMeasurement();

 //Serial.print("Initializing SD card...");

  //if (!SD.begin(4)) {
  //  Serial.println("initialization failed!");
  //  while (1);
  //}
  //Serial.println("initialization done.");

  //reading and storing GGH temp value
  //GGH_T = SD.open(GGH_GRO_Temp,FILE_WRITE);
  
// //reading and storing GGH humidity value
  //GGH_H = SD.open(GGH_GRO_Humidity,FILE_WRITE);
}



void loop() {
  

//easy #ifdef to switch between which sensor is being used, ARGUS or GGH

  float x,y;
  x = sensor.readHumidity();
  y = sensor.readTemp();

  Serial.print("Temperature (C): "); Serial.print(y);
  Serial.print("\t\tHumidity (%): "); Serial.println(x);
  

  //GGH_H.println(x);
  //GGH_H.flush();
  //GGH_T.println(y);
  //GGH_T.flush();

  delay(1000);



 
  

}
