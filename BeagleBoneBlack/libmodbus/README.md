# libmodbus

This directory contains test files for using the libmodbus library and the FTDI USB-RS485-WE-1800-BT cable with the BeagleBone Black. These files are compatible with BeagleBone Black rev C (AM3358 processor).

## Files
- deprecated\ -- Folder containing older test code
- deprecated\modbus_echo_test -- Executable.
- deprecated\modbus_echo_test.c -- Test file for writing char 'a' to the FTDI cable.
- deprecated\modbus_tty -- Executable.
- deprecated\modbus_tty.c -- https://stackoverflow.com/a/38318768
- libmodbus_hello -- Executable.
- libmodbus_hello.c -- C source file which uses the libmodbus library to mimic either a modbus master or slave device. Depending on whether `#define MODBUS_SLAVE` is active, the program will either (if master) sequentially write 0xABCD to holding register addresses starting from 0 onwards or (if slave) receive replies and process them according to libmodbus. Slave mode maps memory for 0x00 to 0x1F for all four data types.
- README.md -- This file.
## Wiring Diagram
![test](https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png)**TEMPORARY IMAGE**

## Instructions
You must have libmodbus installed on the BeagleBone Black to run libmodbus_hello. You can obtain libmodbus with one of the following methods:
1. `sudo apt-get install libmodbus5`
2. `sudo apt-get install libmodbus-dev`
3. Build from source: https://github.com/stephane/libmodbus
You may need to either restart the BeagleBone Black, refresh/reload libraries with `ldconfig`, or modify the path if the library is not on the path and fails to include.

Use command `lsusb` to list usb devices to check if the FTDI cable is connected.
Use command `dmesg` to figure out which `\dev\ttyUSBx` (where x is 0-9) the FTDI cable is accessible through. Modify `RTU_PORT` accordingly.

Program compilation is done with the following command (when in the repository):
```
gcc libmodbus_hello.c -o libmodbus_hello -lmodbus
```
You may need to `chmod +x libmodbus_hello` if the compiled binary is not executable.
```
sudo ./libmodbus_hello
```
