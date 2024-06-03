import serial

# Replace 'COM4' with the actual port your RP2040 is connected to
ser = serial.Serial('COM4', 9600)  # Specify baud rate (9600 in this example)

# Send the character 'f' to turn on the LED
ser.write(b'f')

# Read feedback from the serial monitor
feedback = ser.readline().decode().strip()
print("Feedback:", feedback)

# Close the serial connection
ser.close()
