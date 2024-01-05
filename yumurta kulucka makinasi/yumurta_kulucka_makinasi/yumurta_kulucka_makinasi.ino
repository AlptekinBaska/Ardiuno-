// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  LiquidCrystal lcd(13, 12, 11, 10,  9,  8);

#include <Servo.h>  //Include the Servo Library
Servo myservo;  // create servo object to control a servo

//Assign Names to Pins
const int Temp_Sensor = A0; //Temperature Sensor Pin
#define DHTPIN A1
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
const int Bulb_Pin = 5; //Bulb Pin
const int Fan_Pin = 6; //Fan Pin
const int Servo_Pin = 7; //Servo Motor Pin
int humudity_value;
int pos = 0;   //Servo Position
int State = 1; // Servo State
int Sec = 0;

void setup ()  
{
  // Motor
  pinMode(Bulb_Pin, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(Fan_Pin, OUTPUT);  // Set the pin as OUTPUT 
 dht.begin();
  myservo.attach(Servo_Pin);  // attaches the servo Pin
  myservo.write(2);  //Bring servo to 0 Position

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0); // set the cursor position:
  lcd.print("ARDUNO EGG INCUBATOR"); //Display Message On LCD

  lcd.setCursor(0, 3);
  lcd.print("TIMER: ");
  lcd.print(Sec);
  lcd.print("   ");
}  
void loop ()  
{
  // Temperature Sensing ***********************************
  int S = analogRead(A0);
  int Temp =(S*500)/1022; // Storing value in Degree Celsius
  lcd.setCursor(0, 1);
  lcd.print("T = ");
  lcd.print(Temp);
  lcd.print("'C  ");

  // Humidity Sensing ***********************************
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
  lcd.setCursor(10, 1);
  lcd.print("NEM = ");
  lcd.print(humudity_value);
  lcd.print("%   ");
  
  //Check Temperature
  if(Temp > 29)
  {
    digitalWrite(Bulb_Pin, LOW); // Turn OFF Bulb
    lcd.setCursor(0, 2);
    lcd.print("BULB: OFF ");
  }
  if(Temp < 30)
  {   
    digitalWrite(Bulb_Pin, HIGH); // Turn ON Bulb
    lcd.setCursor(0, 2);
    lcd.print("BULB: ON  ");
  }
  if(humudity_value > 60)
  {
    digitalWrite(Fan_Pin, HIGH); // Turn ON Fan
    lcd.setCursor(10, 2);
    lcd.print("FAN: ON  ");
  }
  if(humudity_value < 60)
  {
    digitalWrite(Fan_Pin, LOW); // Turn OFF Fan
    lcd.setCursor(10, 2);
    lcd.print("FAN: OFF ");
  }

  Sec = Sec + 1;
  lcd.setCursor(0, 3);
  lcd.print("TIMER: ");
  lcd.print(Sec);
  lcd.print("   ");
  
  if(Sec == 5)
  {
    for (pos = 2; pos <= 93; pos += 1) 
    {
      myservo.write(pos); 
      delay(15); 
    }
  }
  if(Sec == 10)
  {
    for (pos = 90; pos >= 2; pos -= 1) 
    {
      myservo.write(pos); 
      delay(15); 
    }
    Sec = 0;
  }
  delay(1000);
}
