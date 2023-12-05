// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
#include <SoftwareSerial.h>
// defines pins numbers
const int SensorPin = 2;
const int LEDPin = 7;

void setup() 
{
    
  Serial.begin(9600); //Start the serial connection with the computer
  
  pinMode(SensorPin, INPUT); // Sets the Pin as an Input
  pinMode(LEDPin, OUTPUT); // Sets the Pin as an OUTPUT
  
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor position:
  lcd.print("  SES ALGILAMA ");
  lcd.setCursor(0,1);
  lcd.print("SISTEMI");
  
}
void loop() 
{
  if(digitalRead(SensorPin) == HIGH)
  {
    digitalWrite(LEDPin,HIGH);
    // Prints Message on the LCD
    lcd.setCursor(0,3); 
    lcd.print("  SES ALGILANDI    "); 
    delay(70);
    lcd.setCursor(0,3); 
    lcd.print("SMS YOLLANIYOR  "); 
 
    Serial.println("AT+CMGF=1\r");
    delay(100);
    Serial.println("AT+CMGS=\"+905360680039\"\r");
    delay(100);
    Serial.print("SES ALGILANDI!\r");


    delay(200);
    Serial.println((char)26); // End AT command with a ^Z, ASCII code 26,
  }
  
}
