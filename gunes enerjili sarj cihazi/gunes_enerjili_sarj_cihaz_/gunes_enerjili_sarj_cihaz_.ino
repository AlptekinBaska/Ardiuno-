
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float voltajsensor = 0;
float akimsensor = 0;
float voltajdegeri = 0;
float akimdegeri = 0;
float gucdegeri = 0; 

void setup()
{
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  voltajsensor = analogRead(A0);
  akimsensor = analogRead(A1);
 voltajdegeri = (voltajsensor * 5.0 / 1023.0) * 5;
  akimdegeri = (akimsensor * 5.0 / 1023.0);
  lcd.setCursor(0, 0);
  gucdegeri = voltajdegeri * akimdegeri;

  lcd.print("P=");
  lcd.print(gucdegeri);

  lcd.setCursor(0, 1);
  lcd.print("V=");
  lcd.print(voltajdegeri);
  lcd.print("V I=");
  lcd.print(akimdegeri);
  lcd.print("A");


}
