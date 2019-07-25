#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.begin(16,2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight(); //To power ON the backlight
  //lcd.backlight(); //To power OFF the backlight
}

void loop() {
  lcd.setCursor(0,0); //Defining position to write from second row, first column
  lcd.print(" Tech Maker "); //You can write 16 characters per line
  delay(1000); //Delay used to give a dynamic effect
  lcd.setCursor(0,1); //Defining position to write from second row, first column
  lcd.print("Like | Share");
  delay(8000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" SUBSCRIBE ");
  lcd.setCursor(0,1);
  lcd.print(" TECH MAKER ");
  delay(8000);

}
