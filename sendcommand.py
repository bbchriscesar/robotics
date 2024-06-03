import serial

# Replace 'COM5' with the actual port your RP2040 is connected to
ser = serial.Serial('COM4')

# Send the character '1' to turn on the LED
ser.write(b'0')

# Close the serial connection
ser.close()
