#include <Servo.h>

Servo servopin;
int PIR=6;
int Readvalue;

void setup() {
  servopin.attach(9);
  pinMode(PIR,INPUT);

}

void loop() {
  Readvalue=digitalRead(PIR);
  if (Readvalue==HIGH){
    servopin.write(90);
    delay(1000);
  }
  else{
    servopin.write(0);
    delay(20); 
  }
}

