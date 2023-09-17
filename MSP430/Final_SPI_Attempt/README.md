### MSP430FR5969 communication via SPI to BOOSTXCL CC1125 LoRa module
This repository includes work and several libraries for general communication between the [MSP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en) and the [BOOSTXCL CC1125 LoRa module](https://www.ti.com/tool/BOOSTXL-CC1125) using SPI for general register communication and UART for transferring data through serial.

Two main files are included in this project. "main_tester.c" is the current work in progress main file which polls the temperature and humidity sensor for raw data, creates a 4 byte packet including the pre-configured device ID, temperature, and humidity data, and pulses it into the FIFO buffer of the CC1125 module for RF transmission.

### Requirements/Installation
This project was written in Texas Instruments Code Composer Studio (CCS) v12.4.0 for the MSP430FR5969 and BOOSTXL CC1125 RF Booster Pack, code functionality is not guaranteed on different &mu;C models, IDE versions, or RF transceivers.
* Download [CCS v12.4.0](https://www.ti.com/tool/CCSTUDIO?utm_source=google&utm_medium=cpc&utm_campaign=epd-der-null-58700007779115352_code_composer_rsa-cpc-evm-google-wwe_int&utm_content=code_composer&ds_k=code+composer&gclid=CjwKCAjwivemBhBhEiwAJxNWNwJCSwoVVroAFzP406678cN4WomQixjpsSxBFZ7YZQcAh7ai1R1CjhoCafcQAvD_BwE&gclsrc=aw.ds) from Texas Instruments.
* Clone the GreenerGreenHouses repository
* Open CCS and select workspace of choice
* In CCS, navigate to [Files >> import >> Code Composer Studio >> CCS Projects >> Select Search Directory >> browse] and then select Final_SPI_Attempt as the project to open.
* If you would like to create a copy of the project local to your workspace, select "Copy Projects into Workspace".![image](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/60e64945-25ef-4348-aa8d-2cf1145aeb02)
* As this is a standalone project, leave "Automatically import referenced projects found in same search-directory" unchecked.
* Once this project is open in your workspace, navigate to the flash drop down and select "Build Project Before Load", there should be a check next to it.
 * ![Flash_img](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/618b6e23-2cca-4c37-9800-3bd23bd92026)   ![image](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/a92e0620-07b4-4248-8598-80bdc0526fe4)

* Navigate back to the flash drop down and press "Select Program to Load". From there navigate to [Browse Project >> Final_SPI_Attempt >> Debug >> Final_SPI_Attempt.out]
* If this is unavailable, make sure the project has been built first

### Testing for functionality
Without the proper receiving hardware, it is impossible to test or use this code base. The project was built around the CC 1125 RF module by Texas Instruments, compatibility with other RF transceivers is not guaranteed. In the grander scope of the project, RF packets transmitted from the MSP430 are picked up by an accompanying RF receiver hosted by a BeagleBoneBlack. Firmware for the BBB, receiver, and packet deconstructor can be found in the BeagleBoneBlack directory. However it is possible to simply test for correct packet transmission, and you can use a program such as TI's RF studio, which has pre-configured settings that do not require any code. 
* Create a TI account and download [RF Studio](https://www.ti.com/tool/SMARTRFTM-STUDIO#downloads)
* Open RF Studio, plug in RF Module into any available USB port, and select device
* Change mode to RX Packets, go to advanced settings, and change packet length to 4 bytes
* Remove packet number setting, and configure CRC setting
* Connect the MSP430 to the CC1125 RF Module:
    * 5V -> 5V
    * Gnd -> Gnd
    * P2.6 MISO -> 14 MISO
    * P2.5 MOSI -> 12 MOSI
    * P2.4 SCLK -> 13 SCK
    * P1.6 CS -> 3 CS_N
* In main.c, above main(), change to TX_Test, in SmartRF1125.h, change PACKET_LEN to 6, build and flash to MSP430
* If RF studio is currently receiving, then 10 packets will appear, each saying "Test" with the packet number after
* If incoming data displays "CRC Error" at the end, then there is an issue with your settings in RF Studio, or the packet length does not match.

A similar method can be used to run main.c, which collects sensor data, packages it, and ships it via RF, using RF studio. Simply change the packet length to 4 in both SmartRF1125.h and in RF Studio, to view incoming packets. To instead receive packets using the BBB CC1125 combo, please refer to the designated receiver/unpacker firmware in the BeagleBoneBlack directory. Below is the complete wiring diagram on how to connect the HDC2021 sensing board and CC1125 Module to the MSP430.

### MSP430 Wiring Diagram
![image](https://github.com/jlab-sensing/GreenerGreenHouses/blob/main/MSP430/Final_SPI_Attempt/images/MSP430%20Wiring%20Diagram.png)

The wiring between the MSP430FR5969, CC1125 Boosterpack, and HDC2021 sensor board is pretty simple. Above is the wiring diagram for the system.

### Sensor Data Packet Structure
The system design uses a custom packet structure to transmit sensor data from the HDC2021 to the BeagleBone Black. The packet is 4 bytes long, and is composed of a 4bit device ID, 14 bit temperature data, and 14 bit humidity data. The device ID is used as an identification piece for the BBB, so that the source (which MSP430) is determined and recorded. Bit masking is used in this case to minimize packet size, thuse minimizing transmission time, reducing bit errors and lowering overall power consumption.

### Future Work
As of now (September 15, 2023), the project is at a stable state, where data is collected from the sensor once a second by the MSP430, packaged and sent over the the BBB via LoRa. Additional updates that are possible include a packet-parser on the MSP side, for the potential messages sent by the BBB to change HDC2021 settings, LoRa register configurations, etc. A 5V fan is also planned to be integrated with the sensor board, to maximize airflow around it to achieve the most accurate results. This requires a stable 5V supply, which the MSP430 can theoretically supply, however calculations should be done to verify that the fan will not affect other peripherals from current draw.
