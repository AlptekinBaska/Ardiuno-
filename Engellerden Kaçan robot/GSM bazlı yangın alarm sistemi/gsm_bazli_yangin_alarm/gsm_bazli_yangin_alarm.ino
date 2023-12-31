// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SoftwareSerial.h>
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  LiquidCrystal lcd(13, 12, 11, 10,  9,  8);
  SoftwareSerial SIM900(4, 5);
const int SENSOR_PIN = 2;
const int BUZZER_PIN = 7;
const int LED_PIN = 6;
const int motor = 3;
void setup ()  
{   
  pinMode (SENSOR_PIN, INPUT); // Set the Sensor pin as INPUT  
  pinMode(BUZZER_PIN, OUTPUT);  // Set the BUZZER pin as OUTPUT 
  pinMode(LED_PIN, OUTPUT);  // Set the LED pin as OUTPUT 
  pinMode(motor, OUTPUT);
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor position:
  lcd.print(" YANGIN    ");
  lcd.setCursor(0,1);
  lcd.print(" ALARM SISTEMI  ");
}  
void loop ()  
{
   Serial.begin(9600);
  SIM900.begin(9600);
  int Sensor_Val = digitalRead(SENSOR_PIN);  //get reading from Sensor
  if (Sensor_Val == HIGH) //If Sensor Detected the Fire
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);
     digitalWrite(motor, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("  YANGIN VAR");
    lcd.setCursor(0, 2);
    lcd.print("SONDURME CALISIYOR");
    sendSMS();
  }
  else
  {
    lcd.setCursor(0, 3);
    lcd.print("YANGIN YOK");
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(motor,LOW);
  }
}
void sendSMS()
{
     SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+xxxxxxxxxxxx\"");// recipient's mobile number
SIM900.println("YANGIN ALGILANDI"); // message to send
Serial.println("YANGIN ALGILANDI");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}
