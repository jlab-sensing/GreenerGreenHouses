# PRU

This directory contains subdirectories test programs for using the BBB's programmable realtime units (PRU).

Based on the examples provided in https://www.glennklockwood.com/embedded/beaglebone-pru.html

## Folders
- blink.c -- source file that toggles P9_31 every 5 ns. Comment out the `TEST_TOGGLE` define to revert to 0.5 s toggling.
- blink.o -- object file for `blink.c`.
- am335x-pru0-fw-blink-p9_31 -- built firmware for the PRU that runs the program described in `blink.c`.
- makefile -- makefile that calls the toolchain for PRU development.
- readme.md -- this file.

## Instructions
You can build from source or use the prebuilt firmware.

1. `make` to build the `blink` program.
2. `cat /sys/class/remoteproc/remoteproc1/state` to check the state of the PRU.
3. `echo stop > /sys/class/remoteproc/remoteproc1/state` to halt the PRU.
4. `sudo cp am335x-pru0-fw /lib/firmware/am335x-pru0-fw` to move the firmware to the directory that the firmware loader checks.
    - To prevent overwriting preexisting firmware, I recommend renaming the firmware to something other than the generic `am335x-pru0-fw`.
5. `cat /sys/class/remoteproc/remoteproc1/firmware` to check what firmware will be run when you turn on the PRU.
6. `echo am335x-pru0-fw > /sys/class/remoteproc/remoteproc1/firmware` to tell the PRU to load the specificed firmware.
7. `echo start > /sys/class/remoteproc/remoteproc1/state` to start the PRU.
    - Note: You must `config-pin` the pins the PRU accesses as `pruout` or `pruin`.
8. `echo stop > /sys/class/remoteproc/remoteproc1/state` to halt the PRU.

One line:
```
make && mv am335x-pru0-fw am335x-pru0-fw-blink-mc-1us-p9_31 && sudo cp am335x-pru0-fw-blink-mc-1us-p9_31 /lib/firmware/ && echo stop > /sys/class/remoteproc/remoteproc1/state && e
cho start > /sys/class/remoteproc/remoteproc1/state
```