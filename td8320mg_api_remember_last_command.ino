#include <Servo.h>

Servo myServo;
char lastCommand = '\0';  // Variable to store the last command, initialized to null character

void setup() {
  Serial.begin(9600);
  myServo.attach(0);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Check if the new command is the same as the last one
    if (command == lastCommand) {
      Serial.println("Command ignored: Same as last command.");
    } else {
      if (command == 'f') {
        myServo.attach(0);
        myServo.write(0); // Full speed forward
        delay(1000);
        myServo.detach();
      } else if (command == 'b') {
        myServo.attach(0);
        myServo.write(180); // Full speed backward
        delay(1000);
        myServo.detach();
      }
      
      // Save the new command in the lastCommand variable
      lastCommand = command;
      Serial.println("Command executed.");
    }
  }
}
