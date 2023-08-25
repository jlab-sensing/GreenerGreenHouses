# SPI_test

This directory contains test files and configuration scripts for the BeagleBone Black. These files are compatible with BeagleBone Black rev C (AM3358 processor).

## Files
- deprecated\ -- Contains old test files.
- config-pin-i2c2-off.sh -- Turns off I2C on SCL:P9.19 and SDA:P9.20. Can be executed with user permissions.
- config-pin-i2c2-on.sh -- Turns on I2C on SCL:P9.19 and SDA:P9.20. Can be executed with user permissions.
- config-pin-spi0-off.sh -- Turns off SPI on CS0:P9.17, MOSI:P9.18, MISO:P9.21, and SCLK:P9.22. Can be executed with user permissions.
- config-pin-spi0-on.sh -- Turns on SPI on CS0:P9.17, MOSI:P9.18, MISO:P9.21, and SCLK:P9.22. Can be executed with user permissions.
- SPI.c -- C source file for the SPI library.
- SPI.h -- C header file for the SPI library.
- SPI_BME280_test -- Executable file that reads the BME280 temperature/humidity/pressure sensor's device ID and resets the device. Execute as sudo.
- SPI_BME280_test.c -- C source file for the executable described above. Can be modified to work with other devices by changing the hardcoded register values in txBuffer.
- SPI_LoRa_test.c -- [WIP] C source file for interacting with the BOOSTXL-CC1125 LoRa BoosterPack from TI.
- SPILIB_test -- Executable file that outputs (MOSI) bytes 0x00 to 0xFF every few seconds and prints out the received data (MISO). Can be tested by wiring MOSI to MISO and examining that the hardware-loopbacked data is 1-255. Execute as sudo.
- SPILIB_test.c -- C source file for the executable described above.
- README.md -- This file.

## Instructions
Compilation is done with the following command:
```
gcc <source files> SPI.c SPI.h -o <exectuable name>
```
Executables that access the SPI pins should be executed as sudo.
```
sudo <exectuable name>
```

