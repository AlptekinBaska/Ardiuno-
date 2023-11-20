#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

const int relay_Pin = 2;
const int buzzer_Pin = 3;
const int ir_Sensor = 10;
const int alcohol_Sensor = 11;
const int vibration_Sensor = 12;


bool ir_status = LOW;
bool alcohol_Status = LOW;
bool vibration_Status = LOW;

void setup() {
  pinMode(relay_Pin, OUTPUT);
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(ir_Sensor, INPUT);
  pinMode(alcohol_Sensor, INPUT);
  pinMode(vibration_Sensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("KAZA ALGILAMA");
  lcd.setCursor(3,2);
  lcd.print("SISTEMI");

}
void loop() {
  ir_status = digitalRead(ir_Sensor);
  delay(100);
  if(ir_status == HIGH)
  {
    digitalWrite(buzzer_Pin, LOW);   
    delay(200);
    lcd.clear();
    lcd.print("KEMER");
    lcd.setCursor(3,2);
    lcd.print("TAKILI");
    delay(200);  
  
    while(1)
    {
      alcohol_Status = digitalRead(alcohol_Sensor);
      delay(100);  
      if(alcohol_Status == HIGH)
      {
       digitalWrite(buzzer_Pin, LOW);   
       delay(200);
       lcd.clear();
       lcd.print("ALKOL");
       lcd.setCursor(3,2);
       lcd.print("ALGILANDI");
       delay(200);  
       digitalWrite(relay_Pin, LOW);   
       delay(200);  
       while(1)  
       {
        lcd.clear();
        lcd.print("MOTOR DURDU");
        delay(200);     
        while(1)
        {   
          vibration_Status = digitalRead(vibration_Sensor);
          delay(100);   
          if(vibration_Status == HIGH)
          {
           lcd.clear();
           lcd.print("KAZA ALGILANDI");
           digitalWrite(relay_Pin,LOW);   
           delay(200);
           lcd.clear();
           lcd.print("MOTOR DURDU");
           delay(200);
         
          
          }
          else
          {
           digitalWrite(buzzer_Pin, LOW);   
           lcd.clear();
           lcd.print("KEMER");
           lcd.setCursor(3,2);
           lcd.print("TAKILII");
           delay(200);  
           digitalWrite(relay_Pin, HIGH);   
           delay(200);
           lcd.clear();
           lcd.print("MOTOR CALISIYOR");
           delay(200); 
          }
        }                 
       }
      }
      else
      {
        lcd.clear();
        lcd.print("KEMER ");
        lcd.setCursor(3,2);
        lcd.print("TAKILI");
        delay(200);  
        digitalWrite(relay_Pin, HIGH);   
        delay(200);              
        digitalWrite(buzzer_Pin, LOW);   
        delay(200);        
        lcd.clear();
         lcd.print("MOTOR CALISIYOR");
         delay(200); 
      }
    }
  } 
  else
  {
    lcd.clear();
    lcd.print("KEMER ");
    lcd.setCursor(3,2);
    lcd.print("TAKINIZ");
    digitalWrite(relay_Pin, LOW);   
    delay(200);              
    digitalWrite(buzzer_Pin, HIGH);   
    delay(200);          
  }
}
