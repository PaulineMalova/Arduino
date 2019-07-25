#include "trials.h"

void Blink1(){
  for (int j=1; j<=5; j++){
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
  }
}

void Blink2(){
  for (int j=1; j<=10; j++){
    digitalWrite(blue, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
    delay(500);
  }
}


