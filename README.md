# JLab - Greener Greenhouses Sensing Project

This repository contains concurrent work for the Greener Greenhouses research project.

## Repository Contents

- **MSP430**
  
    Contains a general library for the [TI MSP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en) microcontroller to communicate with the [HDC2021](https://www.ti.com/product/HDC2021?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=HDC2021&ds_k=HDC2021&DCM=yes&gclid=Cj0KCQjwrfymBhCTARIsADXTabmBxpIyiHJQwz-0fqVoGLloWWmzIEXDT699dNn-ivyHtGXB0x-GpR8aAtybEALw_wcB&gclsrc=aw.ds) Temperature and Humidity Sensor.
  
- **PassiveLiFiTag**

    Includes schematic files for a prototype of the Passive LiFi IoT tag using the TI MSP430FR5969 microcontroller

- **RH_T_Replacement_Board**

    Contains .ino test harness and data storage files for HDC2021 sensor testing using Arduino. Also contains Eagle hardware files for the GGH RH/T replacement board
    
- **LoRa_BoosterPack_Registers**

    Currently only contains register names and settings for ETSI CAT1 869MHz. 1.2Kbps, 2-GFSK, 25Khz channel spacing, ETSI EN 300 220 CAT1 setting with the [CC1125 LoRa module Boosterpack](https://www.ti.com/tool/BOOSTXL-CC1125). Register names and values exported from [SmartRFStudio v7.0](https://www.ti.com/tool/SMARTRFTM-STUDIO) for packet Tx/Rx.

- **BeagleBoneBlack**

    Contains source code for Beaglebone Black development, specifically work on SPI to LoRa boosterpack compatability, and ModbusLib test code for server/client side testing.

  ## To Do

  - [x] Create specific README file for each directory
  - [ ] file cleanup - remove defunct or unnecessary files
  - [ ] Update root README when new directories are created
  - [x] Standardize naming conventions for each directory
  - [x] License Project under MIT
