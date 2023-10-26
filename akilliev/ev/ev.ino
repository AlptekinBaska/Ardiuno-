#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
double motor=6;
double motor2=7;
const int lm35 = A0;
double dogalgazK =8;
int gasSensor = 9;
float voltaj_deger = 0;
float sicaklik = 0;
int gelen_veri = 0;
int buzzerPin=11;
int pir = 10;
boolean sensorValue = 0;
boolean gasStat   = 0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(lm35, INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(pir, INPUT);
  pinMode(gasSensor,INPUT);
  pinMode(dogalgazK,OUTPUT);
  pinMode(motor,OUTPUT);
pinMode(motor2,OUTPUT);
}

void loop()
{
  
  gasStat = digitalRead(gasSensor);
  delay(50);
  gelen_veri = analogRead(lm35);
   delay(50);
  voltaj_deger = (gelen_veri / 1023.0) * 5000;
  sicaklik = voltaj_deger / 10.0; 
 sensorValue = digitalRead(pir);
  delay(100);


 if ((gasStat == 1 ) && (sensorValue == 1)&& ((sicaklik))>(50))
 {
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  
    digitalWrite(dogalgazK, HIGH);
    delay(50);
    digitalWrite(motor,1);
    digitalWrite(motor2,0);
    lcd.setCursor(0, 1);
    lcd.print("ALARMMM!! ");
    
    delay(100);
    lcd.clear();
 }
 else if ((gasStat == 1 ) && ((sicaklik))>(50))
 {
   digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(dogalgazK, HIGH);
    delay(100);
    lcd.clear();
    digitalWrite(motor,1);
    digitalWrite(motor2,0);
   lcd.setCursor(0, 1);
    lcd.print("SICAKLIK GAZ!!! ");
    delay(100);
    lcd.clear();
 }
else  if ((gasStat == 1 )&& (sensorValue == 1))
  {
 digitalWrite(buzzerPin, HIGH);
    delay(100);
  digitalWrite(dogalgazK, LOW);
  lcd.setCursor(0, 1);
    lcd.print("GAZ HIRSIZ!! ");

    delay(100);
    lcd.clear();
    
  }
  else if ((sensorValue == 1)&& ((sicaklik)>(50)))
  {
     digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(dogalgazK,LOW);
    delay(1);
    digitalWrite(motor,HIGH);
    digitalWrite(motor2,LOW);
   lcd.setCursor(0, 1);
    lcd.print("SICAKLIK HIRSIZ!");
    delay(100);
    lcd.clear();
    
  }
  else if (sensorValue == 1)
  {
     digitalWrite(buzzerPin, HIGH);
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print(" HIRSIZ!");
    delay(100);
    lcd.clear();
    
  }
  else if ((sicaklik)>(50))
  {
    digitalWrite(dogalgazK,HIGH);
    delay(1);
    digitalWrite(motor,HIGH);
    digitalWrite(motor2,LOW);
    lcd.setCursor(0, 1);
    lcd.print(" SICAKLIK!");
  
    delay(100);
    lcd.clear();
  }
   else if (gasStat == 1 )
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(dogalgazK,HIGH);
    delay(100);
     lcd.setCursor(0, 1);
    lcd.print(" GAZ!");
  
    delay(100);
    lcd.clear();
  }
  else 
  {
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(dogalgazK, LOW);
    delay(100);
    lcd.clear();
    digitalWrite(motor,LOW);
    digitalWrite(motor2,LOW);
    lcd.print("sicaklik = ");
  lcd.setCursor(0, 1);
  lcd.print(sicaklik);
  lcd.print(" derece");

    delay(1000);
    lcd.clear();
  }
}
