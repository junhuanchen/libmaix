import serial
import time
import sys

ser = serial.Serial("/dev/ttyUSB0", 115200)    # 连接串口

for f in range(1, 20):

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15' + f.to_bytes(1,'little') + b'\x00\x00' + (0x40 + f).to_bytes(1,'little') + b'\xCF')

  time.sleep(4)

sys.exit(0)

while True:

  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x02\x00\x00\x3B\xCF')

  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x05\x00\x00\x3F\xCF')

  print(time.asctime())

  time.sleep(2)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x07\x00\x00\x41\xCF')

  print(time.asctime())
