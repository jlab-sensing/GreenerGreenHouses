#include <stdio.h>
#include <rsc_types.h>

// #define TEST_TOGGLE
// #define TEST_UPCHIRP
#define TEST_UPCHIRP_LOG

#define CYCLES_PER_SECOND 200000000 /* PRU has 200 MHz clock */

#define P9_31 (1 << 0) /* R30 at 0x1 = pru1_pru0_pru_r30_0 = ball A13 = P9_31 */

volatile register uint32_t __R30; /* output register for PRU */
volatile register uint32_t __R31; /* output register for PRU */

void main(void) {
    uint16_t i, j = 1 << 15;
    while (1) {
#ifdef TEST_TOGGLE
        __R30 ^= P9_31;
#elif defined TEST_UPCHIRP
        __R30 ^= P9_31;
        for (i = j; i > 0; i--) asm(" NOP");
        j--;
#elif defined TEST_UPCHIRP_LOG
        __R30 ^= P9_31;
        for (i = j; i > 0; i >>= 1) asm(" NOP");
        if (j == 0){
            j = 1 << 15;
        }else{
            j >>= 1;
        }
#else
        __R30 |= P9_31; /* set first bit in register 30 */
        __delay_cycles(CYCLES_PER_SECOND / 4); /* wait 0.5 seconds */
        __R30 &= ~P9_31; /* unset first bit in register 30 */
        __delay_cycles(CYCLES_PER_SECOND / 4); /* wait 0.5 seconds */
#endif
    }
}

/* required by PRU */
#pragma DATA_SECTION(pru_remoteproc_ResourceTable, ".resource_table")
#pragma RETAIN(pru_remoteproc_ResourceTable)
struct my_resource_table {
    struct resource_table base;
    uint32_t offset[1];
} pru_remoteproc_ResourceTable = { 1, 0, 0, 0, 0 };
