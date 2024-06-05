#define STEP_PIN 0 // Connect to RP2040 GPIO 0
#define DIR_PIN 1  // Connect to RP2040 GPIO 1

void setup() {
  // Set the STEP and DIR pins as outputs
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() {
  // Rotate the motor in one direction
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 1000; i++) { // Rotate for a while
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(2000); // Wait for 2 seconds

  // Rotate the motor in the opposite direction
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 1000; i++) { // Rotate for a while
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(2000); // Wait for 2 seconds
}
