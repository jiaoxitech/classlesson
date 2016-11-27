const int GREEN_LED = 11;
const int BLUE_LED = 10;
const int RED_LED = 9;
const int POWER = 8;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(POWER, OUTPUT);
  allLedOff();
  digitalWrite(POWER, HIGH);
}

void loop() {
  delay(100);
  allLedOff();
  // 250 = Low, 0 = High
  analogWrite(BLUE_LED, 250);

  delay(100);
  allLedOff();
  // 250 = Low, 0 = High
  analogWrite(RED_LED, 250);

  delay(100);
  allLedOff();
  // 250 = Low, 0 = High
  analogWrite(GREEN_LED, 250);

}

void allLedOff() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
}

