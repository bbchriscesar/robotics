import serial
import time

# Set up the serial connection (COM7, 9600 baud rate)
ser = serial.Serial('COM7', 9600, timeout=1)
time.sleep(2)  # Wait for the connection to establish


def send_command(command):
    ser.write(command.encode())  # Send the command as bytes
    print(f"Sent command: {command}")
    time.sleep(0.5)  # Wait a bit for the command to be processed


try:
    while True:
        user_input = input("Enter command ('f' for forward, 'b' for backward, 'q' to quit): ")
        if user_input.lower() == 'q':
            break
        elif user_input.lower() in ['f', 'b']:
            send_command(user_input.lower())
        else:
            print("Invalid command. Please enter 'f', 'b', or 'q'.")
finally:
    ser.close()  # Close the serial connection when done
    print("Serial connection closed.")
