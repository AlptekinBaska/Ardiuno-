
#include <LiquidCrystal.h> //LCD Library

#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523 

int temp;
int T_Sensor = A3;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
    pinMode(9,OUTPUT);
    
    val = analogRead(T_Sensor); //sıcaklık sensorunu okuma
    int mv = ( val/1024.0)*5000; 
    cel = mv/10;
    
  
    
    lcd.setCursor(0,0);
    lcd.print("AKILLI SULAMA");
    lcd.setCursor(0,1);
    lcd.print("SISTEMI ");
    delay(500);
   
}

void loop()
{
  
  lcd.clear();
  int Moisture = analogRead(M_Sensor); //NEM SENSORU OKUMASU

 
 if (Moisture> 700 )   // kuru toprak için
  { 
        lcd.setCursor(1,0);
        lcd.print("KURU");
        
        lcd.setCursor(6,0);
        lcd.print("TOPRAK");
         lcd.setCursor(0,1);
         lcd.print("POMPA AKTIF");
        
       
         digitalWrite(13, HIGH);
           tone(Speaker, NOTE_C4, 500); 
           delay(500); 
           tone(Speaker, NOTE_D4, 500);
           delay(500); 
           tone(Speaker, NOTE_E4, 500); 
           delay(500); 
           tone(Speaker, NOTE_F4, 500); 
           delay(500); 
           tone(Speaker, NOTE_G4, 500); 
           digitalWrite(13, LOW);
           delay(500);
         lcd.clear();

        }
   else  if ((digitalRead(W_led)==1)&& cel>(50))
     {
         digitalWrite(13, HIGH);
           tone(Speaker, NOTE_C4, 500); 
           delay(500); 
           tone(Speaker, NOTE_D4, 500);
           delay(500); 
           tone(Speaker, NOTE_E4, 500); 
           delay(500); 
           tone(Speaker, NOTE_F4, 500); 
           delay(500); 
           tone(Speaker, NOTE_G4, 500); 
           delay(500);
         digitalWrite(13, LOW);
         lcd.setCursor(1,0);
         lcd.print("HIGH SICAKLIK");
         lcd.setCursor(0,1);
         lcd.print("POMPA AKTIF");
         delay(500);
         lcd.clear();
     }
  
         
 
    else if (Moisture>= 300 && Moisture<=700) //Nemli Toprak için
    { 
      lcd.setCursor(1,0);
     lcd.print("NEMLI");
    
     lcd.setCursor(7,0);
     lcd.print("TOPRAK");
    
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("POMPA KAPALI"); 
     delay(500);  
     lcd.clear(); 
  }
  else  if (Moisture < 300)  // ISLAK TOPRAK
  { 
    lcd.setCursor(1,0);
     lcd.print("ISLAK");
    
     lcd.setCursor(7,0);
     lcd.print("TOPRAK");
     
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("POMPA KAPALI");
     delay(500);
     lcd.clear();
  }
       else 
       {
         digitalWrite(13, LOW);
         lcd.setCursor(0,1);
         lcd.print("POMPA KAPALI");
           delay(500);
         
           lcd.clear();
       }


}  
