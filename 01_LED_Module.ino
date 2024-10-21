// Define pins for the LEDs
const int led1 = D1;
const int led2 = D2;
const int led3 = D3;
const int led4 = D4;

void setup() {
  // Set LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Turn LEDs on and off in sequence
  digitalWrite(led1, HIGH); // Turn LED 1 ON
  delay(500);               // Wait for 500ms
  digitalWrite(led1, LOW);  // Turn LED 1 OFF

  digitalWrite(led2, HIGH); // Turn LED 2 ON
  delay(500);               // Wait for 500ms
  digitalWrite(led2, LOW);  // Turn LED 2 OFF

  digitalWrite(led3, HIGH); // Turn LED 3 ON
  delay(500);               // Wait for 500ms
  digitalWrite(led3, LOW);  // Turn LED 3 OFF

  digitalWrite(led4, HIGH); // Turn LED 4 ON
  delay(500);               // Wait for 500ms
  digitalWrite(led4, LOW);  // Turn LED 4 OFF
}
