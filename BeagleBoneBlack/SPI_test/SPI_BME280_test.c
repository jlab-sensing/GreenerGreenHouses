#include <fcntl.h> // open()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
// #include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "SPI.h"

// #define uint8_t u_int8_t
#define SPI_BUFFER_SIZE 4

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"

#define BME_280_REG_READ 0x80
#define BME_280_REG_WRITE 0x7F

int main(int argc, char *argv[]){
    
    printf("Program start.\n");
    
    printf("Opening %s in O_RDWR (r+).\n", SPI_DEV_BUS0_CS0);
    // SPI_MODE_x: (or combine SPI_CPOL and SPI_CPHA accordingly)
    // 0: no pol, no pha
    // 1: yes pol, no pha
    // 2: no pol, yes pha
    // 3: yes pol, yes pha
    // Frequencies:
    // SPEED_HZ_DEFAULT
    // choose your own
    int spiFileDesc = SPI_initPort(SPI_DEV_BUS0_CS0, SPI_MODE_0, 115200);
    if (spiFileDesc < 0){
        printf("Error: Could not init SPI.\n");
        exit(1);
    }

    if (SPI_readSettings(spiFileDesc) < 0){
        printf("Error: Could not read SPI mode settings.\n");
        exit(1);
    }
    
    uint8_t *txBuffer = malloc(SPI_BUFFER_SIZE);
    uint8_t *rxBuffer = malloc(SPI_BUFFER_SIZE);
    
    // Read BME280 device ID, expect 0x60
    txBuffer[0] = 0xD0 | BME_280_REG_READ;
    txBuffer[1] = 0x00; // dummy
    
    // Reset BME280
    txBuffer[2] = 0xE0 & BME_280_REG_WRITE;
    txBuffer[3] = 0xB6; // reset command
    
    
    
    while(1){
        SPI_transfer(spiFileDesc, txBuffer, rxBuffer, SPI_BUFFER_SIZE);
        sleep(1);
        printf("\nrxBuffer: ");
        for (int i = 0; i < SPI_BUFFER_SIZE; i++){
            printf("0x%X ", rxBuffer[i]);
        }
        sleep(1);
    }

    printf("Closing \"/dev/spidev0.0\".\n");
    // fclose(spiFileDesc);
    return 0;
}
