#include "DHT.h"
#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(2, 3, 4, 5, 6,7);
const int fan = 8;
const int DHT11_Sesnor = 9;
SoftwareSerial mySerial(10,11);
const int tempPin = A0;
#define DHTTYPE DHT11
DHT dht(DHT11_Sesnor, DHTTYPE);
int val;
int humudity_value;
int cel ;
int mv;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(fan, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("AKILLI DEPO ");
  lcd.setCursor(0,2);
  lcd.print("IZLEME SISTEMI");
  digitalWrite(fan, HIGH); 
  dht.begin();
}
void loop()
{
  readtemperature();
  readDTH11_Sesnor();
  lcd.clear();
  lcd.print("SICAKLIK:" + String(cel) );
  lcd.setCursor(0,2);
  lcd.print("NEM:" + String(humudity_value) );
  delay(500);

}

void readtemperature()
{
  val = analogRead(tempPin);
   mv = ( val/1024.0)*5000;
   cel = mv/10;
  Serial.print("SICAKLIK = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(500);

  if(cel >30 )
  {
      lcd.clear();
  lcd.print("FAN AKTIF ");
  lcd.setCursor(0,2);
 lcd.print("SOGUTULUYOR ");
  delay(500);
    digitalWrite(fan, LOW);  
  }
  else
  {
    digitalWrite(fan, HIGH); 
  }
}

void readDTH11_Sesnor()
{

  // Reading temperature or humidity takes about 250 milliseconds!
  humudity_value = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humudity_value))
  {
    Serial.println(("DHT SENSORU OKUNAMADI!"));
    return;
  }
  Serial.print((" NEM: "));
  Serial.print(humudity_value);
  Serial.print(("%"));

  Serial.print("\n"); 
  delay(1000); 
}
