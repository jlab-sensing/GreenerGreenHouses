PRU_SWPKG = /usr/lib/ti/pru-software-support-package

CC = clpru
LD = lnkpru
CFLAGS = --include_path=$(PRU_SWPKG)/include \
         --include_path=$(PRU_SWPKG)/include/am335x
LDFLAGS = $(PRU_SWPKG)/labs/lab_2/AM335x_PRU.cmd

all: am335x-pru0-fw

blink.o: blink.c
	$(CC) $(CFLAGS) $^ --output_file $@

am335x-pru0-fw: blink.o
	$(LD) $(LDFLAGS) $^ -o $@
