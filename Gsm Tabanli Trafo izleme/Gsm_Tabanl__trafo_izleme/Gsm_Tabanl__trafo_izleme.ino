
 
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal.h>
#include<SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SoftwareSerial SIM900(9, 10);
#define DHTPIN 6 
#define DHTTYPE DHT11  // DHT11 sensor is used
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT library
char temperature[] = "Temp = 00.0 C  ";
char humidity[]    = "RH   = 00.0 %  ";


const int trigPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
long duration;
int OilLevel;


int delayTime = 200;

int EarthCurrent;
float SensorReadEarth;
float sensitivity = 0.185;


void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.begin(20, 4);
  dht.begin();
 Serial.begin(9600);
 SIM900.begin(9600);
 delay(100);

Serial.println(" UZAKTAN TRAFO İZLEME");  

lcd.setCursor(2,1);
lcd.print("UZAKTAN");
lcd.setCursor(13,1);
lcd.print("TRAFO ");
lcd.setCursor(4,2);
lcd.print("IZLEME");
lcd.setCursor(0,3);
lcd.print("YAG NEM SICAKLIK");
delay (delayTime);
lcd.clear();

}

void loop() {



//EARTH CURRENT//
SensorReadEarth = analogRead(A1)*(5.0 / 1023.0);     //We read the sensor output  
EarthCurrent = (SensorReadEarth - 2.5)/sensitivity;   //Calculate the current value for earth


// SENSING OIL LEVEL//
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
OilLevel = duration * 0.034 / 2;


//LCD PRINTING//
  

 // Read humidity
  byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  byte Temp = dht.readTemperature();
  if (isnan(RH) || isnan(Temp)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }
  temperature[7]     = Temp / 10 + 48;
  temperature[8]     = Temp % 10 + 48;
  temperature[11]    = 223;
  humidity[7]        = RH / 10 + 48;
  humidity[8]        = RH % 10 + 48;
lcd.setCursor (0 , 0);                       
lcd.print ("NEM:");         // printing “ humidity is : ” on the display
lcd.print(humidity);              // printing humidity on the display
                 
lcd.setCursor ( 0, 1 );                   //  starting the cursor from  top left
lcd.print ("SICAKLIK: ");       // printing the “ Temperature is : ” on the lcd 
 lcd.print(temperature);  

 
  

lcd.setCursor(0,2);
lcd.print("YAG SEVIYESI:");
lcd.setCursor(14,2);
lcd.print(OilLevel);
lcd.setCursor(18,2);
lcd.print("CM");

lcd.setCursor(0,3);
lcd.print("TOPRAK AKIMI:");
lcd.setCursor(14,3);
lcd.print(EarthCurrent,3);
lcd.setCursor(16,3);
lcd.print("A");
delay(600);


 if (Temp >30)
{
lcd_tempPrint();
sms();
 delay(300);
  
  }
if (OilLevel > 900)
{
 lcd_oilLevelFULLPrint();
 sms1();
 
 delay(1000);
  }
  else if (OilLevel < 300)

{
  lcd_oilLevelLOWPrint();
 sms2();
 delay(300);
  }
  if (RH> 30)
{
lcd_RHPrint();
sms4();
 delay(300);
  
  }

   
}


// LCD PRINTING CONDITION//

void lcd_oilLevelFULLPrint()
{
lcd.clear();
lcd.setCursor(1,1);
lcd.clear();                                  //if condition temp for it to print.
lcd.print("YAG TANKI DOLU");  
 
}

void lcd_oilLevelLOWPrint()
{
lcd.clear();
lcd.setCursor(0,2);
lcd.clear();                                  //if condition temp for it to print.
lcd.print("YAG TANKI DUSUK");  

}



void lcd_tempPrint()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.clear();                                  //if condition temp for it to print.
lcd.print("YUKSEK SICAKLIK");   
  
}

void lcd_RHPrint()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.clear();                                  //if condition temp for it to print.
lcd.print("YUKSEK NEM");   
  
}

void sms()

{
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("YUKSEK TRAFO SICAKLIGI"); // message to send
Serial.println("YUKSEK TRAFO SICAKLIGI");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}

void sms1(){
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("YAG TANKI DOLU"); // message to send
Serial.println("YAG TANKI DOLU");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();

}

void sms2(){
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("DUSUK YAG SEVIYESI"); // message to send
Serial.println("DUSUK YAG SEVIYESI");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}

void sms3(){
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("TOPRAK AKIMI HATASI "); // message to send
Serial.println("TOPRAK AKIMI HATASI ");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();

}

void sms4(){
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("YÜKSEK NEM"); // message to send
Serial.println("YÜKSEK NEM");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();

}
