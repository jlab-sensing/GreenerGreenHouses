# BeagleBoneBlack

This directory contains subdirectories for scripts and programs for the BeagleBone Black (BBB) revision C with the AM3358 processor.

## Folders
- BoosterPack_swrc253e\ -- (Deprecated) Program for interfacing the BBB with the CC1125. For a more up-to-date program, see `rxlogger\` which also includes Modbus integration.
- LaunchPad_trx_demo_swra493\ -- (Abandoned) Non-working compatibility conversion of the Texas Instruments SWRA493 test code for use with the CC1125.
- SPI_test\ -- (Deprecated) Various small test programs for exploring SPI on the BBB.
- config-pin\ -- Scripts for toggling I2C and SPI. Execute the script(s) before running programs that access the BBB's I2C and SPI peripherals.
- libmodbus\ -- (Deprecated) Test program for exploring libmodbus on the BBB.
- rxlogger\ -- Program for the "Sensor Manager" in the traditional IoT system. Receives periodic data packets from the IoT tag (MSP430), saves the data to a CSV, and also updates the BBB's modbus registers in order to provide the greenhouse control system (Argus) with the latest temperature and relative humidity readings.

# BeagleBone Black Setup
The following instructions should be done on the BeagleBone Black (abbreviated as BBB), and assume that you are executing commands on the BBB through SSH.

## Files
- files

## First-Time BBB
1. Plug in the USB cable between your computer and the BBB. You should plug in the mini USB to the bottom side of the BBB near the ethernet port.
	a. If you want to use the WiFi dongle, you should connect the barrel plug (5 V, >= 1 A) to the BBB in order to supply enough current. USB power (
2. SSH in with one of the following (both are equivalent):
	a. `ssh debian@beaglebone.local`
	b. `ssh debian@192.168.7.2`
3. The default password for the `debian` user is `temppwd`
4. 


## Code
git clone


## SPI and I2C
Run scripts in the confg-pin folder from the git repo.
Alternatively, invoke the commands manually with the config-pin command.
```
config-pin p9.17 spi_cs
```


## Libmodbus
Needs RS485 cable
Plug and play, no separate driver installation needed
Use lsusb and dmesg to check which ttyUSBx should be used in RTU_PORT.


## WiFi
### Simple WPA2 Networks
1. Plug in the wifi dongle. Tested with Comfast CF-WU810N, 2.4 GHz only (802.11n) which has the (RTL8188EUS) R8188EU driver. This device does not require additional/separate driver installation.
	- You can check if the wifi dongle is connected with `lsusb`, and you can find out more with `dmesg`.
2. `connmanctl`
3. `technologies` to see the network interfaces available, which should include wifi.
	- `enable wifi` if not already enabled/powered.
4. `services` to display networks available.
	- `scan wifi` to force a new scan if you do not see the networks you expect. (Note: 2.4 GHz only with CF-WU810N.)
5. `agent on`
6. `connect wifi_<tab to complete>` to connect to the wifi network.
7. Follow the agent prompts (such as entering the network password) to finish configuration and connection.

### eduroam
The BBB ships with Debian and uses `connmanctl` to manage network connections. `connmanctl` appears to seize `wpa_supplicant`, so the method to connect to eduroam is slightly different from what you would do on a Raspberry Pi. Instead of setting up `/etc/wpa_supplicant/wpa_supplicant.conf`, you will instead set up a `connmanctl` manual configuration file (`/var/lib/connman/eduroam.config`).
1. Download the UCSC certificate authority file from the ITS website: https://its.ucsc.edu/wireless/docs/ca.crt
	- The certificate appears to already be in one of `connmanctl`'s [accepted CA file formats (PEM/DER)](https://manpages.debian.org/buster/connman/connman-service.config.5.en.html), so there is no need to convert the file.
2. Copy the certificate ("ca.crt") to `/usr/share/ca-certificates/local`. You can rename it to something memorable if you want.
3. `sudo dpkg-reconfigure ca-certificates` and use the spacebar to select the newly added certificate. Press Enter to confirm and apply the changes.
4. `sudo nano /var/lib/connman/eduroam.config` and enter the following:
	- Not sure, but the Passphrase may need to be enclosed in double quotes if it contains spaces.
	- You do not need to specify the `CACertFile` or `Domain` arguments, at least for UCSC's flavor of eduroam.
```
[service_eduroam]
Type=wifi
Name=eduroam
EAP=peap
Phase2=MSCHAPV2
Identity=<YOUR UCSC EMAIL ENDING IN @ucsc.edu HERE>
Passphrase=<YOUR GOLD PASSWORD HERE>
```
5. Follow the instructions in Simple WPA2 Networks and connect to eduroam.

TODO:
- https://cloud.securew2.com/public/40809/eduroam/
    - *.cer (non-specific OS)
    - Linux python script

## LF11 Control via Telnet
Telnet is used to control the LF11 Light Fixture. Note that the LF11 only provides illumination to the plants, and does not control the LBRB9 Light Bar for LiFi communication.

1. `sudo apt-get install telnet`
2. Connect the BBB to the ChiYu BF-430 converter with an ethernet/RJ45 cable.
3. Turn on the power switch on the XtremeLUX DC11 digital controller and plug in the power adapter for the ChiYu BF-430. You should observe the power indicator LEDs on the BF-430 and the DC11 turn on.
    - You do not need to plug in the power for the LEDs themselves if you only want to test the connectivity.
4. Use `ifconfig` and `ping 192.168.1.123` to verify if the BBB can see the digital controller.
    - The BBB must be on the same subnet as the DC11.
    - In the `connmanctl` shell, use `config ethernet_<tab> --ipv4 manual 192.168.1.115 255.255.0.0` to set the eth0 interface IP to the same subnet as the DC11. This may interfere with the wlan0 interface, possibly due to DNS gateway issues.
    - To revert, use `config ethernet_<tab> --ipv4 dhcp`. If this doesn't fix the wlan0 interface issue, then you can just unplug the ethernet cable to regain full function.
5. `telnet 192.168.1.123 50123` to connect to the DC11. (192.168.1.123:50123)
6. In the telnet shell, use the `?` command to view all possible commands and their descriptions.
7. To set the LED brightness, use the following commands:
    1. `mode m` to change to manual mode (default auto for use with the companion application).
    2. `lo [0-2000]` where the number is the brightness in tenths of a percent. (ex. 1000 corresponds to 100.0%, and 50 corresponds to 5.0%.)
    3. `ls all` to apply the light output to all light bars.

## LBRB9 LiFi/VLC Control
### Main Processor
To control the LBRB9 light bar for LiFi/VLC communication, you can control the digital pins and output a voltage between 0 and 5 V to the LBRB9's control pins. The control pins are red (for red) and white (for blue). Make sure that the BBB shares ground (black wire).

TODO:
- Configure pin as normal push-pull, or as open drain?
- What is the max current sink/source per digital pin?
- Consider 5 V level shifter

### Programmable Realtime Unit (PRU)

TODO:
- PRU hookup and modification of OpenVLC
- pinout and `config-pin` script for the digital pins
- Analog output? Ramifications and comparison of switching speed?
    - Where is the bottleneck? Likely the "frequency response" (switching speed) of the LEDs on the LBRB9 (~10 kHz).