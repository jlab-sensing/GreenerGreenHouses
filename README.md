# JLab - Greener Greenhouses Sensing Project

This repository contains concurrent work for the Greener Greenhouses research project.

## Repository Contents

- **MSP430**
  
    Contains a general library for the [TI MSP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en) microcontroller to communicate with the [HDC2021](https://www.ti.com/product/HDC2021?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=HDC2021&ds_k=HDC2021&DCM=yes&gclid=Cj0KCQjwrfymBhCTARIsADXTabmBxpIyiHJQwz-0fqVoGLloWWmzIEXDT699dNn-ivyHtGXB0x-GpR8aAtybEALw_wcB&gclsrc=aw.ds) Temperature and Humidity Sensor.
  
- **PassiveLiFiTag**

    Includes schematic files for a prototype of the Passive LiFi IoT tag using the TI MSP430FR5969 microcontroller

- **RH_T_Replacement_Board**

    Contains .ino test harness and data storage files for HDC2021 sensor testing using Arduino
    
- **Sensor Power Comparison**

    Power consumption models for temperature & humidity sensor comparison, as well as CCS project for power trace measurement on MSP430 programs

  ## To Do

  - [ ] Create specific README file for each directory
  - [ ] file cleanup - remove defunct or unnecessary files
  - [ ] Update root README when new directories are created
  - [ ] Standardize naming conventions for each directory
