#include <Servo.h>

// Define the servo pin
const int servoPin = 0;

// Create a Servo object
Servo myServo;

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);

  // Initialize the servo to its center position
  myServo.writeMicroseconds(1500); // Center position for MG995

  // Allow time for the servo to reach its position
  delay(1000);

  // Calibrate the servo dead band width
  calibrateServo();
}

void loop() {
  // Nothing to do in the loop for this example
}

void calibrateServo() {
  // Define the dead band width
  const int deadBandWidth = 5; // µs

  // Define the center position pulse width
  const int centerPulseWidth = 1500; // µs

  // Calculate the pulse widths for the dead band range
  int minPulseWidth = centerPulseWidth - (deadBandWidth / 2);
  int maxPulseWidth = centerPulseWidth + (deadBandWidth / 2);

  // Move the servo to the minimum pulse width position
  myServo.writeMicroseconds(minPulseWidth);

  // Wait for the servo to reach the position
  delay(1000);

  // Move the servo to the maximum pulse width position
  myServo.writeMicroseconds(maxPulseWidth);

  // Wait for the servo to reach the position
  delay(1000);

  // Move the servo back to the center position
  myServo.writeMicroseconds(centerPulseWidth);

  // Calibration complete
  Serial.println("Servo calibration complete!");
}
