
#include <LiquidCrystal.h>
//servo motor tanımlanması
//Servo servo;
const int rs=12 , en=11 , d4=10 , d5=9 , d6=8 , d7=7;
LiquidCrystal lcd(rs, en , d4, d5, d6, d7);
int ldr1 = A0;
int ldr2 = A1;
int val1;
int val2;
int motor1= 6;
int motor2= 5;
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("GUNES TAKIP");
  delay(1000);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);

}

void loop() {
val1=analogRead(ldr1);
val2=analogRead(ldr2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("LDR1=");
lcd.print(val1);
lcd.setCursor(0,1);
lcd.print("LDR2=");
lcd.print(val2);
delay(100);
if (val1>(val2+40))
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("İLERİ");
  delay(100);
  Serial.println("İLERİ");
  delay(100);
}
else if (val2 >(val1+50))
{
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GERI");
    delay(100);
  Serial.println("GERI");
    delay(100);
}
else 
{
   digitalWrite(6,LOW);
  digitalWrite(5,LOW);
}
}


  
