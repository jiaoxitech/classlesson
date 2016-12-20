int vccPin = 14;
int trigPin = 15;
int echoPin = 16;
int gndPin = 17;
int ledVcc = 8;
int redLed = 9;
int blueLed = 10;
int greenLed = 11;
long duration, cm;
 
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vccPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
 
  digitalWrite(vccPin, HIGH);
  digitalWrite(trigPin, LOW);
  digitalWrite(gndPin, LOW);

  pinMode(ledVcc, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(ledVcc, HIGH);
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);
  digitalWrite(greenLed, HIGH);  
}
 
void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58.0;

  if ( cm > 100 ) 
  {
    colorGreen();
  } 
  else if ( cm > 50 )
  {
    colorYellow();
  } 
  else 
  {
    colorRed();
  }

  delay(200);
}

void colorRed()
{
  analogWrite(redLed, 200);
  analogWrite(blueLed, 255);
  analogWrite(greenLed, 255);
}

void colorYellow()
{
  analogWrite(redLed, 200);
  analogWrite(blueLed, 255);
  analogWrite(greenLed, 200);
}

void colorGreen()
{
  analogWrite(redLed, 255);
  analogWrite(blueLed, 255);
  analogWrite(greenLed, 200);
}


