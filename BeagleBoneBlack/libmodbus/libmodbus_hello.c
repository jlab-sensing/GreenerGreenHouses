#include <stdio.h>
// #include <stdlib.h>
#include <modbus/modbus.h>
// #include <modbus/modbus-rtu.h>

#define MODBUS_DEBUG_ENABLE
// #ifdef MODBUS_DEBUG_ENABLE
    // #define printf(x) do{ printf("\t"); printf(x);} while(0);
// #endif

#define RTU_PORT        "/dev/ttyUSB0"
#define RTU_BAUD        19200
#define RTU_PARITY      'N'
#define RTU_DATA_BITS   8
#define RTU_STOP_BITS   1

// gcc libmodbus_hello.c -o libmodbus_hello -lmodbus
// Emulates a modbus server
int main(void) {
    modbus_t *mb;
    printf("Program start.\n");
    
    printf("Instantiating Modbus RTU on %s at %d baud (%d%c%d).\n", RTU_PORT, RTU_BAUD, RTU_DATA_BITS, RTU_PARITY, RTU_STOP_BITS);
    mb = modbus_new_rtu(RTU_PORT, RTU_BAUD, RTU_PARITY, RTU_DATA_BITS, RTU_STOP_BITS);
    printf("mb = 0x%02X\n", mb);
    
#ifdef MODBUS_DEBUG_ENABLE
    printf("MODBUS_DEBUG_ENABLE\n");
    if (modbus_set_debug(mb, TRUE) != 0){
        printf("Failed to enable debug on mb = 0x%02X with flag %d\n", mb, TRUE);
        return -1;
    }
    printf("Enabled debug.\n");
#endif
    
    printf("Check Modbus RTU settings:\n");
    int serial_mode = modbus_rtu_get_serial_mode(mb);
    printf("\tSerial mode: %d ", serial_mode);
    switch(serial_mode){
        case MODBUS_RTU_RS232:
            printf("MODBUS_RTU_RS232\n");
            break;
        case MODBUS_RTU_RS485:
            printf("MODBUS_RTU_RS485\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }
    int rts_mode = modbus_rtu_get_rts(mb);
    printf("\tRTS mode: %d ", rts_mode);
    switch(serial_mode){
        case MODBUS_RTU_RTS_NONE:
            printf("MODBUS_RTU_RTS_NONE\n");
            break;
        case MODBUS_RTU_RTS_UP:
            printf("MODBUS_RTU_RTS_UP\n");
            break;
        case MODBUS_RTU_RTS_DOWN:
            printf("MODBUS_RTU_RTS_DOWN\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }
    int rts_delay = modbus_rtu_get_rts_delay(mb);
    printf("\tRTS delay: %d us\n", rts_delay);
    if (rts_delay == -1) printf("ERROR\n");
    
    
    
    printf("Opening connection.\n");
    if (modbus_connect(mb) != 0){
        printf("modbus_connect(mb=0x%02X) failed to connect.\n", mb);
        return -1;
    }
    
    printf("Closing connection.\n");
    modbus_close(mb);
    
    printf("Flushing non-transmitted data.\n");
    int bytes_flushed;
    bytes_flushed = modbus_flush(mb);
    printf("Flushed %d bytes.\n", bytes_flushed);
    
    
    // modbus_close(mb);
    printf("Freeing mb = 0x%02X\n", mb);
    modbus_free(mb);
    
    printf("Program end.\n");
    return 0;
    
    /*
    modbus_t *mb;
    uint16_t tab_reg[32];

    mb = modbus_new_tcp("127.0.0.1", 1502);
    modbus_connect(mb);

    // Read 5 registers from the address 0
    modbus_read_registers(mb, 0, 5, tab_reg);

    modbus_close(mb);
    modbus_free(mb);
    */
}