#include "trials.h"

void setup(){
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  servopin.attach(8);
}

void loop(){
  Blink1;
  Turn1;
  Blink2;
  Turn2;
}

//#include <Servo.h>
//
//int red = 5;
//int blue = 7;
//Servo servopin;
//
//void setup() {
//  pinMode(red, OUTPUT);
//  pinMode(blue, OUTPUT);
//  servopin.attach(8);
//
//}
//
//void loop() {
//  for (int j=1; j<=5; j++){
//    digitalWrite(red, HIGH);
//    delay(500);
//    digitalWrite(red, LOW);
//    delay(500);
//    servopin.write(90);
//  }
//
//  for (int j=1; j<=10; j++){
//    digitalWrite(blue, HIGH);
//    delay(500);
//    digitalWrite(blue, LOW);
//    delay(500);
//    servopin.write(0);
//  }
//
//}
