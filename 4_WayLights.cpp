include <Arduino.h>

void setup() {
  // LEDs 1 and 4 (parallel)
  pinMode(2, OUTPUT); // Red
  pinMode(3, OUTPUT); // Green
  pinMode(4, OUTPUT); // Blue
  // LEDs 2 and 3 (parallel)
  pinMode(5, OUTPUT); // Red
  pinMode(6, OUTPUT); // Green
  pinMode(7, OUTPUT); // Blue
  // Switch
  pinMode(A0, INPUT_PULLUP);
  // Turn off unused colors initially
  digitalWrite(4, LOW); // Blue off (LEDs 1 and 4)
  digitalWrite(7, LOW); // Blue off (LEDs 2 and 3)
}

void loop() {
  int switchState = digitalRead(A0); // LOW when pressed
  if (switchState == LOW) { // Button pressed
    // LEDs 1 and 4: Red on, Green off
    digitalWrite(2, HIGH); // Red on (LEDs 1 and 4)
    digitalWrite(3, LOW);  // Green off (LEDs 1 and 4)
    // LEDs 2 and 3: Green on, Red off
    digitalWrite(5, LOW);  // Red off (LEDs 2 and 3)
    digitalWrite(6, HIGH); // Green on (LEDs 2 and 3)
  } else { // Button not pressed
    // LEDs 1 and 4: Red off, Green on
    digitalWrite(2, LOW);  // Red off (LEDs 1 and 4)
    digitalWrite(3, HIGH); // Green on (LEDs 1 and 4)
    // LEDs 2 and 3: Green off, Red on
    digitalWrite(5, HIGH); // Red on (LEDs 2 and 3)
    digitalWrite(6, LOW);  // Green off (LEDs 2 and 3)
  }
}