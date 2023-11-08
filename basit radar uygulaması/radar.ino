#include<LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trigPin = 9;
int echoPin = 11;
int green = A0;             
int red = A2;
int yellow = A1;
int buzzer = A3;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(yellow,OUTPUT);
  lcd.begin(16,2);

}

void loop()
{
  
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.412;

  if (distance>200)
  {
    lcd.setCursor(0,0);
    lcd.print("ALGILANMADI");
    lcd.setCursor(0,2);
    lcd.print("MESAFE:");
    lcd.print(">200cm");
    digitalWrite(yellow,LOW); 
    digitalWrite(green,HIGH); 
    }
else if(distance<=200 || distance>100)
  {
    lcd.setCursor(0,0);
    lcd.print("NESNE ALGILANDI");
    lcd.setCursor(0,2);
    lcd.print("MESAFE:");
    lcd.print(distance);
    lcd.print("cm");  
      }
if(distance >= 200)
{
  digitalWrite(red,LOW);
 
  }
else if(distance>200 || distance<=100)
{
  lcd.setCursor(0,0);
  lcd.print("NESNE COK YAKIN");
  lcd.setCursor(0,2);
  lcd.print("MESAFE:");
  lcd.print(distance);
  lcd.print("cm");
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW); 
  digitalWrite(buzzer,HIGH);
}
else
{
  digitalWrite(yellow,HIGH);
  delay(100);
  digitalWrite(yellow,LOW);
  delay(100);
  digitalWrite(red,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(green,LOW); 
}
delay(100);
  }
