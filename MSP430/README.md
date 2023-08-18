# MSP430FR5969 Communication w/ HDC2021 RH/T Sensor via I2C protocol.
This repository includes a library for general communication with the [MSP430FR5969](https://www.ti.com/tool/MSP-EXP430FR5969?DCMP=mcugen&HQS=ep-mcu-msp-mcugen-mspblog-pf1-en) via I2C as well as a library for specified communication between the MSP and [HDC2021](https://www.ti.com/product/HDC2021?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-wwe&utm_content=HDC2021&ds_k=HDC2021&DCM=yes&gclid=CjwKCAjwivemBhBhEiwAJxNWNy875bwFKBnv9r-xLXOkZse5OFJSX0_3rTlIcTxieNfiUW1rvup9-BoC60QQAvD_BwE&gclsrc=aw.ds) RH/T sensor.

### Requirements/Installation
This project was written in Texas Instruments Code Composer Studio (CCS) v12.4.0 for the MSP430FR5969, code functionality is not guaranteed on different &mu;C models or IDE versions.
* Download [CCS v12.4.0](https://www.ti.com/tool/CCSTUDIO?utm_source=google&utm_medium=cpc&utm_campaign=epd-der-null-58700007779115352_code_composer_rsa-cpc-evm-google-wwe_int&utm_content=code_composer&ds_k=code+composer&gclid=CjwKCAjwivemBhBhEiwAJxNWNwJCSwoVVroAFzP406678cN4WomQixjpsSxBFZ7YZQcAh7ai1R1CjhoCafcQAvD_BwE&gclsrc=aw.ds) from Texas Instruments.
* Clone the GreenerGreenHouses repository
* Open CCS and select workspace of choice
* In CCS, navigate to [Files >> import >> Code Composer Studio >> CCS Projects >> Select Search Directory] and then select HDC2021_via_MSP430_I2C as the project to open.
* Build the project in order to create the .out file read by the MSP
* Once this project is open in your workspace, navigate to the flash drop down and select "Build Project Before Load", there should be a check next to it.
 * ![Flash_img](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/618b6e23-2cca-4c37-9800-3bd23bd92026)   ![image](https://github.com/jlab-sensing/GreenerGreenHouses/assets/133836006/a92e0620-07b4-4248-8598-80bdc0526fe4)

* Navigate back to the flash drop down and press "Select Program to Load". From there navigate to [Browse Project >> HDC2021_via_MSP430_I2C >> Debug >> HDC2021_via_MSP430_I2C.out]
* If this is unavailable, make sure the project has been built first




## Examples

### I2C Library: Read HDC2021 Manufacturer ID
This code demonstrates the usage of the MSP430_I2C library to read the HDC2021's manufacturer ID. This format of reading can be applied to an arbitrary device that communicates over the I2C protocol. For more information on function parameters, see [MSP430_I2C.h](HDC2021_via_MSP430_I2C/MSP430_I2C.h).
```c
//required libraries for example to work
#include <msp430.h>
#include "MSP430_I2C.h"
#include <stdint.h>

//required to link to the Rx buffer I2C library
extern uint8_t ReceiveBuffer[MAX_BUFFER_SIZE];
uint16_t ManufacturerID = 0; //global to view value in debug memory

int main(void){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
    initI2C(0x40); //initI2C(Peripheral_Address) *HDC2021 address is 0x40

    uint8_t data[STD_MSG_LENGTH] = {0}; //array to store data from RxBuffer

    //Read top 8 bits of manufacturer ID and store
    I2C_Controller_ReadReg(0x40, 0xFD, STD_MSG_LENGTH);
    CopyArray(ReceiveBuffer, data, STD_MSG_LENGTH);

    ManufacturerID = data[0];

    //read bottom 8 bits of manufacturer ID
    I2C_Controller_ReadReg(0x40, 0xFC, STD_MSG_LENGTH);
    CopyArray(ReceiveBuffer, data, STD_MSG_LENGTH);

    //bit masking to store manufacturer ID correctly
    ManufacturerID = (ManufacturerID << 8) | data[0];

 return 0;
}
```
### RH/T Library: Poll HDC2021 Temperature and Relative Humidity
This example is demonstrates usage of the HDC2021 library in conjunction with the MSP430_I2C library. General initialization sequence for the 
HDC2021 is as follows:
 * Sensor_Reset(void)
 * Sensor_SetMeasurementMode(MODE);
 * Sensor_SetMeasurementRate(RATE);
 * Sensor_SetTemperatureResolution(RESOLUTION);
 * Sensor_SetHumidityResolution(RESOLUTION);
 * Sensor_TriggerMeasurements(void);
 * Begin logging readings! ***First reading must be thrown out as HDC2021 stabilizes***

For details on available modes, rates, and resolutions see [HDC2021.h](HDC2021_via_MSP430_I2C/HDC2021.h).
```c
//required libraries for example to work
#include <msp430.h>
#include "MSP430_I2C.h"
#include <stdint.h>
#include "HDC2021.h"

//required to link to the Rx buffer in I2C library
extern uint8_t ReceiveBuffer[MAX_BUFFER_SIZE];

//global to view value in debug memory
//Sensor resolution allows floats, however is recommended against
float Temperature = 0.0;
float Humidity = 0.0;

int main(){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
    initI2C(HDC2021_ADDRESS);


    //HDC2021 Initialization
    Sensor_Reset();
    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
    Sensor_SetMeasurementRate(ONE_SECOND);
    Sensor_SetTempResolution(FOURTEEN_BIT);
    Sensor_SetHumidityResolution(FOURTEEN_BIT);
    Sensor_TriggerMeasurement();

    //first measurement needs to be thrown away as HDC2021 stabilizes
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();

    //first valid measurements stored
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();

 return 0;
}
```

## To Do:
- [ ] Add functions for setting Temperature/Humidity Offset
- [ ] Create standardized test-harness to verify sensor functionality
- [ ] Continue to manage README as code-base progresses
- [ ] Enable data-logging through uart->terminal
- [ ] Create library for communication with TI [LoRa boosterpack](https://www.ti.com/tool/BOOSTXL-CC1125#supported-products)
- [ ] Optimize current code-base for low-power performance
    - [ ] Remove float operations
    - [ ] enable and pull un-used GPIO pins to ground
      

    


   
