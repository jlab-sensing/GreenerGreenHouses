# BoosterPack_swrc253e

This directory contains test files for interfacing the BOOSTXL-CC1125 with the BeagleBone Black. These files are compatible with BeagleBone Black rev C (AM3358 processor).

## Files
- unused\ -- Contains files that are not used.
- SPI.c -- C source file for the SPI library. Bottom-layer SPI system calls.
- SPI.h -- C header file for the SPI library. Bottom-layer SPI system calls.
- cc112x_easy_link_reg_config.h -- Contains CC1125 register values as provided in the TI SWRC253E code examples.
- cc112x_spi.c -- Top-layer CC1125 SPI access library implementation file as provided in the TI SWRC253E code examples.
- cc112x_spi.h -- Top-layer CC1125 SPI access library header file as provided in the TI SWRC253E code examples.
- hal_defs.h -- Contains defined constants and macros as provided in the TI SWRC253E code examples.
- hal_spi_rf_trxeb.c -- Implementation file for register access and command strobes to the CC1125. Modified from TI SWRC253E code examples. Mid-level SPI access.
- hal_spi_rf_trxeb.h -- Header file for register access and command strobes to the CC1125. Modified from TI SWRC253E code examples. Mid-level SPI access.
- hal_types.h -- Contains typedefs for integer types and compiler abstractions as provided in the TI SWRC253E code examples.
- main.c -- Main execution loop which contains the register read/write/read test. Resets CC1125, reads default registers, writes to them based on the contents of cc112x_easy_link_reg_config.h, and reads the registers again to verify successful write. Loops with reading through all registers (including extended addresses) from 0x00 to 0x2F and 0x2F00 to 0x2FD9.
- out -- Compiled binary for the AM3358 processor (BeagleBone Black revision C).
- README.md -- This file.

## Instructions
Compilation is done with the following command (when in the repository):
```
gcc *.c *.h -o out
```
Executables that access the SPI pins should be executed as sudo. You may need to `chmod +x out` if the compiled binary is not executable. `config-pin` scripts must be executed prior to SPI pin access.
```
sudo ./out
```
