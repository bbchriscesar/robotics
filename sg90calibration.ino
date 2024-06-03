#include <Servo.h>

Servo myServo;

int servoPin = 0;  // GPIO0 pin is used to control the servo

void setup() {
  myServo.attach(servoPin);
  calibrateServo();
}

void loop() {
  // Your main code here
}

void calibrateServo() {
  // Move the servo to position 0 (middle)
  myServo.writeMicroseconds(1500);
  delay(1000);  // Adjust the delay if needed
  
  // Move the servo to position 90 (all the way to the right)
  myServo.writeMicroseconds(2000);
  delay(1000);  // Adjust the delay if needed
  
  // Move the servo to position -90 (all the way to the left)
  myServo.writeMicroseconds(1000);
  delay(1000);  // Adjust the delay if needed
  
  // Return the servo to position 0 (middle)
  myServo.writeMicroseconds(1500);
  delay(1000);  // Adjust the delay if needed
}
