import serial
import time
import sys

ser = serial.Serial("/dev/ttyUSB0", 115200)    # 连接串口

while True:

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x01\x00\x00\x40\xCF')

  time.sleep(3)

  ser.write(b'\x86\xAB\x00\x0B\xE8\x15\x07\x00\x00\x41\xCF')

  time.sleep(3)

# while True:
#   data = ser.read_until(b'\xCF')
#   if data:
#     print(data)
#     s= 'Sample String'.encode('iso8859-1')
#     print(s.hex())

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
