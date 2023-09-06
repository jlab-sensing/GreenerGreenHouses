# MSP430FR5969 Various CCS Projects
This directory includes several CCS projects and files for various driver development and testing ambitions. The projects are specific for the [MSP430FR5969](https://ww/ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en). The current projects included in the MSP430 directory include:

* Booster_Pack_LoRa_SPI: CCS project entailing development of communcation and transmition using the [TI BOOSTXL-CC1125 LoRa BoosterPack](https://www.ti.com/tool/BOOSTXL-CC1125). DEFUNCT DUE TO FAILED ATTEMPT AND ISSUES.
* HDC2021_via_MSP430_I2C: CCS project containing custom I2C communication library for MSP430FR5969. Also includes custom driver library for [HDC2021](https://www.ti.com/product/HDC2021?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=HDC2021&ds_k=HDC2021&DCM=yes&gclid=CjwKCAjwivemBhBhEiwAJxNWNy875bwFKBnv9r-xLXOkZse5OFJSX0_3rTlIcTxieNfiUW1rvup9-BoC60QQAvD_BwE&gclsrc=aw.ds) temperature and humidity sensor, meant to work with the above board.
* UART_example: CCS project containing work on the creation of a custom UART communication driver for the MSP430FR5969. Now defunct due to discovery of proprietary TI UART library in driverlib folder.
* driverlib/MSP430FR5xx_6xx: Proprietary TI driver library directory. Contains drivers for UART, I2C, SPI, among other communication protocols and peripherals for the MSP430FR5969 board. UART and SPI drivers in Booster_Pack_LoRa_SPI were derived from the files in this directory.
* Final_SPI_Attempt: CCS project that contains code for communication with the [TI BOOSTXL-CC1125 LoRa BoosterPack](https://www.ti.com/tool/BOOSTXL-CC1125) and the MSP430FR5969. Includes custom libraries for specific register configurations for TX, RX, and Continuous Packet identification modes. WORKING VERSION.

### Requirements/Installation
Each directory, except driverlib, were written in Texas Instruments Code Composer Studio (CCS) v12.4.0 for the MSP430FR5969, and code functionality is not guaranteed on different &mu;C models or IDE versions. Please make your way to the README of a specific project for more information on how to install and run the application.



:warning:README UNDER-CONSTRUCTION. OLD README MOVED TO HDC2021_via_MSP430_I2C DIRECTORY :warning:
