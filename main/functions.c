#include "functions.h"

void Blink() {
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  delay(500);

   digitalWrite(blue, HIGH);
  delay(1000);
  digitalWrite(blue, LOW);
  delay(500);

  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(500);
}

