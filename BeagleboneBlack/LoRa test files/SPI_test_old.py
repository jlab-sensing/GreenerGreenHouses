#!/usr/bin/env python3

#import Adafruit_BBIO.GPIO as GPIO
from Adafruit_BBIO.SPI import SPI
import time

myList = "ABCDEF"

# SPI
print("Initialize SPI")
spi = SPI(0,0)

print("Starting transfer")
#for x in myList:
spi.xfer([0x41, 0x42, 0x43], 1000)
#time.sleep(0.5)

print("Transfer finished")

#while True:
#    print(temp, end="\r")
#    time.sleep(0.25)
