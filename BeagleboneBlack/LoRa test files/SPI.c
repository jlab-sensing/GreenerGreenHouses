
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include "SPI.h"

// The code for setting port parameters was taken and modified from spidev_test.c here:
// https://github.com/derekmolloy/exploringBB/blob/version2/chp08/spi/spidev_test/spidev_test.c
int SPI_initPort(char* spiDevice)
{    
    // Assume pins already configured for SPI
    // E.g. for SPI1, CS0:
    // (bbg)$ config-pin P9_28 spi_cs
    // (bbg)$ config-pin P9_31 spi_sclk
    // (bbg)$ config-pin P9_29 spi
    // (bbg)$ config-pin P9_30 spi

    // Open Device
    int spiFileDesc = open(spiDevice, O_RDWR);
    if (spiFileDesc < 0) {
		printf("Error: Can't open device %s", spiDevice);
        exit(1);
    }

    // Set port parameters

	// SPI mode
    int spiMode = SPI_MODE_DEFAULT;
	int errorCheck = ioctl(spiFileDesc, SPI_IOC_WR_MODE, &spiMode);
	if (errorCheck < 0) {
		printf("Error: Set SPI mode failed");
        exit(1);
    }

	// Max Speed (Hz)
    int speedHz = SPEED_HZ_DEFAULT;
	errorCheck = ioctl(spiFileDesc, SPI_IOC_WR_MAX_SPEED_HZ, &speedHz);
	if (errorCheck < 0) {
		printf("Error: Set max speed hz failed");
        exit(1);
    }

    return spiFileDesc;
}

int SPI_transfer(int spiFileDesc, uint8_t *sendBuf, uint8_t *receiveBuf, int length)
{
	struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer));
    
    transfer.tx_buf = (unsigned long)send;
    transfer.rx_buf = (unsigned long)recv;
    transfer.len = length;

    const int NUM_TRANSFERS = 1;
	int status = ioctl(spiFileDesc, SPI_IOC_MESSAGE(NUM_TRANSFERS), &transfer);
	if (status < 0) {
		printf("Error: SPI Transfer failed\n");
    }

    return status;
}

