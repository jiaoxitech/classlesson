const int GREEN_LED = 9;
const int YELLOW_LED = 6;
const int RED_LED = 5;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

}

void loop() {
  analogWrite(GREEN_LED, 0);
  analogWrite(YELLOW_LED, 0);
  analogWrite(RED_LED, 255);
  delay(250);
  analogWrite(GREEN_LED, 0);
  analogWrite(YELLOW_LED, 255);
  analogWrite(RED_LED, 0);
  delay(250);  
  analogWrite(GREEN_LED, 255);
  analogWrite(YELLOW_LED, 0);
  analogWrite(RED_LED, 0);
  delay(250);
  analogWrite(GREEN_LED, 0);
  analogWrite(YELLOW_LED, 255);
  analogWrite(RED_LED, 0);
  delay(250); 
}

