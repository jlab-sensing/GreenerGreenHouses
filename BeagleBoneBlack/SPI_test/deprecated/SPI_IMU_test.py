#!/usr/bin/env python3

import board
import busio
import time

spi = busio.SPI(board.SCLK, board.MOSI, board.MISO)

print("Obtaining SPI lock.")
while not spi.try_lock():
    pass

print("Configuring SPI")
spi.configure(baudrate=1500000, phase=0, polarity=0, bits=8) #ICM-20948 IMU max 7 MHz SPI baud rate

# REGISTERS
# Address 0x00; WHO_AM_I, expect 0xEA
# 0 is write, 1 is read
# WHO_AM_I = b'\x00'
WHO_AM_I_WRITE = 0x00
WHO_AM_I_READ = 0x80
DEVICE_ID = 0xEA
REG_BANK_SEL = 0x7F
readBuffer = [0x00 for x in range(4)]
# readBuffer=bytearray(4)

print("1 REG_BANK_SEL write")
spi.write_readinto([REG_BANK_SEL], readBuffer, in_end=1)
print(readBuffer)

print("2 USER_BANK 0")
spi.write_readinto([0x00], readBuffer, in_end=1)
print(readBuffer)

print("1 PWR_MGMT_1 read")
spi.write_readinto([0x86], readBuffer, in_end=1)
print(readBuffer)

print("2 PWR_MGMT_1 read again")
spi.write_readinto([0x86], readBuffer, in_end=1)
print(readBuffer)
PWR_MGMT_1 = readBuffer[0]

print("1 PWR_MGMT_1 write")
spi.write_readinto([0x06], readBuffer, in_end=1)
print(readBuffer)

print("2 PWR_MGMT_1 unsleep")
spi.write_readinto([PWR_MGMT_1 & 0xBF], readBuffer, in_end=1)
print(readBuffer)

print("1 WHO_AM_I read")
spi.write_readinto([WHO_AM_I_READ], readBuffer, in_end=1)
print(readBuffer)

print("2 WHO_AM_I read again")
spi.write_readinto([WHO_AM_I_READ], readBuffer, in_end=1)
print(readBuffer)

print("1 TEMP_OUT_H read")
spi.write_readinto([0x39], readBuffer, in_start=1, in_end=2)
print(readBuffer)

print("1 TEMP_OUT_L read")
spi.write_readinto([0x3A], readBuffer, in_start=1, in_end=2)
print(readBuffer)

print("dummy")
spi.write_readinto([0x3A], readBuffer, in_start=2, in_end=3)
print(readBuffer)

# print("Writing: " + str(WHO_AM_I))
# spi.write([WHO_AM_I])

# time.sleep(0.1)

print("repeat")
while True:
    spi.write_readinto([WHO_AM_I_READ], readBuffer, in_end=1)
    print(readBuffer)
    input("Enter to continue")

# while True:
    # spi.write(bytes(range(64)))
    # time.sleep(0.1)


spi.unlock()