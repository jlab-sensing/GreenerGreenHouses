# BeagleBoneBlack

This directory contains subdirectories for scripts and programs for the BeagleBone Black (BBB) revision C with the AM3358 processor.

## Folders
- BoosterPack_swrc253e\ -- (Deprecated) Program for interfacing the BBB with the CC1125. For a more up-to-date program, see `rxlogger\` which also includes Modbus integration.
- LaunchPad_trx_demo_swra493\ -- (Abandoned) Non-working compatibility conversion of the Texas Instruments SWRA493 test code for use with the CC1125.
- SPI_test\ -- (Deprecated) Various small test programs for exploring SPI on the BBB.
- config-pin\ -- Scripts for toggling I2C and SPI. Execute the script(s) before running programs that access the BBB's I2C and SPI peripherals.
- libmodbus\ -- (Deprecated) Test program for exploring libmodbus on the BBB.
- rxlogger\ -- Program for the "Sensor Manager" in the traditional IoT system. Receives periodic data packets from the IoT tag (MSP430), saves the data to a CSV, and also updates the BBB's modbus registers in order to provide the greenhouse control system (Argus) with the latest temperature and relative humidity readings.