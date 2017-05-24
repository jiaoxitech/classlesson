#include <SoftwareSerial.h>

const int BLUETOOTH_RX = 4;
const int BLUETOOTH_TX = 3;
SoftwareSerial bt ( BLUETOOTH_TX, BLUETOOTH_RX );

const int RELAY1 = 12;
const int RELAY2 = 11;
const int RELAY3 = 10;
const int RELAY4 = 9;
const int RELAY5 = 8;
const int RELAY6 = 7;
const int RELAY7 = 6;
const int RELAY8 = 5;

void setup() {
  bt.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(RELAY5, OUTPUT);
  pinMode(RELAY6, OUTPUT);
  pinMode(RELAY7, OUTPUT);
  pinMode(RELAY8, OUTPUT);
}

void loop() {
  if (bt.available()) {
    char data = bt.read();
      //
      // TODO:
      // These should be numbers, but I don't know how to handle
      // strings. By using a number, we could do something cool:
      // "10" - Relay 1 Off
      // "11" - Relay 1 On
      // Where 0 = Off, and 1 = On.
      // 
      if (data == 'a') {
        digitalWrite(RELAY1, LOW);
        bt.println("RELAY 1 OFF");
      }
      if (data == 'b') {
        digitalWrite(RELAY1, HIGH);
        bt.println("RELAY 1 ON");
      }
      if (data == 'c') {
        digitalWrite(RELAY2, LOW);
        bt.println("RELAY 2 OFF");
      }
      if (data == 'd') {
        digitalWrite(RELAY2, HIGH);
        bt.println("RELAY 2 ON");
      }
      if (data == 'e') {
        digitalWrite(RELAY3, LOW);
        bt.println("RELAY 3 OFF");
      }
      if (data == 'f') {
        digitalWrite(RELAY3, HIGH);
        bt.println("RELAY 3 ON");
      }
      if (data == 'g') {
        digitalWrite(RELAY4, LOW);
        bt.println("RELAY 4 OFF");
      }
      if (data == 'h') {
        digitalWrite(RELAY4, HIGH);
        bt.println("RELAY 4 ON");
      }
      if (data == 'i') {
        digitalWrite(RELAY5, LOW);
        bt.println("RELAY 5 OFF");
      }
      if (data == 'j') {
        digitalWrite(RELAY5, HIGH);
        bt.println("RELAY 5 ON");
      }
      if (data == 'k') {
        digitalWrite(RELAY6, LOW);
        bt.println("RELAY 6 OFF");
      }
      if (data == 'l') {
        digitalWrite(RELAY6, HIGH);
        bt.println("RELAY 6 ON");
      }
      if (data == 'm') {
        digitalWrite(RELAY7, LOW);
        bt.println("RELAY 7 OFF");
      }
      if (data == 'n') {
        digitalWrite(RELAY7, HIGH);
        bt.println("RELAY 7 ON");
      }
      if (data == 'o') {
        digitalWrite(RELAY8, LOW);
        bt.println("RELAY 8 OFF");
      }
      if (data == 'p') {
        digitalWrite(RELAY8, HIGH);
        bt.println("RELAY 8 ON");
      }
  }
}
