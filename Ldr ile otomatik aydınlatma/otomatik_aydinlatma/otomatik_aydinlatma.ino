#include <LiquidCrystal.h>
int led7 =7;
int led6 =6;
int led5 =5;
int led4 =4;
int led3 =3;
int led2 =2;
int led1 =1;
int led0 =0;
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
 lcd.begin(16,2);
 pinMode(led0,OUTPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
 pinMode(led6,OUTPUT);
 pinMode(led7,OUTPUT);

}

void loop() {
 int ldr =analogRead (A0);
 int temp=map (ldr,0,1023,0,255);
 lcd.setCursor(0,0);
 lcd.print("ISIGIN ADC DEGERI");
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(10);
  lcd.clear();
  if (temp==2)
  {
     digitalWrite(led0,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
          
  }
   if (temp>2)
  {
    digitalWrite(led7,LOW);      
  }
   if (temp>32)
  {
    digitalWrite(led6,LOW);      
  }
   if (temp>64)
  {
    digitalWrite(led5,LOW);      
  }
   if (temp>96)
  {
    digitalWrite(led4,LOW);      
  }
   if (temp>128)
  {
    digitalWrite(led3,LOW);      
  }
   if (temp>160)
  {
    digitalWrite(led2,LOW);      
  }
   if (temp>192)
  {
    digitalWrite(led1,LOW);      
  }
   if (temp>224)
  {
    digitalWrite(led0,LOW);      
  }
 if (temp<0)
  {
    digitalWrite(led7,HIGH);      
  }
    if (temp<32)
  {
    digitalWrite(led6,HIGH);      
  }
   if (temp<64)
  {
    digitalWrite(led5,HIGH);      
  }
   if (temp<96)
  {
    digitalWrite(led4,HIGH);      
  }
   if (temp<128)
  {
    digitalWrite(led3,HIGH);      
  }
   if (temp<160)
  {
    digitalWrite(led2,HIGH);      
  }
   if (temp<192)
  {
    digitalWrite(led1,HIGH);      
  }
   if (temp<224)
  {
    digitalWrite(led0,HIGH);      
  }

}
