import serial

ser = serial.Serial()
ser.baudrate = 115200
ser.port = "/dev/ttyACM3"
ser.open()

f = open("/tmp/stupid", "wb", 0)
print("assasas") 
while True:
    buf = ser.read_until(b"\n")
    print(buf)
    f.write(buf)