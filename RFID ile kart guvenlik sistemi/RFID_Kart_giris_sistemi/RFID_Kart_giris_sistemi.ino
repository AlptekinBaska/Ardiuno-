// include the library code:
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int RedlED = 5;
const int GreenlED = 6;
const int Buzzer = 7;

int count = 0;
char c;
String id;

int wait = 5000;

void setup()
{
  Serial.begin(9600);
  pinMode(RedlED, OUTPUT);
  pinMode(GreenlED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.println("KART OKUTUNUZ");

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("RFID KART");
  lcd.setCursor(0, 1);
  lcd.print(" OKUMA SISTEMI");
  lcd.setCursor(0, 2);
  lcd.print(" KART:   ");
  lcd.setCursor(0, 3);
  lcd.print(" ISMI:   ");
}

void loop()
{
  while (Serial.available() > 0)
  {
    c = Serial.read();
    count++;
    id += c;
    if (count == 12)
    {
      Serial.print(id);
      //break;

      if (id == "E280689401A9")
      {
        Serial.println("GECERlI KART");
        lcd.setCursor(0, 2);
        lcd.print(" KART: GECERLI   ");
        lcd.setCursor(0, 3);
        lcd.print(" ISIM: A KISISI ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" KART:           ");
        lcd.setCursor(0, 3);
        lcd.print(" ISIM:           ");
      }

      else if (id == "E2000019060C")
      {
         Serial.println("GECERlI KART");
        lcd.setCursor(0, 2);
        lcd.print(" KART: GECERLI   ");
        lcd.setCursor(0, 3);
        
        lcd.print(" NAME: B KISISI  ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" KART:           ");
        lcd.setCursor(0, 3);
        lcd.print(" ISIM:           ");
      }

      else if (id == "G46RD9V40F3A")
      {
         Serial.println("GECERlI KART");
        lcd.setCursor(0, 2);
        lcd.print(" KART: GECERLI   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: C KISISI   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" KART:           ");
        lcd.setCursor(0, 3);
        lcd.print(" ISIM:           ");
      }

 

      else
      {
        Serial.println("GECERSIZ KART");
        lcd.setCursor(0, 2);
        lcd.print(" KART GECERSIZ  ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: BILINMIYOR");
        digitalWrite(RedlED, HIGH);
        digitalWrite(Buzzer, HIGH);
        delay(500);
        digitalWrite(Buzzer, LOW);
        delay(4000);
        digitalWrite(RedlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" KART:           ");
        lcd.setCursor(0, 3);
        lcd.print(" ISIM:           ");
      }
    }
  }
  count = 0;
  id = "";
  delay(500);
}
