// include the library code:
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int IR_IN_PIN  = 6;
const int IR_OUT_PIN = 7;

int Capacity = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(IR_IN_PIN, INPUT);
  pinMode(IR_OUT_PIN, INPUT);

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("  CIFT YONLU ");
  lcd.setCursor(0, 1);
  lcd.print("  ZIYARETCI SAYACI");
  lcd.setCursor(0, 2);
  lcd.print("  KAPASİTE: ");
  lcd.setCursor(12, 2);
  lcd.print(Capacity);
  lcd.print("  ");
  lcd.setCursor(0, 3);
  lcd.print("                 ");
}

void loop()
{
  if(digitalRead(IR_IN_PIN) == HIGH && Capacity >0)
  {
    lcd.setCursor(0, 3);
    lcd.print("                 ");
    Capacity = Capacity - 1;
    lcd.setCursor(12, 2);
    lcd.print(Capacity);
    lcd.print("  ");
    delay(1000);
  }
  if(digitalRead(IR_OUT_PIN) == HIGH && Capacity <10)
  {
    lcd.setCursor(0, 3);
    lcd.print("                 ");
    Capacity = Capacity + 1;
    lcd.setCursor(12, 2);
    lcd.print(Capacity);
    lcd.print("  ");
    delay(1000);
  }
  if(Capacity == 0)
  {
    lcd.setCursor(0, 3);
    lcd.print("DAHA FAZLA YER YOK   ");
  }
}
