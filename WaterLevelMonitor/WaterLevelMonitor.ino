int sensor_vcc = 3;
int sensor_gnd = 2;
int sensor_sig = A5;

int relay_sig = 8;

int sensor_val;

void setup() {
  pinMode(sensor_vcc, OUTPUT);
  pinMode(sensor_gnd, OUTPUT);
  pinMode(sensor_sig, INPUT);
  pinMode(relay_sig, OUTPUT);
  
  digitalWrite(sensor_vcc, LOW);
  digitalWrite(sensor_gnd, LOW);

  digitalWrite(relay_sig, LOW);
}

void loop() {
  digitalWrite(sensor_vcc, HIGH);
  delay(200);
  sensor_val = analogRead(sensor_sig);
  digitalWrite(sensor_vcc, LOW);
  if (sensor_val < 100) {
    digitalWrite(relay_sig, HIGH);
  } else {
    digitalWrite(relay_sig, LOW);
  }
  delay(5000);
}
