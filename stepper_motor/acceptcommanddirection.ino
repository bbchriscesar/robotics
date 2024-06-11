#define STEP_PIN 0 // Connect to RP2040 GPIO 0
#define DIR_PIN 1  // Connect to RP2040 GPIO 1

void setup() {
  // Set the STEP and DIR pins as outputs
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read from the serial port
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming byte

    if (command == 'f') {
      // Set direction to clockwise
      digitalWrite(DIR_PIN, HIGH);
      rotateMotor();
    } else if (command == 'b') {
      // Set direction to counterclockwise
      digitalWrite(DIR_PIN, LOW);
      rotateMotor();
    } else if (command == '0') {
      // Stop the motor
      stopMotor();
    }
  }
}

void rotateMotor() {
  for (int i = 0; i < 500; i++) { // Rotate for a while
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(600); // Adjust this delay to control speed
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(600); // Adjust this delay to control speed
  }
}

void stopMotor() {
  digitalWrite(STEP_PIN, LOW); // Ensure the STEP pin is LOW to stop the motor
}
