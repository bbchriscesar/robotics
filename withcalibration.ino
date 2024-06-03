#include <Servo.h>

// TD-8325MG servo with calibration
// Check your servo data sheet before using the calibration

Servo myServo;  // Create a Servo object

void setup() {
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  myServo.attach(0);        // Attach the servo to GP0 (PWM pin)
  calibrateServo();         // Calibrate the servo
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming command
    
    if (command == 'f') {
      myServo.write(180);  // Rotate servo to 180 degrees
      Serial.println("Servo rotated to 180 degrees (full clockwise).");  // Feedback
    } else if (command == 'b') {
      myServo.write(0);    // Rotate servo to 0 degrees
      Serial.println("Servo rotated to 0 degrees (full counterclockwise).");  // Feedback
    } else if (command == '0') {
      myServo.write(90);   // Rotate servo to 90 degrees (middle position)
      Serial.println("Servo rotated to 90 degrees (stopped/middle position).");  // Feedback
    } else {
      Serial.println("Unknown command. Please use 'f' for 180 degrees, 'b' for 0 degrees, or '0' for 90 degrees.");  // Error handling
    }
  }
}

void calibrateServo() {
  // Set the central point and dead band width for the servo
  int centralPoint = 1500;   // Central point in microseconds
  int deadBandWidth = 2;      // Dead band width in microseconds
  
  // Calculate the minimum and maximum pulse widths
  int minPulseWidth = centralPoint - deadBandWidth;   // Minimum pulse width
  int maxPulseWidth = centralPoint + deadBandWidth;   // Maximum pulse width
  
  // Calibrate the servo by moving it to its minimum and maximum positions
  Serial.println("Calibrating servo...");
  myServo.writeMicroseconds(minPulseWidth);  // Set servo to minimum position
  delay(1000);  // Delay for stability
  Serial.println("Servo calibrated to minimum position.");
  delay(2000);  // Wait for 2 seconds
  myServo.writeMicroseconds(maxPulseWidth);  // Set servo to maximum position
  delay(1000);  // Delay for stability
  Serial.println("Servo calibrated to maximum position.");
  delay(2000);  // Wait for 2 seconds
  myServo.writeMicroseconds(centralPoint);  // Set servo to central point
  Serial.println("Servo calibrated to central point.");
  delay(2000);  // Wait for 2 seconds
}
