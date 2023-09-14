# Greener GreenHouses New Member Onboarding
Welcome to J-Lab's Greener Greenhouses project! This document should provide all the information and references that a new team member should need in order jump into the action. If information is incomplete or vague, feel free to message [Matthew Kaltman](mailto:mkaltman@ucsc.edu?subject=[GitHub]%20Source%20Han%20Sans), [Tim Kraemer](mailto:tikraeme@ucsc.edu?subject=[GitHub]%20Source%20Han%20Sans), or [Jack Lin](mailto:jlin143@ucsc.edu?subject=[GitHub]%20Source%20Han%20Sans).

## Project Overview
The Greener Greenhouses project is one led by professors Colleen Josephson [ECE], Katia Obraczka [CSE], and Michael Loik [ENVS] in conjunction with [IMDEA Networks](https://networks.imdea.org/about-imdea-networks/) based in Spain. The goal of this project is to use a novel visible-light (LiFi) enabled IOT approach to monitor and control greenhouses, thereby improving energy efficiency, reducing water usage, and growing healthier, more nutritious plants. The low-cost, energy-efficient LiFi technology uses LED lights to power sensors, transmit data, and provide supplemental on foggy or short winter days. LED lighting can be controlled based on environmental conditions as well as the specific needs of the plants, addressing the productivity versus energy efficient tradeoffs. 


In order to implement and quantify the benefits of a LiFi enabled IOT system, the members of this team will compare the power consumption and resource efficiency of several control schemes. 
* Argus Controls System (Current)
* Traditional Battery-Powered IOT Device
* LiFi Enabled IOT Device

These sub-systems and their related resources will be discussed further below. A detailed overview of the planned LiFi system that will be integrated into the current greenhouse control system is provided here.

![image|600x371](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/08766264-8e22-4e1d-bff3-384b1e383e17 )


## Current Greenhouse Control System
The current system equipped in UCSC's [Coastal Biology Greenhouses](https://greenhouse.ucsc.edu/research/facility-cbg.html) is driven by [Argus Controls](https://arguscontrols.com/), and a detailed overview of this baseline system can be found [here](https://drive.google.com/drive/folders/1_lNfw5vJW_Q_KWBBiqxn9BiAg7NH7jfJ?usp=sharing). Provided below is a basic diagram of the current functionality, where all actuators and sensors are tied to the Argus Titan IO module and controlled from the greenhouse director's office.

<p align="center">
<img width="480" height="500" src="https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/9187ddc8-56a3-427e-ab8b-aa702891e5ed">
</p>



## Traditional IOT System

A system diagram of our traditional low-power IOT device is provided below in order for new members to gain an understanding of every link involved in this traditional system. Here, the brains of the system is TI's MSP430FR5969 launchpad which is polling relative humidity and temperature sensors and transmitting this information over LoRa. Receiving this information is a Beagle Bone Black that acts as a sensor manager and communicates with the Argus control software in order to send data and receive commands.

![image](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/9b7c92c4-6507-470a-a9c7-7d83ccedcf46)



### GGH RH/T Sensor

### MSP430FR5969 Launchpad

#### Overview
The microcontroller being utilized by the GGH team is the [MSP430FR5969](https://www.ti.com/product/MSP430FR5969?utm_source=google&utm_medium=cpc&utm_campaign=epd-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=MSP430FR5969&ds_k=%7b_dssearchterm%7d&DCM=yes&gclid=CjwKCAjw3oqoBhAjEiwA_UaLtj0zWJxyBJCrLkihQoXO8O6QFz54VD2A-_e_Rqq8SBqXRJOLkkrMNRoC8pIQAvD_BwE&gclsrc=aw.ds) designed by Texas Instruments. General data sheets, reference manuals, and software/hardware examples are included in the GGH Google Drive under MSP430FR5969. Once you have obtained access to the J-Lab Google Drive, you can navigate to this info [here](https://drive.google.com/drive/folders/1jpBABjsWT8H2YCBZDEAygGu2eUNpcp-V?usp=sharing).

#### Current Wiring Diagram








[here](https://github.com/jlab-sensing/GreenerGreenHouses/tree/main/MSP430)

### CC1125 Boosterpack

#### Overview
The RF transciever that we are using is the [BOOSTXL CC1125 RF Boosterpack](https://www.ti.com/lit/an/swra520/swra520.pdf?ts=1694669569713) by Texas Instruments. Like the MSP430FR5969, general datasheets can be found in the datasheets folder of the GGH Google Drive. Software examples can be found in the MSP430/Final_SPI_Attempt directory of the GGH repository, specifically SmartRF1125.h for pin configurations, FR5969_CC1125.c/.h for interfacing functions with the MSP430, and SPI_LoRa_TestHarness.c for general tests on RX, TX modes.  
