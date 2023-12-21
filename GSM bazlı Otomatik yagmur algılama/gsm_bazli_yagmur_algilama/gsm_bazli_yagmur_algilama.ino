// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  LiquidCrystal lcd(12, 11, 5, 4,  3,  2);
#include <Wire.h>
//Define the Pin Numbers
const int SENSOR_PIN =6;
const int RLED_PIN = 9;
const int GLED_PIN = 8;
 SoftwareSerial SIM900(7, 10);
void setup ()  
{   
  pinMode (SENSOR_PIN, INPUT); // Set the Sensor pin as INPUT  
  pinMode(RLED_PIN, OUTPUT);  // Set the Red LED pin as OUTPUT 
  pinMode(GLED_PIN, OUTPUT);  // Set the Green LED pin as OUTPUT 
  Serial.begin(9600);
  SIM900.begin(9600);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor position:
  lcd.print("OTOMATIK YAGMUR");
  lcd.setCursor(0,1);
  lcd.print("   ALGILAMA  ");
}  
void loop ()  
{
  int Sensor_Val = digitalRead(SENSOR_PIN);  //get reading from Sensor
  
  if (Sensor_Val == HIGH) //If Sensor Detected the Rain
  {
    digitalWrite(RLED_PIN, HIGH);
    digitalWrite(GLED_PIN, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  YAGMUR  ");
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print("   ALGILANDI");
    delay(100);
    sendSMS();
      delay(500);
  }
  else
  {
   lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" YAGMUR YOK ");
    digitalWrite(RLED_PIN, LOW);
    digitalWrite(GLED_PIN, HIGH);
  }
}
void sendSMS()
{
     SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("YAGMUR ALGILANDI"); // message to send
Serial.println("YAGMUR ALGILANDI");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}
