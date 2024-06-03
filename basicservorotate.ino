#include <Servo.h>

Servo myServo;  // Create a Servo object

void setup() {
  myServo.attach(0);  // Attach the servo to GP0
}

void loop() {
  myServo.write(0);  // Move servo to 0 degrees
  delay(2000);       // Wait for 2 seconds
  myServo.write(180);  // Move servo to 180 degrees
  delay(2000);       // Wait for 2 seconds
}
