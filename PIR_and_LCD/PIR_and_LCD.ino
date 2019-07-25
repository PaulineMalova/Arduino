# include <LiquidCrystal.h>

LiquidCrystal lcd (7,8,9,10,11,12);
int PIR=4;
int Readvalue;

void setup() {
  pinMode(PIR,INPUT);
  lcd.begin(16,2);
  lcd.clear();

}

void loop() {
  lcd.setCursor(0,0);
  Readvalue=digitalRead(PIR);
  if (Readvalue == HIGH) {
    lcd.print("Alert!!");
  }
  else{
    lcd.print("Scanning...");
  }

}
