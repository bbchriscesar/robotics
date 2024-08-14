#include <Arduino.h>
#include <Stepper.h>

// Accepts a command via serial to rotate the stepper motor. 
// If limit switch is pressed then rotation will stop immediately.
// Setup: RP2040, 28BYJ-48, 5v limit switch, breadboard, external power supply 5v 2A

// Constants for the stepper motor
const int stepsPerRevolution = 2048; // Adjust if necessary

// Pin assignments
const int in1Pin = 2;
const int in2Pin = 3;
const int in3Pin = 4;
const int in4Pin = 5;
const int limitSwitchPin = 6;

// Initialize the stepper library
Stepper myStepper(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin);

// Variables to control motor direction and state
char currentCommand = ' ';
bool motorRunning = false;

void setup() {
  // Set up the stepper motor speed
  myStepper.setSpeed(10); // Adjust speed as needed

  // Set the limit switch pin as input with a pull-up resistor
  pinMode(limitSwitchPin, INPUT_PULLUP);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if there is a new command from the serial port
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'f' || command == 'b') {
      currentCommand = command;
      motorRunning = true;
    }
  }

  // Check if the limit switch is pressed
  if (digitalRead(limitSwitchPin) == LOW) {
    motorRunning = false;
  }

  // Control the motor based on the current command and limit switch state
  if (motorRunning) {
    if (currentCommand == 'f') {
      myStepper.step(1);  // Move the motor one step forward
    } else if (currentCommand == 'b') {
      myStepper.step(-1); // Move the motor one step backward
    }
  }
}
