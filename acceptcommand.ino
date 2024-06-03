#include <Servo.h>

Servo myServo;  // Create a Servo object

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  myServo.attach(0);   // Attach the servo to GP0
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming command

    if (command == 'f') {
      myServo.write(180);  // Rotate servo clockwise at full speed
    } else if (command == 'b') {
      myServo.write(0);    // Rotate servo counterclockwise at full speed
    } else if (command == '0') {
      myServo.write(90);   // Stop the servo
    }
  }
}
