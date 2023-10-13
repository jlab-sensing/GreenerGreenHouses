#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/mman.h>

// GPIO chip base addresses (span 0x1000 = 4096 bytes each)
#define GPIO0_ADDR 0x44E07000
#define GPIO1_ADDR 0x4804C000
#define GPIO2_ADDR 0x481AC000
#define GPIO3_ADDR 0x481AE000

static int gpioBaseAddress[] = {GPIO0_ADDR, GPIO1_ADDR, GPIO2_ADDR, GPIO3_ADDR};

// GPIO byte offsets
#define GPIO_OE              0x134
#define GPIO_DATAOUT         0x13C
#define GPIO_DATAIN          0x138
#define GPIO_CLEARDATAOUT    0x190
#define GPIO_SETDATAOUT      0x194

// GPIO word offsets (byte offset / 4)
#define GPIO_CLEARDATAOUT_W  0x64
#define GPIO_SETDATAOUT_W    0x65

/* GPIO offsets (full)
#define GPIO_REVISION        0x0
#define GPIO_SYSCONFIG       0x10
#define GPIO_EOI             0x20
#define GPIO_IRQSTATUS_RAW_0 0x24
#define GPIO_IRQSTATUS_RAW_1 0x28
#define GPIO_IRQSTATUS_0     0x2C
#define GPIO_IRQSTATUS_1     0x30
#define GPIO_IRQSTATUS_SET_0 0x34
#define GPIO_IRQSTATUS_SET_1 0x38
#define GPIO_IRQSTATUS_CLR_0 0x3C
#define GPIO_IRQSTATUS_CLR_1 0x40
#define GPIO_IRQWAKEN_0      0x44
#define GPIO_IRQWAKEN_1      0x48
#define GPIO_SYSSTATUS       0x114
#define GPIO_CTRL            0x130
#define GPIO_OE              0x134
#define GPIO_DATAIN          0x138
#define GPIO_DATAOUT         0x13C
#define GPIO_LEVELDETECT0    0x140
#define GPIO_LEVELDETECT1    0x144
#define GPIO_RISINGDETECT    0x148
#define GPIO_FALLINGDETECT   0x14C
#define GPIO_DEBOUNCENABLE   0x150
#define GPIO_DEBOUNCINGTIME  0x154
#define GPIO_CLEARDATAOUT    0x190
#define GPIO_SETDATAOUT      0x194
*/

// P9_23 is gpio49 is on chip 1 line 17 (32 * 1 + 17)
// P9_15 is gpio48 is on chip 1 line 16 (32 * 1 + 16)

#define SELECT_GPIO_CHIP 1
#define SELECT_GPIO_LINE 17

#define DELAY_CYCLES(x) do{for(int i = 0; i < x; i++);}while(0)

// Modified from http://vabi-robotics.blogspot.com/2013/10/register-access-to-gpios-of-beaglebone.html

int main(int argc, char * argv[])
{
    uint8_t chip[2], line[2], gpioNumber[2];
    switch (argc){
        case 3: // assume provided second gpio
            gpioNumber[1] = atoi(argv[2]);
            chip[1] = gpioNumber[1] / 32;
            line[1] = gpioNumber[1] % 32;
            printf("gpio%d[%d] = gpio%d\n", chip[1], line[1], gpioNumber[1]);
            // fall-through to process second arg
        case 2: // assume logical number
            gpioNumber[0] = atoi(argv[1]);
            chip[0] = gpioNumber[0] / 32;
            line[0] = gpioNumber[0] % 32;
            printf("gpio%d[%d] = gpio%d\n", chip[0], line[0], gpioNumber[0]);
            break;
        default:
            printf("usage:\nsudo %s <gpio#> <optional: gpio#>\nNote: Must be run with sudo or else you get segfault. Partial list of gpio is available in '/sys/class/gpio/'. Refer to Beaglebone Black System Reference Manual for gpio details.\n", argv[0], argv[0]);
            return -1;
            break;
    }
    
    // Check for valid gpio
    for (int i = 0; i < 2; i++){
        if ((chip[i] > 3) || (line[i] > 31) || (gpioNumber[i] > 128)){
            printf("Invalid gpio entered.\n");
            return -1;
        }
    }
    
    if (argc == 3){
        if (chip[0] != chip[1]){
            printf("For this example program, both gpios must be on the same chip.\n");
        }
    }
    
    printf("Opening /dev/mem\n");
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    
    printf("Init pinconf1\n");
    ulong* pinconf1 = (ulong*) mmap(NULL, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, gpioBaseAddress[chip[0]]);
    
    printf("setting OE\n");
    pinconf1[GPIO_OE/4] &= (0xFFFFFFFF ^ ((1 << line[0]) | (1 << line[1])));
    
    printf("gpio blinking\n");
    uint32_t delay = 1; // 1 << 20 corresponds to about 67 Hz
    while(1){
        // pinconf1[GPIO_DATAOUT/4]  |= (1 << line);
        // DELAY_CYCLES(10);
        // pinconf1[GPIO_DATAOUT/4]  ^= (1 << line);
        // DELAY_CYCLES(10);
        
        
        // for (int delay = 1; delay < (1 << 21); delay << 1){
            // for (int duration = 0; duration < 1000000; duration += delay){
                
        // pinconf1[GPIO_SETDATAOUT/4] = ((1 << line[0]) | (1 << line[1]));
        pinconf1[GPIO_SETDATAOUT/4] = (1 << line[0]);
        pinconf1[GPIO_CLEARDATAOUT/4] = (1 << line[1]);
        DELAY_CYCLES(delay);
        // pinconf1[GPIO_CLEARDATAOUT/4] = ((1 << line[0]) | (1 << line[1]));
        pinconf1[GPIO_CLEARDATAOUT/4] = (1 << line[0]);
        pinconf1[GPIO_SETDATAOUT/4] = (1 << line[1]);
        DELAY_CYCLES(delay);
                
            // }
        // }
        
        
        delay = delay << 1;
        if (delay > (1 << 19)) delay = 1;
    }
    
    return 0;
    
    /* input
    pinconf1[GPIO_DATAOUT/4]  &= (0xFFFFFFFF ^ ((1 << 21) | (1 << line))); // set both off
    pinconf1[GPIO_OE/4] |= ( 1 << line); // set input
    for(int i = 0; i < 20; i++){
        printf("%ld\n", pinconf1[GPIO_DATAIN/4]);
        if(pinconf1[GPIO_DATAIN/4] & (1  << line)){
            printf("on\n");
            pinconf1[GPIO_DATAOUT/4]  |= (1 << 21);
        }
        else{
            printf("off\n");
            pinconf1[GPIO_DATAOUT/4] &= (0xFFFFFFFF ^ (1 << 21));
        }
        sleep(1);
    }
    pinconf1[GPIO_DATAOUT/4]  ^= (1 << 21);
    return 0;
    */
    
}
