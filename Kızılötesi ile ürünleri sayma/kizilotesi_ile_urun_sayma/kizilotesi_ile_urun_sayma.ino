
#include <LiquidCrystal.h> 


LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int IR_PIN  = 6;
const int LED_PIN = 7;

int urun = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("URUN SAYMA");
  lcd.setCursor(0, 1);
  lcd.print("SISTEMI");

  lcd.setCursor(10, 1);
  lcd.print(urun);
  lcd.print("  ");
}

void loop()
{
  if(digitalRead(IR_PIN) == HIGH)
  {
    urun = urun + 1;
    lcd.setCursor(9, 3);
    lcd.print(urun);
    lcd.print("  ");
    digitalWrite(LED_PIN,HIGH);
    delay(200);
    digitalWrite(LED_PIN,LOW);
    delay(800);
  }
}
