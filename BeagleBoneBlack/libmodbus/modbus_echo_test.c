#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h> // open()
#include <sys/ioctl.h>

int main(void)
{
    int fd = open("/dev/ttyUSB0", O_NONBLOCK);
    int numChars;
    int counter = 0;
    char buff[512];

    printf("modbus test\n");
    printf("fd = %d\n",fd);
    while(1)
    {
        fprintf((FILE*)fd, "a");
        
        sleep(1);
    }
}
