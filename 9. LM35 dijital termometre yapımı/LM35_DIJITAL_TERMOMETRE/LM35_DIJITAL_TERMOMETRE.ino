#include <LiquidCrystal.h>         

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0;                   // A0 is where you connect the sensor
void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  int value = analogRead(inPin); // read the value from the sensor
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 5000; 
  float celsius = millivolts / 10;// DOGRU DEGER GELMEZ ISE float celsius =( millivolts-500) / 10; yazın
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C vucut isisi");
  lcd.setCursor(0,1);
  lcd.print((celsius * 9)/5 + 32); //turning the celsius into fahrehait
  lcd.print(" F TOPRAK BEBEK");
  delay(1000);
}
