# BeagleBoneBlack

This directory contains subdirectories for scripts and programs for the BeagleBone Black (BBB) revision C with the AM3358 processor.

All projects and guides assume that the BBB is on Debian Buster IoT Image 2020-04-06, with Linux 4.19.94-ti-r42 kernel. There are certain ramifications on the accuracy of the WiFi section of this guide if you [update to newer versions such as Debian 11 Bullseye or 12 Bookworm](https://www.beagleboard.org/distros), specifically that `connman` is no longer in use and is replaced by `systemd-networkd`, see the [Debian 11.x Bullseye Monthly Snapshot](https://forum.beagleboard.org/t/debian-11-x-bullseye-monthly-snapshot-2023-09-02/31280) for more information. If you decide to upgrade, you should use the IoT image, unless you need the desktop provided in the Xfce image.

## Folders
- BoosterPack_swrc253e\ -- (Deprecated) Program for interfacing the BBB with the CC1125. For a more up-to-date program, see `rxlogger\` which also includes Modbus integration.
- LaunchPad_trx_demo_swra493\ -- (Abandoned) Non-working compatibility conversion of the Texas Instruments SWRA493 test code for use with the CC1125.
- SPI_test\ -- (Deprecated) Various small test programs for exploring SPI on the BBB.
- config-pin\ -- Scripts for toggling I2C and SPI. Execute the script(s) before running programs that access the BBB's I2C and SPI peripherals.
- libmodbus\ -- (Deprecated) Test program for exploring libmodbus on the BBB.
- rxlogger\ -- Program for the "Sensor Manager" in the traditional IoT system. Receives periodic data packets from the IoT tag (MSP430), saves the data to a CSV, and also updates the BBB's modbus registers in order to provide the greenhouse control system (Argus) with the latest temperature and relative humidity readings.

# BeagleBone Black Setup
The following instructions should be done on the BeagleBone Black (abbreviated as BBB), and assume that you are executing commands on the BBB through SSH. It is easiest to connect through the onboard mini USB port.

## First-Time BBB
1. Plug in the USB cable between your computer and the BBB. You should plug in the mini USB to the bottom side of the BBB near the ethernet port.
	- If you want to use the WiFi dongle, you should connect the barrel plug (5 V, >= 1 A) to the BBB in order to supply enough current. USB 2.0 power (5V, 500 mA) may not be sufficient for both the BBB and wifi peripherals.
2. SSH in with one of the following:
	- `ssh debian@beaglebone.local`
	- `ssh debian@192.168.7.2` (Windows)
    - `ssh debian@192.168.6.2` (macOS & Linux)
        - [macOS 11.5 USB FIX](https://forum.beagleboard.org/t/beaglebone-black-on-macosx-12-1/31366/6): On the BBB run `cd /opt/scripts/`, `git pull`, then `sudo reboot`.
    - [Alternative addresses](https://docs.beagleboard.org/latest/intro/support/getting-started.html#browse-to-your-beagle)
    - Note: If you encounter hostkey verification issues due to ssh'ing into multiple BBBs, you can modify your `~/.ssh/config` file to disable strict host key checking. Append the following lines to the end of your `~/.ssh/config` file:
    ```
    Host 192.168.7.*
      UserKnownHostsFile /dev/null
      StrictHostKeyChecking no
    ```
    - You may want to change the `Host` value to `beaglebone.local` or to the address you use to access the BBB.
3. The default password for the `debian` user is `temppwd`
    - Use `passwd` to update the password if you intend to make the BBB network-accessible.
4. Connect an ethernet cable to the BBB for internet.
    - If ethernet is unavailable, see the WiFi section. You can set up a mobile hotspot from your computer or phone. Alternatively, you may be able to bridge a BBB-to-host ethernet with your host device's wifi.
5. `sudo apt-get update`
6. `sudo apt-get upgrade` (This may take a while, > 30 min.)

## Code
1. Copy the codebase with: `git clone https://github.com/jlab-sensing/GreenerGreenHouses.git` or `git clone git@github.com:jlab-sensing/GreenerGreenHouses.git`
2. In general, compile with: `gcc *.c *.h -o <executable_name>`
3. Then run with: `./<executable_name>`

## SPI and I2C
Run scripts in the `confg-pin\` folder from the git repo to configure the pins for SPI and I2C.
Alternatively, invoke the commands manually with the `config-pin` command. These commands and scripts do not need to be run with `sudo`. Pin configurations do not persist after power-off.

## libmodbus
The easiest way to use the modbus code is with a USB-RS485 cable such as FTDI's [USB-RS485-WE-1800-BT](https://ftdichip.com/products/usb-rs485-we-1800-bt/). The FTDI cable is plug and play, no separate driver installation needed.

In order to communicate with the Modbus protocol over the RS485 PHY layer, you must have libmodbus installed, ideally built from source from https://github.com/stephane/libmodbus.
1. In your `~/` directory: `git clone https://github.com/stephane/libmodbus`
2. `cd libmodbus`
3. `./autogen.sh && ./configure && sudo make install && sudo ldconfig` (This may take a while, < 15 min.)

To use the libmodbus library, you must add `#include <modbus/modbus.h>`. See the [libmodbus reference](https://libmodbus.org/reference/) or the source files in `~/libmodbus/src/` for details.

Use `lsusb` and `dmesg` to check which `/dev/ttyUSBx` should be provided to `modbus_new_rtu()`.

Note: The Debian prebuilt packages `libmodbus5` and `libmodbus-dev` did not work for me. Just build from source.

## WiFi

### Simple WPA2 Networks
1. Plug in the wifi dongle. Tested with Comfast CF-WU810N, 2.4 GHz only (802.11n) which has the (RTL8188EUS) R8188EU driver. This device does not require additional/separate driver installation.
	- You can check if the wifi dongle is connected with `lsusb`, and you can find out more with `dmesg`.
2. `connmanctl` (ignore the VPN error)
3. `technologies` to see the network interfaces available, which should include wifi.
	- `enable wifi` if not already enabled/powered.
4. `services` to display networks available.
	- `scan wifi` to force a new scan if you do not see the networks you expect. Use `services` again to show available networks. (Note: 2.4 GHz only with CF-WU810N. If you are using a mobile hotspot, make sure it is set to 2.4 GHz.)
5. `agent on` to enable the agent for configuring and connecting to networks.
6. `connect wifi_<tab to complete>` to connect to the wifi network. You must enter the 
7. Follow the agent prompts (such as entering the network password) to finish configuration and connection.
8. `exit`

### eduroam
The BBB ships with Debian and uses `connmanctl` to manage network connections. `connmanctl` appears to seize `wpa_supplicant`, so the method to connect to eduroam is slightly different from what you would do on a Raspberry Pi. Instead of setting up `/etc/wpa_supplicant/wpa_supplicant.conf`, you will instead set up a `connmanctl` manual configuration file (`/var/lib/connman/eduroam.config`).
1. Download the UCSC certificate authority file from the ITS website: https://its.ucsc.edu/wireless/docs/ca.crt
	- The certificate appears to already be in one of `connmanctl`'s [accepted CA file formats (PEM/DER)](https://manpages.debian.org/buster/connman/connman-service.config.5.en.html), so there is no need to convert the file.
2. Copy the certificate ("ca.crt") to `/usr/share/ca-certificates/local/`. You can rename it to something memorable if you want.
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

### (Recommended) Ethernet Blacklisted From Connman
The steps below describe how to connect to the LF11 (DC11) using manual configuration on the ethernet interface. This method has a downside of requiring additional setup and (untested:) may not work properly if you want to use the ethernet port for an internet connection. The upside is that this will not interfere with the wifi wlan0 internet connection.

Further investigation in `/etc/dhcp/dhclient.conf` could help resolve static/dhcp issues (i.e. preferred dhcp ip or fallback static ip after no dhcp server response).

Use this method if you need a simultaneous wifi connection. (Recommended for remote management.)

1. Add `eth0` to the NetworkInterfaceBlacklist for connman in `/etc/connman/main.conf`.
```
[General]
PreferredTechnologies=ethernet,wifi
SingleConnectedTechnology=false
AllowHostnameUpdates=false
PersistentTetheringMode=true
NetworkInterfaceBlacklist=SoftAp0,usb0,usb1,eth0
#eth0 on blacklist for manual routing only
```
2. Set up an alias for eth0 and configure it with a static ip within the 192.168.1.x subnet such as 192.168.1.1 in `/etc/network/interfaces`.
```
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

# The loopback network interface
auto lo
iface lo inet loopback

# eth0 configuration for simultaneous dhcp and static
# Note: eth0 must be on connman blacklist (/etc/connman/main.conf)

# Main eth0 interface remains dhcp to (hopefully) retain plug-and-play internet capabilities through eth0
auto eth0
allow-hotplug eth0
iface eth0 inet dhcp

# Alias 1 for eth0 is configured as static 192.168.1.1 for communication with LF11/DC11 located at static 192.168.1.123 (telnet 50123)
# Note: gateway, name, and alias are optional, see https://wiki.debian.org/NetworkConfiguration#Legacy_method
auto eth0:1
allow-hotplug eth0:1
iface eth0:1 inet static
	name Ethernet alias LAN card
	address 192.168.1.1/24
	netmask 255.255.255.0
	gateway 192.168.1.1
#	broadcast 192.168.1.255
#	network 192.168.1.0
```
3. Restart the BBB with `sudo reboot` or (untested:) just restart connman and the networking services with `sudo systemctl restart networking connman`.
4. `sudo apt-get install telnet`
5. Connect the BBB to the ChiYu BF-430 converter with an ethernet/RJ45 cable.
6. Turn on the power switch on the XtremeLUX DC11 digital controller and plug in the power adapter for the ChiYu BF-430. You should observe the power indicator LEDs on the BF-430 and the DC11 turn on.
    - You do not need to plug in the power for the LEDs themselves if you only want to test the connectivity.
    - The DC11 is powered by the BF-430 over RS485, so you can ignore the barrel jack on the side of the DC11.
7. Use `ifconfig` and `ping 192.168.1.123` to check if the BBB's eth0 ipv4 address is on the same subnet as the BF-430 and if it can reach it.
    - The BBB must be on the same subnet as the BF-430.
8. `telnet 192.168.1.123 50123` to connect to the DC11. (192.168.1.123:50123)
9. In the telnet shell, use the `?` command to view all possible commands and their descriptions.
10. To set the LED brightness, use the following commands:
    1. `mode m` to change to manual mode (the default is auto for use with the companion application).
    2. `lo [0-2000]` where the number is the brightness in tenths of a percent. (ex. 1000 corresponds to 100.0%, and 50 corresponds to 5.0%.)
    3. `ls all` to apply the light output to all light bars.

When configured properly, your `route` table should look like this:
```
debian@beaglebone:~$ route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
default         comm-vss-g-v480 0.0.0.0         UG    0      0        0 wlan0
ns2.ucsc.edu    comm-vss-g-v480 255.255.255.255 UGH   0      0        0 wlan0
ns1.ucsc.edu    comm-vss-g-v480 255.255.255.255 UGH   0      0        0 wlan0
169.233.128.0   0.0.0.0         255.255.128.0   U     0      0        0 wlan0
comm-vss-g-v480 0.0.0.0         255.255.255.255 UH    0      0        0 wlan0
192.168.1.0     0.0.0.0         255.255.255.0   U     0      0        0 eth0
192.168.6.0     0.0.0.0         255.255.255.0   U     0      0        0 usb1
192.168.7.0     0.0.0.0         255.255.255.0   U     0      0        0 usb0
```

### Ethernet Managed By Connman
The steps below describe how to connect to the LF11 (DC11) using Debian 10's default Connection Manager. This method has a downside of regularly modifying the routing table (`route`) and disrupting the wifi wlan0 internet connection. However, this method maintains the out-of-the-box behavior of the ethernet port in case you want to use the ethernet port for an internet connection or DHCP.

Use this method if you do not care about having a wifi connection.

1. `sudo apt-get install telnet`
2. Connect the BBB to the ChiYu BF-430 converter with an ethernet/RJ45 cable.
3. Turn on the power switch on the XtremeLUX DC11 digital controller and plug in the power adapter for the ChiYu BF-430. You should observe the power indicator LEDs on the BF-430 and the DC11 turn on.
    - You do not need to plug in the power for the LEDs themselves if you only want to test the connectivity.
    - The DC11 is powered by the BF-430 over RS485, so you can ignore the barrel jack on the side of the DC11.
4. Use `ifconfig` and `ping 192.168.1.123` to check if the BBB's eth0 ipv4 address is on the same subnet as the BF-430 and if it can reach it.
    - The BBB must be on the same subnet as the BF-430.
    - In the `connmanctl` shell, use `config ethernet_<tab> --ipv4 manual 192.168.1.115 255.255.0.0` to set the eth0 interface IP to the same subnet as the BF-430. This may interfere with the wlan0 interface due to overwriting the default gateway. Normally, you want all non-local requests to be routed through wlan0 (which is your internet connection) through `comm-vss-g-v480` (`169.233.255.254`), but the connman daemon will repeatedly overwrite the default gateway with the eth0 interface through `0.0.0.0`.
    - To revert, use `config ethernet_<tab> --ipv4 dhcp`. If this doesn't fix the wlan0 interface issue, then you can just unplug the ethernet cable to regain full function. Doing that will flush the `route` table of any routes associated with the (now disconnected) eth0 interface.
    - Alternatively, you can use the command `sudo route add default gw comm-vss-g-v480 dev wlan0` to manually route non-local connections through the wlan0 interface. Similarly, you can manually route 192.168.1.123 through eth0 using `sudo route add 192.168.1.123 gw 0.0.0.0 dev eth0`. However, this will not stop the connman daemon from modifying the default gateway.
5. `telnet 192.168.1.123 50123` to connect to the DC11. (192.168.1.123:50123)
6. In the telnet shell, use the `?` command to view all possible commands and their descriptions.
7. To set the LED brightness, use the following commands:
    1. `mode m` to change to manual mode (the default is auto for use with the companion application).
    2. `lo [0-2000]` where the number is the brightness in tenths of a percent. (ex. 1000 corresponds to 100.0%, and 50 corresponds to 5.0%.)
    3. `ls all` to apply the light output to all light bars.

### Managing the BF-430
If you want to change the IP and port settings for the BF-430, you can access its web (HTTP port 80) configuration portal.

1. Plug an ethernet cable between the BF-430 and a device with a desktop GUI and a web browser (such as a laptop or a BBB with the desktop GUI image loaded).
2. Navigate to `192.168.1.123` in the web browser address bar. You may need to specify http with `http://192.168.1.123`. The login credential is `admin` and `nodeoN12`.
    - If you do not know the URL, use the `arp` command to check for the IPs of local devices.
3. Configure the BF-430 according to the configuration portal. Most options relating to the IP and port settings are under the one-page setup tab. After modifying the settings, be sure to click the apply button.

Alternatively, you can manage the BF-430 through the command line (telnet port 23).

1. `telnet 192.168.1.123` and login with the credentials `admin` and `nodeoN12`.
2. Configure the BF-430 according to the command line. Use the `help` command to view options, and `help <command>` to view usage instructions.
3. You must us `NVsave` to apply your changes to non-volatile memory and have your options persist through power-down.

## LBRB9 LiFi/VLC Control

### Main Processor
To control the LBRB9 light bar for LiFi/VLC communication, you can control the digital pins and output a voltage between 0 and 5 V to the LBRB9's control pins. The control pins are red (for red) and white (for blue). Make sure that the BBB shares ground (black wire).

TODO:
- Configure pin as normal push-pull, or as open drain?
- What is the max current sink/source per digital pin?
- Consider 5 V level shifter

### Programmable Realtime Unit (PRU)
The two Programmable Realtime Units (PRU) on the BBB act as coprocessors, and can execute programs independently of the main CPU (while still on the 200 MHz clock). This is great for devoting low-latency pin access, since you can have one of the PRUs execute a single program and not have to worry about having CPU time be divided. With a 200 MHz clock, this means that you can get as low as 5 ns pin access times.

This section covers how to program the PRU.

Based on the guide written by Glenn K. Lockwood: https://www.glennklockwood.com/embedded/beaglebone-pru.html

1. PRU code must include a resource table. Use the code below, or copy and include `/usr/lib/ti/pru-software-support-package/examples/am335x/PRU_gpioToggle/resource_table_empty.h` which is the equivalent.
    - Resource tables are for configuring buffers and interrupts.
    - You can include additional PRU-specific libraries which are located in `/usr/lib/ti/pru-software-support-package/include/`. This path is in the makefile build path.
```
#include <rsc_types.h>

...

/* required by PRU */
#pragma DATA_SECTION(pru_remoteproc_ResourceTable, ".resource_table")
#pragma RETAIN(pru_remoteproc_ResourceTable)
struct my_resource_table {
    struct resource_table base;
    uint32_t offset[1];
} pru_remoteproc_ResourceTable = { 1, 0, 0, 0, 0 };
```
2. Perform bit operations on `volatile register uint32_t __R30;` to cause P9 pins gpio to change.
    - You must `config-pin` for `pruout` or `pruin` before executing.
3. Compile and link with `clpru` and `lnkpru`. The makefile below will do it for you if you simply call `make`.
```
PRU_SWPKG = /usr/lib/ti/pru-software-support-package

CC = clpru
LD = lnkpru
CFLAGS = --include_path=$(PRU_SWPKG)/include \
         --include_path=$(PRU_SWPKG)/include/am335x
LDFLAGS = $(PRU_SWPKG)/labs/lab_2/AM335x_PRU.cmd

all: am335x-pru0-fw

hello-pru0.o: hello-pru0.c
    $(CC) $(CFLAGS) $^ --output_file $@

am335x-pru0-fw: hello-pru0.o
    $(LD) $(LDFLAGS) $^ -o $@
```
4. `echo stop > /sys/class/remoteproc/remoteproc1/state` to halt the PRU. `remoteproc1` is for PRU0, `remoteproc2` is for PRU1.
    - You can check the state by reading the `state` file: `cat /sys/class/remoteproc/remoteproc1/state`.
5. Move the firmware to the `/lib/firmware/` folder. (ex. `cp am335x-pru0-fw /lib/firmware/am335x-pru0-fw`)
6. Set the `firmware` file to be the same name as the firmware you've moved into the `/lib/firmware/` folder. This tells the PRU to load the firmware with that name.
    - `cat /sys/class/remoteproc/remoteproc1/firmware` to check which firmware it will load.
    - `echo myFirmwareName > /sys/class/remoteproc/remoteproc1/firmware` to set the firmware to load.
7. `echo start > /sys/class/remoteproc/remoteproc1/state` to start the PRU.
    - `cat /sys/class/remoteproc/remoteproc1/state` to observe if the PRU is `running` or `offline`.

TODO:
- PRU hookup and modification of OpenVLC
- pinout and `config-pin` script for the digital pins
- Analog output? Ramifications and comparison of switching speed?
    - Where is the bottleneck? Likely the "frequency response" (switching speed) of the LEDs on the LBRB9 (~10 kHz).