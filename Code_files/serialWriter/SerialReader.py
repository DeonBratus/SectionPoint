import serial

connected = False
ser = serial.Serial("COM4", 9600)

while not connected:
    serin = ser.read()
    connected = True

ser.write("0".encode())

while ser.read == b'1':
    ser.read()

ser.close()
