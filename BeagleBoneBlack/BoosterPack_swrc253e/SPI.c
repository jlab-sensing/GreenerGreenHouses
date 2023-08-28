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
int SPI_initPort(char* spiDevice, int mode, int freqHz)
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
    int spiMode = mode; // SPI_MODE_0?
	int errorCheck = ioctl(spiFileDesc, SPI_IOC_WR_MODE, &spiMode);
	if (errorCheck < 0) {
		printf("Error: Set SPI mode failed");
        exit(1);
    }

	// Max Speed (Hz)
    int speedHz = freqHz; // 9600
	errorCheck = ioctl(spiFileDesc, SPI_IOC_WR_MAX_SPEED_HZ, &speedHz);
	if (errorCheck < 0) {
		printf("Error: Set max speed hz failed");
        exit(1);
    }

    return spiFileDesc;
}

int SPI_readSettings(int spiFileDesc)
{
    uint8_t spiMode;
    if (ioctl(spiFileDesc, SPI_IOC_RD_MODE, &spiMode) < 0){
        printf("Error: Could not retrieve mode.\n");
        return -1;
    }
    uint32_t spiMode32;
    if (ioctl(spiFileDesc, SPI_IOC_RD_MODE32, &spiMode32) < 0){
        printf("Error: Could not retrieve mode32.\n");
        return -1;
    }
    uint8_t spiLSBFirst;
    if (ioctl(spiFileDesc, SPI_IOC_RD_LSB_FIRST, &spiLSBFirst) < 0){
        printf("Error: Could not retrieve LSB first.\n");
        return -1;
    }
    uint8_t spiBitsPerWord;
    if (ioctl(spiFileDesc, SPI_IOC_RD_BITS_PER_WORD, &spiBitsPerWord) < 0){
        printf("Error: Could not retrieve bits per word.\n");
        return -1;
    }
    uint32_t spiMaxSpeedHz;
    if (ioctl(spiFileDesc, SPI_IOC_RD_MAX_SPEED_HZ, &spiMaxSpeedHz) < 0){
        printf("Error: Could not retrieve max speed.\n");
        return -1;
    }
    printf("SPI Info:\n");
    printf("\tSPI_IOC_RD_MODE: 0x%X\n", spiMode);
    printf("\tSPI_IOC_RD_MODE32: 0x%X\n", spiMode32);
    printf("\tSPI_IOC_RD_LSB_FIRST: 0x%X\n", spiLSBFirst);
    printf("\tSPI_IOC_RD_BITS_PER_WORD: 0x%X\n", spiBitsPerWord);
    printf("\tSPI_IOC_RD_MAX_SPEED_HZ: 0x%X\n", spiMaxSpeedHz);
    return 0;
}

int SPI_transfer(int spiFileDesc, uint8_t *send, uint8_t *recv, int length)
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

