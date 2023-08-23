#!/usr/bin/env python3

import board
import busio
import time

imu = busio.I2C(board.SCL, board.SDA, frequency=9600)

print(imu.scan())

