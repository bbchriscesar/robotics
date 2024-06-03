#include <Servo.h>

Servo myServo;  // Create a Servo object

void setup() {
  myServo.attach(0);  // Attach the servo to GP0
  myServo.write(180);  // Rotate servo clockwise at full speed
  // myServo.write(0);   // Rotate servo counterclockwise at full speed
}

void loop() {
  // No code needed here since the servo will rotate continuously
}
