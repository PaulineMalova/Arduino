#include <Servo.h>

Servo servopin;
int Readvalue;
int pinpot = A0;
int LEDBLUE = 9; 
int LEDGREEN = 10;
int turn;

void setup() {
  servopin.attach(11);
  pinMode(pinpot, INPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);

}

void loop() {
  Readvalue = analogRead(pinpot);
  turn = map(Readvalue,0,1023,0,180);
  servopin.write(turn);
  if (turn >= 0 && turn <=90) {
    digitalWrite(LEDBLUE, HIGH);
    digitalWrite(LEDGREEN, LOW);
  }
  else{
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDBLUE, LOW);
  }

}
