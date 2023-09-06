### MSP430FR5969 communication via SPI to BOOSTXCL CC1125 LoRa module
This repository includes work and several libraries for general communication between the [MSP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en) and the [BOOSTXCL CC1125 LoRa module](https://www.ti.com/tool/BOOSTXL-CC1125) using SPI for general register communication and UART for transferring data through serial.

### Requirements/Installation
This project was written in Texas Instruments Code Composer Studio (CCS) v12.4.0 for the MSP430FR5969, code functionality is not guaranteed on different &mu;C models or IDE versions.
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