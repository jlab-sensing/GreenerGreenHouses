#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    FILE *io,*iodir,*ioval;
    int interval = 1;
    
    if (argc != 2){
        printf("usage: %s <pin toggle interval [usec]>\n", argv[0]);
        return -1;
    }else{
        interval = atoi(argv[1]);
    }

    // io = fopen("/sys/class/gpio/export", "w");
    // if (io == NULL){
        // printf("io null\n");
        // return -1;
    // }
    // fseek(io,0,SEEK_SET);
    // fprintf(io,"%d",39);
    // fflush(io);

    iodir = fopen("/sys/class/gpio/gpio49/direction", "w");
    if (iodir == NULL){
        printf("iodir null\n");
        return -1;
    }
    printf("seek start\n");
    fseek(iodir,0,SEEK_SET);
    printf("write out\n");
    fwrite("out", sizeof(char), 3, iodir);
    // printf("fflush\n");
    // fflush(iodir);

    ioval = fopen("/sys/class/gpio/gpio49/value", "w");
    if (ioval == NULL){
        printf("ioval null\n");
        return -1;
    }
    fseek(ioval,0,SEEK_SET);

    const char high = '1';
    const char low = '0';
    printf("sizes: %d %d bytes\n", sizeof(high), sizeof(low));
    while(1)
    {
        fwrite(&high, sizeof(high), 1, ioval);
        fflush(ioval);
        // usleep(interval);
        fwrite(&low, sizeof(low), 1, ioval);
        fflush(ioval);
        // usleep(interval);
    }

    // fclose(io);
    fclose(iodir);
    fclose(ioval);
    return 0;
}
