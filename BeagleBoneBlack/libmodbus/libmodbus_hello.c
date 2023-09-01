#include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>
#include <modbus/modbus.h>
// #include <modbus/modbus-rtu.h>

#define MODBUS_DEBUG_ENABLE
// #ifdef MODBUS_DEBUG_ENABLE
    // #define printf(x) do{ printf("\t"); printf(x);} while(0);
// #endif

#define MODBUS_SLAVE

#define MODBUS_SLAVE_ID 0xAB

#define MAP_SIZE_ALL 32

#define RTU_PORT        "/dev/ttyUSB0"
#define RTU_BAUD        19200
#define RTU_PARITY      'N'
#define RTU_DATA_BITS   8
#define RTU_STOP_BITS   1

modbus_t * modbus_setup(const char *device, int baud, char parity, int data_bit, int stop_bit);
void print_modbus_mapping(modbus_mapping_t *map);

// gcc libmodbus_hello.c -o libmodbus_hello -lmodbus
// Emulates a modbus server
int main(int argc, char *argv[]) {
    int status;
    modbus_t *mb = NULL;
    
    printf("Program start ");
    
#ifndef MODBUS_SLAVE
    printf("Master mode\n");
#else
    printf("Slave mode\n");
#endif
    
    printf("Setting up modbus struct and config.\n");
    mb = modbus_setup(RTU_PORT, RTU_BAUD, RTU_PARITY, RTU_DATA_BITS, RTU_STOP_BITS);
    printf("mb = 0x%02X\n", mb);
    
#ifndef MODBUS_SLAVE
    printf("set_slave (master: destination) address 0x%02X (%d) ", MODBUS_SLAVE_ID, MODBUS_SLAVE_ID);
#else
    printf("set_slave (slave: address) address 0x%02X (%d) ", MODBUS_SLAVE_ID, MODBUS_SLAVE_ID);
#endif
    status = modbus_set_slave(mb, MODBUS_SLAVE_ID);
    printf("status = %d\n", status);
    
    printf("Opening connection.\n");
    if (modbus_connect(mb) != 0){
        printf("modbus_connect(mb=0x%02X) failed to connect.\n", mb);
        return -1;
    }
    
    printf("get_socket == %d, flushed %d bytes\n", modbus_get_socket(mb), modbus_flush(mb));
    
#ifndef MODBUS_SLAVE
    // printf("Writing 1 bit (1b) to 0x00CD\n");
    // status = modbus_write_bit(mb, 0x00CD, 1);
    // printf("status = %d\n", status);
    uint16_t data = 0xABCD;
    uint16_t addr = 0x0000;
    while(1){
        printf("addr 0x%02X --> 0x%02X\n", addr, data);
        status = modbus_write_register(mb, addr++, data);
        printf("status = %d\n\n", status);
        // sleep(1);
        // usleep(100000);
    }
#else
    printf("Mapping %d rows\n", MAP_SIZE_ALL);
    modbus_mapping_t *map;
    // map = modbus_mapping_new_start_address();
    map = modbus_mapping_new(MAP_SIZE_ALL, MAP_SIZE_ALL, MAP_SIZE_ALL, MAP_SIZE_ALL); // 16 of each
    /* 
        map->tab_bits[0]
        map->tab_input_bits[0]
        map->tab_input_registers[0]
        map->tab_registers[0]
    */
    
    if (map == NULL){
        printf("modbus_mapping_new failed to allocate.\n");
        return -1;
    }
    
    int req_length;
    uint8_t req[MODBUS_MAX_ADU_LENGTH];
    int iteration = 0;
    while(1){
        printf("\n%d\n", iteration++);
        
        print_modbus_mapping(map);
        
        printf("waiting on modbus_receive\n");
        req_length = modbus_receive(mb, req);
        switch(req_length){
            case 0:
                printf("Ignore request (other slave address)\n");
                break;
            case -1:
                printf("Error receiving\n");
                break;
            default:
                printf("Handling request (length %d)\n", req_length);
                sleep(1);
                status = modbus_reply(mb, req, req_length, map);
                if (status == -1){
                    printf("Could not reply\n");
                }else{
                    printf("Sent reply (length %d)\n", status);
                }
                break;
        }
    }
    
#endif
    
    
    printf("Closing connection.\n");
    modbus_close(mb);
    
    printf("Flushing non-transmitted data.\n");
    int bytes_flushed;
    bytes_flushed = modbus_flush(mb);
    printf("Flushed %d bytes.\n", bytes_flushed);
    
    printf("Freeing mb = 0x%02X\n", mb);
    modbus_free(mb);
    
    printf("Program end.\n");
    return 0;
}

modbus_t * modbus_setup(const char *device, int baud, char parity, int data_bit, int stop_bit)
{
    modbus_t *mb;
    printf("\t(before) mb = 0x%02X\n", mb);
    printf("\tInstantiating Modbus RTU on %s at %d baud (%d%c%d).\n", device, baud, data_bit, parity, stop_bit);
    mb = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    printf("\t(after) mb = 0x%02X\n", mb);
    
#ifdef MODBUS_DEBUG_ENABLE
    printf("\tMODBUS_DEBUG_ENABLE\n");
    if (modbus_set_debug(mb, TRUE) != 0){
        printf("Failed to enable debug on mb = 0x%02X with flag %d\n", mb, TRUE);
        // return 0;
    }
    // printf("Enabled debug.\n");
#endif
    
    printf("\tCheck Modbus RTU settings:\n");
    int serial_mode = modbus_rtu_get_serial_mode(mb);
    printf("\t\tSerial mode: %d ", serial_mode);
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
    printf("\t\tRTS mode: %d ", rts_mode);
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
    printf("\t\tRTS delay: %d us\n", rts_delay);
    if (rts_delay == -1) printf("ERROR\n");
    
    return mb;
}

void print_modbus_mapping(modbus_mapping_t *map)
{
    // printf("Dumping data (hex):\n");
    printf("addr\tbit\tibit\tireg\treg\n");
    printf("------------------------------------\n");
    for (int i = 0; i < MAP_SIZE_ALL; i++){
        printf("%04X|\t%04X\t%04X\t%04X\t%04X\n", 
        i, 
        map->tab_bits[i], 
        map->tab_input_bits[i], 
        map->tab_input_registers[i], 
        map->tab_registers[i]);
    }
}