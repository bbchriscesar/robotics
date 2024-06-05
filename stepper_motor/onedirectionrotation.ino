#define STEP_PIN 0 // Connect to RP2040 GPIO 0
#define DIR_PIN 1  // Connect to RP2040 GPIO 1

void setup() {
  // Set the STEP and DIR pins as outputs
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Set the initial direction
  digitalWrite(DIR_PIN, HIGH); // Rotate in one direction
}

void loop() {
  // Rotate the motor by sending pulses to the STEP pin
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(1000); // Adjust this delay to control speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(1000); // Adjust this delay to control speed
}
