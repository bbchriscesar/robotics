#include <Servo.h>

Servo myServo; // Create a Servo object to control the servo

void setup() {
  Serial.begin(9600);   // Start the serial communication
  myServo.attach(0);    // Attach the servo to GP0 (Pin 0 on Arduino)
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the command sent via serial
    
    if (command == 'f') {
      myServo.attach(0);          // Attach the servo
      myServo.write(0);           // Full speed forward
      delay(1000);                // Run for 1 second (adjust as needed)
      myServo.detach();           // Detach the servo to avoid jitter
    } 
    else if (command == 'b') {
      myServo.attach(0);          // Attach the servo
      myServo.write(180);         // Full speed backward
      delay(1000);                // Run for 1 second (adjust as needed)
      myServo.detach();           // Detach the servo to avoid jitter
    }
  }
}
