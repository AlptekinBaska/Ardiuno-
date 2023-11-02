#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
double motor=6;
double motor2=7;
int flamePin = A0;
double dogalgazK =8;
int gasSensor = 9;
int flameValue = 0;


int buzzerPin=11;
int pir=10;
boolean sensorValue = 0;
boolean gasStat   = 0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(flamePin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(pir, INPUT);
  pinMode(gasSensor,INPUT);
  pinMode(dogalgazK,OUTPUT);
  pinMode(motor,OUTPUT);
pinMode(motor2,OUTPUT);
lcd.setCursor(0,0);
lcd.println("AKILLI EV ");
lcd.setCursor(0,1);
lcd.println("SISTEMI ");
delay(500);
lcd.clear();
}

void loop()
{
  
  gasStat = digitalRead(gasSensor);
  delay(50);
 
 sensorValue = digitalRead(pir);
  delay(50);
  flameValue = digitalRead(flamePin);
  delay(100);


 if ((gasStat == 1 ) && (sensorValue == 1)&& (flameValue == HIGH))
 {
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  
    digitalWrite(dogalgazK, HIGH);
    delay(50);
    digitalWrite(motor,1);
    digitalWrite(motor2,0);
    lcd.setCursor(0, 0);
    lcd.print("ALARMMM!! ");
     lcd.setCursor(0, 1);
     lcd.print("YANGIN GAS HIRSIZ!! ");
    delay(100);
    lcd.clear();
 }
 else if ((gasStat == 1 ) && (flameValue == HIGH))
 {
   digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(dogalgazK, HIGH);
    delay(100);
    lcd.clear();
    digitalWrite(motor,1);
    digitalWrite(motor2,0);
   lcd.setCursor(0, 1);
    lcd.print("YANGIN!!! ");
    delay(100);
    lcd.clear();
 }
else  if ((gasStat == 1 )&& (sensorValue == 1))
  {
 digitalWrite(buzzerPin, HIGH);
    delay(100);
  digitalWrite(dogalgazK, LOW);
  lcd.setCursor(0, 1);
    lcd.print("HIRSIZ!! ");

    delay(100);
    lcd.clear();
    
  }
  else if ((sensorValue == 1)&& (flameValue == HIGH))
  {
     digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(dogalgazK,LOW);
    delay(1);
    digitalWrite(motor,HIGH);
    digitalWrite(motor2,LOW);
   lcd.setCursor(0, 1);
    lcd.print("YANGIN!");
    delay(100);
    lcd.clear();
    
  }
  else if (sensorValue == 1)
  {
     digitalWrite(buzzerPin, HIGH);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print(" ALARMM!");
   
    lcd.setCursor(0, 1);
    lcd.print(" HIRSIZ!");
    delay(100);
    lcd.clear();
    
  }
  else if (flameValue == HIGH)
  {
    digitalWrite(dogalgazK,HIGH);
    delay(1);
    digitalWrite(motor,HIGH);
    digitalWrite(motor2,LOW);
      lcd.setCursor(0, 0);
    lcd.print("ALARM!");
    lcd.setCursor(0, 1);
    lcd.print(" YANGIN!");
  
    delay(100);
    lcd.clear();
  }
   else if (gasStat == 1 )
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(dogalgazK,HIGH);
    delay(100);
      lcd.setCursor(0, 0);
     lcd.print(" ALARM!");
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
    lcd.setCursor(0,0);
    lcd.println("EV ");
    lcd.setCursor(0,1);
    lcd.println("GUVENLI ");

    delay(1000);
    lcd.clear();
  }
}
