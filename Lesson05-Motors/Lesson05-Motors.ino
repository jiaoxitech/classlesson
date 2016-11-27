void setup() {
  // Pin 13 is the built in LED. Set the pin to output mode.
  pinMode(13, OUTPUT);
  
  // Connect Pin 3 to A-1A, and set to output mode
  pinMode(3, OUTPUT);
  
  // Connect Pin 4 to A-1B, and set to output mode
  pinMode(4, OUTPUT);  
}

void loop() {
  // Delay for 5000 milliseconds, which is 5 seconds
  delay(5000);

  // Turn on pin 13, to turn on the LED
  digitalWrite(13, HIGH);

  // Turn one pin to High, and the other to Low
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);

  // Wait for 5 seconds
  delay(5000);

  // Turn all pins to off
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  // Wait for 5 seconds
  delay(5000);

  // Turn on pin 13, to turn on the LED
  digitalWrite(13, HIGH);

  // Turn one pin to Low, and the other to High
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);

  // Wait for 5 seconds
  delay(5000);

  // Turn all pins to off
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}
