import serial
import time

ser = serial.Serial("/dev/ttyUSB0", 115200)    # 连接串口

while True:
  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x03\x00\x00\x3B\xCF')

  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x05\x00\x00\x3B\xCF')

  print(time.asctime())

  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x07\x00\x00\x3B\xCF')

  print(time.asctime())
