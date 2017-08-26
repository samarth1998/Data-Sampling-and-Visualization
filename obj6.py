import serial
aser = serial.Serial('COM6', 115200)
while True:
    print int((aser.read()).encode('bin '), 16)