
int vccPin = 4;
int trigPin = 5;
int echoPin = 6;
int gndPin = 7;
long duration, cm;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vccPin, OUTPUT);
  pinMode(gndPin, OUTPUT);

  digitalWrite(vccPin, HIGH);
  digitalWrite(trigPin, LOW);
  digitalWrite(gndPin, LOW);
}
 
void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58.0;

  Serial.print(cm);
  Serial.println(" cm");
  
  delay(200);
}
