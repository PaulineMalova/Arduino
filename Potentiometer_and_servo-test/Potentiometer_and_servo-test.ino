#include <Servo.h>

Servo servopin;
int pinpot = A0;
int Readvalue;
int turn;


void setup() {
  servopin.attach(11);
  pinMode(pinpot, INPUT);

}

void loop() {
  Readvalue = analogRead(pinpot);
  turn = (180./1023.)*Readvalue;
  servopin.write(turn);

}
