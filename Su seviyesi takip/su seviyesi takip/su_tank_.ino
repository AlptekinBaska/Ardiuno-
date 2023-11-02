#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int az =A3;
int ceyrek=A2;
int yarim=A1;
int full=A0;
int motor=13;
int buzzer =8;
boolean i; 
boolean j; 
boolean k;
boolean l;
void setup() {
 lcd.begin(16,2);
 lcd.print("Tank durumu..");
 pinMode(az,INPUT);
 pinMode(ceyrek,INPUT);
 pinMode(yarim,INPUT);
 pinMode(full,INPUT);
pinMode(motor,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  i = digitalRead(full);
  j = digitalRead(yarim);
  k=digitalRead(ceyrek);
  l=digitalRead(az);
  if (i==1 && j==1 && k==1 && l==1)
{
  lcd.setCursor(0,0);
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print(".");
  lcd.setCursor(5,0);
  lcd.print("TANK FULL");
  lcd.setCursor(0,1);
  lcd.print("MOTOR KAPALI");
  digitalWrite(motor,LOW); 
  digitalWrite(buzzer,HIGH);
  delay(10);  
  digitalWrite(buzzer,HIGH);
}

   else if (i==0 && j==1 && k==1 && l==1)
{
  lcd.setCursor(0,0);
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print("..");
  lcd.setCursor(5,0);
  lcd.print("TANK YARIM");
  lcd.setCursor(0,1);
  lcd.print("MOTOR ACIK");
  digitalWrite(motor,HIGH);  
}
   else if (i==0 && j==0 && k==1 && l==1)
{
  lcd.setCursor(0,0);
  lcd.print(char(219));
  lcd.print(char(219));
  lcd.print("...");
  lcd.setCursor(5,0);
  lcd.print("TANK CEYREK");
  lcd.setCursor(0,1);
  lcd.print("MOTOR ACIK");
  digitalWrite(motor,HIGH);  
}
   else if (i==0 && j==0 && k==0 && l==1)
{
  lcd.setCursor(0,0);
  lcd.print(char(219));
  lcd.setCursor(5,0);
  lcd.print("TANK AZ");
  lcd.print("....");
  lcd.setCursor(0,1);
  lcd.print("MOTOR ACIK");
  digitalWrite(motor,HIGH);  
}
   else if (i==0 && j==0 && k==0 && l==0)
{
  lcd.setCursor(0,0);
  lcd.setCursor(5,0);
  lcd.print("TANK BOS");
  lcd.setCursor(0,1);
  lcd.print("MOTOR ACIK");
  digitalWrite(motor,HIGH);  
}
else
{
  lcd.setCursor(1,0);
  lcd.print("SENSOR");
  lcd.setCursor(0,1);
  lcd.print("HATASI");
}
}
