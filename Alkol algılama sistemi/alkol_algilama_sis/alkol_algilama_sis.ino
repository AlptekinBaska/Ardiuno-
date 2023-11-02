#include<SoftwareSerial.h>
#include <LiquidCrystal.h>
#define alcs A0 
#define buzzer 10
float alkol =0;
int red = 13;
int yellow = 12; 
int green = 11; 
SoftwareSerial SIM800l(2,3); // TX and RX respectively
const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  SIM800l.begin(9600);
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(alcs,INPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("ALKOL ALGILAMA");
  lcd.setCursor(4,1);
  lcd.print("SISTEMI");
  delay (1000);
  lcd.clear();
}
void loop() {
       alkol=analogRead(alcs);
       alkol=(alkol/1023)*100;
       lcd.setCursor(0,1);
       lcd.print("YUZDE:"); 
       lcd.setCursor(9,1);
       lcd.print(alkol);
       lcd.print("%");
       
    if (alkol>=45)
    {
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(0,0);
    lcd.print("YUKSEK:");
    lcd.setCursor(7,0);
    lcd.print("DUZEY");
    delay(100);
    lcd.clear();
  if(alkol >=60 && alkol <=62){
  lcd.setCursor(0,0);
  lcd.println("sms yollaniyor.....");
  SIM800l.write("AT+CMGF=1\r\n");
  delay(100);
  SIM800l.write("AT+CMGS=\"+255743712315\"\r\n");
  delay(100);
  SIM800l.write("ALKOL DURUMU: YUKSEK\r\n");
  SIM800l.write("YUZDE:");
  SIM800l.print(alkol);
  SIM800l.write("%\r\n");
  SIM800l.write((char)26);

  
  delay(100);
  lcd.setCursor(0,1); 
  Serial.println("SMS Sent!");
  delay(1000);
}
   }
  else if(alkol>=21)
  {
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(buzzer,LOW);
    lcd.setCursor(0,0);
  lcd.print("ORTA:");
  lcd.setCursor(8,0);
  lcd.print("DUZEY");
  delay(100);
  lcd.clear();
  if(alkol>=35 && alkol <=35.50){
  lcd.setCursor(0,0);
  lcd.println("mesaj yollaniyor.....");
  SIM800l.write("AT+CMGF=1\r\n");
  delay(100);
  SIM800l.write("AT+CMGS=\"+255743712315\"\r\n");
  delay(100);
  SIM800l.write("ALKOL DURUMU: ORTA\r\n");
  SIM800l.write("YZUDE:");
  SIM800l.print(alkol);
  SIM800l.write("%\r\n");
  SIM800l.write((char)26);
  delay(100); 

  lcd.setCursor(0,1); 
  Serial.println("SMS gonderildi!");
  delay(1000);
      }
   }
else
{
  lcd.setCursor(0,0);
  lcd.print("NORMAL:");
  lcd.setCursor(8,0);
  lcd.print("DURUM");
  delay(100);
  lcd.clear();
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(buzzer,LOW);
    
  if(alkol >= 21.00 && alkol <= 21.50)
  {
  lcd.setCursor(0,0);
  lcd.println("mesaj yollaniyor.....");
  SIM800l.write("AT+CMGF=1\r\n");
  delay(100);
  SIM800l.write("AT+CMGS=\"+255743712315\"\r\n");
  delay(100);
  SIM800l.write("ALKOL DURUMU: NORMAL\r\n");
  SIM800l.write("YUZDE:");
  SIM800l.print(alkol);
  SIM800l.write("%\r\n");
  SIM800l.write((char)26);
  delay(100);
  lcd.setCursor(0,1);  
  lcd.println("SMS gonderildi!");
  delay(1000);
    }
  }
}
