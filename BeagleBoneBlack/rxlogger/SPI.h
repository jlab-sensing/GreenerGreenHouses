#ifndef SPI_SAMPLE_H
#define SPI_SAMPLE_H

/**
 * SPI Module
 * Provides an API for using either of the Beaglebone's two SPI ports.
 * Allows for easy port initialization and transfers.
 */

#include <stdint.h>

#define NUM_SPI_BUSES 2
#define SPI_MODE_DEFAULT 0
#define SPEED_HZ_DEFAULT 500000

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"
#define SPI_DEV_BUS1_CS0 "/dev/spidev1.0"
#define SPI_DEV_BUS1_CS1 "/dev/spidev1.1"

// Configures pins associated with the specified port number for SPI
// Opens the file associated with that port and the specified chipSelect number
// SPI port number must be in the range 0 to 1
// For SPI port 0, chip select must be 0. For SPI port 1, chip select can be 0 or 1
// Returns the file descriptor
int SPI_initPort(char* spiDevice, int mode, int freqHz);

// Close the file descriptor
int SPI_closePort(int spiFileDesc);

// Prints the settings for the provided spiFileDesc.
// Status >= 0 is success, < 0 is error
int SPI_readSettings(int spiFileDesc);

// Returns the status
// Status >= 0 is success, < 0 is error
int SPI_transfer(int spiFileDesc, uint8_t *send, uint8_t *recv, int length);

#endif