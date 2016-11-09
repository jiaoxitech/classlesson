const int GREEN_LED = 9;
const int YELLOW_LED = 6;
const int RED_LED = 5;

int x = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  analogWrite(GREEN_LED, x);
  analogWrite(YELLOW_LED, x);
  analogWrite(RED_LED, x);

  if ( x == 200 ) {
    x = 0;
  } else {
    x = x + 1;
  }
  
  delay(10);
}
