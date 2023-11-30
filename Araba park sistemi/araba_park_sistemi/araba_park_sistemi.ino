#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
#define sensor1 8
#define sensor2 9
#define sensor3 10
#define sensor4 11
#define closegate 6
#define opengate 7
byte park [8] // dolu park alanı icın ozel karakter
{
  0b10001,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  0b10001,
};
byte npark [8]// boş park alanı icın ozel karakter
{
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
};
int pA1,pA2,pA3,pA4;

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(closegate, OUTPUT);
  pinMode(opengate, OUTPUT);
  lcd.createChar(0,park);
  lcd.createChar(1,npark);
  lcd.begin(16, 2);

  
  lcd.print("KAPI ACILIYOR:"); 
  digitalWrite(opengate,HIGH);
  digitalWrite(closegate,LOW);
  delay(200);
   digitalWrite(opengate,LOW);
  digitalWrite(closegate,LOW);
  lcd.clear();
}


void loop() {
   lcd.setCursor(0,0);
   lcd.print("PA1 PA2 PA3 PA4");
   pA1=digitalRead(sensor1);
   pA2=digitalRead(sensor2);
   pA3=digitalRead(sensor3);
   pA4=digitalRead(sensor4);
   if (pA1==1) 
   {
   lcd.setCursor(1,1);
   lcd.write(byte(1));
   }
   else 
   {
    lcd.setCursor(1,1);
     lcd.write(byte(0));
   }
   
     if (pA1==2) 
   {
   lcd.setCursor(5,1);
   lcd.write(byte(1));
   }
   else 
   {
    lcd.setCursor(5,1);
     lcd.write(byte(0));
   }
   
     if (pA1==3) 
   {
   lcd.setCursor(9,1);
   lcd.write(byte(1));
   }
   else 
   {
    lcd.setCursor(9,1);
     lcd.write(byte(0));
   }
   
     if (pA1==4) 
   {
   lcd.setCursor(13,1);
   lcd.write(byte(1));
   }
   else 
   {
    lcd.setCursor(13,1);
     lcd.write(byte(0));
   }
   if (pA1==0 && pA2==0 && pA3==0 && pA4==0)
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("KAPI KAPANIYOR:"); 
     digitalWrite(opengate,LOW);
     digitalWrite(closegate,HIGH);
     delay(200);
     digitalWrite(opengate,LOW);
     digitalWrite(closegate,LOW);
       lcd.setCursor(0,1);
       lcd.print("PARK DOLU:"); 
}
   }
 
