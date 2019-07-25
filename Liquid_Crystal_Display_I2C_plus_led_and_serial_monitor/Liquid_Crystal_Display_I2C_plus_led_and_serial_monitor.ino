#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int numblink;
int ledred = 7;

void setup() {
  lcd.init();
  lcd.begin(16,2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight(); //To power ON the backlight
  //lcd.backlight(); //To power OFF the backlight
  Serial.begin(9600);

  pinMode(ledred, OUTPUT);
  pinMode(ledred, OUTPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("How many?");
  Serial.println("How many blinks?");
  while(Serial.available() == 0) {}
  numblink = Serial.parseInt();
  lcd.setCursor(0,1); //Defining position to write from second row, first column
  lcd.print(numblink);
  
  delay(1000);
  
  lcd.clear();


  for (int j=1; j<=numblink; j++){
    digitalWrite(ledred, HIGH);
    lcd.print("Blink ");
    lcd.print(j);
    delay(500);
    lcd.clear();
    digitalWrite(ledred, LOW);
    delay(500);
  }
  
  

}
