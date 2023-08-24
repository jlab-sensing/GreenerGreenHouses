#include <fcntl.h> // open()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
// #include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// #define uint8_t u_int8_t
#define SPI_BUFFER_SIZE 256

void SPI_transfer(int spiFileDesc, uint8_t *txBuffer, uint8_t *rxBuffer, int length);

int main(int argc, char *argv[]){
    
    printf("Program start.\n");
    
    printf("Opening \"/dev/spidev0.0\" in O_RDWR (r+).\n");
    // FILE* spiFileDesc = fopen("/dev/spidev0.0", "r+");
    int spiFileDesc = open("/dev/spidev0.0", O_RDWR);
    if (spiFileDesc < 0){
        printf("Error: Could not open SPI.\n");
        exit(1);
    }
    
    uint8_t spiMode = SPI_MODE_0; // SPI_MODE_0: SPI_CPOL and SPI_CPHA not set
    if (ioctl(spiFileDesc, SPI_IOC_WR_MODE, &spiMode) < 0){
        printf("Error: Could not set SPI mode.\n");
        exit(1);
    }
    
    uint32_t spiMaxSpeedHz = 9600;
    if (ioctl(spiFileDesc, SPI_IOC_WR_MAX_SPEED_HZ, &spiMaxSpeedHz) < 0){
        printf("Error: Could not set max speed.\n");
        exit(1);
    }
    
    
    
    if (ioctl(spiFileDesc, SPI_IOC_RD_MODE, &spiMode) < 0){
        printf("Error: Could not retrieve mode.\n");
        exit(1);
    }
    uint32_t spiMode32;
    if (ioctl(spiFileDesc, SPI_IOC_RD_MODE32, &spiMode32) < 0){
        printf("Error: Could not retrieve mode32.\n");
        exit(1);
    }
    uint8_t spiLSBFirst;
    if (ioctl(spiFileDesc, SPI_IOC_RD_LSB_FIRST, &spiLSBFirst) < 0){
        printf("Error: Could not retrieve LSB first.\n");
        exit(1);
    }
    uint8_t spiBitsPerWord;
    if (ioctl(spiFileDesc, SPI_IOC_RD_BITS_PER_WORD, &spiBitsPerWord) < 0){
        printf("Error: Could not retrieve bits per word.\n");
        exit(1);
    }
    if (ioctl(spiFileDesc, SPI_IOC_RD_MAX_SPEED_HZ, &spiMaxSpeedHz) < 0){
        printf("Error: Could not retrieve max speed.\n");
        exit(1);
    }
    printf("SPI Info:\n");
    printf("\tSPI_IOC_RD_MODE: 0x%X\n", spiMode);
    printf("\tSPI_IOC_RD_MODE32: 0x%X\n", spiMode32);
    printf("\tSPI_IOC_RD_LSB_FIRST: 0x%X\n", spiLSBFirst);
    printf("\tSPI_IOC_RD_BITS_PER_WORD: 0x%X\n", spiBitsPerWord);
    printf("\tSPI_IOC_RD_MAX_SPEED_HZ: 0x%X\n", spiMaxSpeedHz);
    
    
    uint8_t *txBuffer = malloc(SPI_BUFFER_SIZE);
    uint8_t *rxBuffer = malloc(SPI_BUFFER_SIZE);
    
    for (int i = 0; i < SPI_BUFFER_SIZE; i++){
        txBuffer[i] = i;
    }
    // txBuffer[0] = 0x80; // Read WHO_AM_I
    // txBuffer[1] = 0xAA; // 
    // txBuffer[2] = 0xFF; // 
    
    while(1){
        SPI_transfer(spiFileDesc, txBuffer, rxBuffer, SPI_BUFFER_SIZE);
        sleep(1);
        printf("\nrxBuffer:\n");
        for (int i = 0; i < SPI_BUFFER_SIZE; i++){
            printf("%d ", rxBuffer[i]);
        }
        sleep(1);
    }

    printf("Closing \"/dev/spidev0.0\".\n");
    // fclose(spiFileDesc);
    return 0;
}

void SPI_transfer(int spiFileDesc, uint8_t *txBuffer, uint8_t *rxBuffer, int length){
    struct spi_ioc_transfer transfer = {    
        .tx_buf = (unsigned long) txBuffer,
        .rx_buf = (unsigned long) rxBuffer,
        .len = length
    };
    
    const int NUM_TRANSFERS = 1;
    if (ioctl(spiFileDesc, SPI_IOC_MESSAGE(NUM_TRANSFERS), &transfer) < 0){
        printf("Error: SPI transfer failed.\n");
    }
}