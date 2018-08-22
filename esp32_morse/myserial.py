#coding:utf-8
import serial

def doSerial():
    with serial.Serial('COM4', 9600, timeout=1) as ser:
        while True:
            flag = bytes(input(), 'utf-8')
            ser.write(flag)
            if(flag==bytes('a', 'utf-8')):
                break
        ser.close()


doSerial()