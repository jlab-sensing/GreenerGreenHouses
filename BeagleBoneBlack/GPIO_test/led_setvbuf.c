#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    FILE *iodir, *ioval;

    iodir = fopen("/sys/class/gpio/gpio49/direction", "w");
    if (iodir == NULL){
        printf("iodir null\n");
        return -1;
    }
    printf("seek start\n");
    fseek(iodir,0,SEEK_SET);
    printf("write out\n");
    fwrite("out", sizeof(char), 3, iodir);
    fflush(iodir);

    ioval = fopen("/sys/class/gpio/gpio49/value", "w");
    if (ioval == NULL){
        printf("ioval null\n");
        return -1;
    }
    fseek(ioval,0,SEEK_SET);
    
    setvbuf(ioval, NULL, _IONBF, 0); // no buffer, write immediately

    const char high = '1';
    const char low = '0';
    printf("sizes: %d %d bytes\n", sizeof(high), sizeof(low));
    while(1)
    {
        fputc('1', ioval);
        fputc('0', ioval);
        // fwrite(&high, sizeof(high), 1, ioval);
        // fflush(ioval);
        // usleep(interval);
        // fwrite(&low, sizeof(low), 1, ioval);
        // fflush(ioval);
        // usleep(interval);
    }

    // fclose(io);
    fclose(iodir);
    fclose(ioval);
    return 0;
}
