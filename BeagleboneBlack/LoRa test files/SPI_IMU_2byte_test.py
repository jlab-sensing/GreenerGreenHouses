#!/usr/bin/env python3

import board
import busio
import time

spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)

print("Obtaining SPI lock.")
while not spi.try_lock():
    pass

print("Configuring SPI")
spi.configure(baudrate=9600, phase=0, polarity=0, bits=16) #ICM-20948 IMU max 7 MHz SPI baud rate

# REGISTERS
# Address 0x00; WHO_AM_I, expect 0xEA
# 0 is write, 1 is read
# WHO_AM_I = b'\x00'
WHO_AM_I_WRITE = 0x00
WHO_AM_I_READ = 0x80
DEVICE_ID = 0xEA
REG_BANK_SEL = 0x7F
readBuffer = [0x00 for x in range(2)]
# readBuffer=bytearray(2)

# print(list(map(hex, readBuffer)))

print("read REG_BANK_SEL")
spi.write_readinto([0xFF, 0xFF], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("write REG_BANK_SEL bank 0")
spi.write_readinto([0x7F, 0x00], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("read PWR_MGMT_1")
spi.write_readinto([0x06, 0x06], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("write PWR_MGMT_1 reset")
spi.write_readinto([0x86, 0xA1], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("read PWR_MGMT_1")
spi.write_readinto([0x06, 0x06], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("write PWR_MGMT_1 unsleep")
spi.write_readinto([0x86, 0x01], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)



print("read REG_BANK_SEL")
spi.write_readinto([0xFF, 0xFF], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("write REG_BANK_SEL bank 0")
spi.write_readinto([0x7F, 0x00], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("read WHO_AM_I")
spi.write_readinto([0x80, 0x80], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("read WHO_AM_I")
spi.write_readinto([0x80, 0x80], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)



print("read TEMP_OUT_H")
spi.write_readinto([0x39, 0x39], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

print("read TEMP_OUT_L")
spi.write_readinto([0x3A, 0x3A], readBuffer)
print(list(map(hex, readBuffer)))
readBuffer = [0x00 for x in range(2)]

time.sleep(0.1)

# print("Writing: " + str(WHO_AM_I))
# spi.write([WHO_AM_I])

# time.sleep(0.1)

# print("repeat")
# while True:
    # spi.write_readinto([WHO_AM_I_READ], readBuffer, in_end=1)
    # print(list(map(hex, readBuffer)))
    # input("Enter to continue")

# while True:
    # spi.write(bytes(range(64)))
    # time.sleep(0.1)


spi.unlock()