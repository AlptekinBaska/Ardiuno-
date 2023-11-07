# include "LiquidCrystal.h"         

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ana1=A0;
int temp=0;  
float derece=0;
float voltaj=0;

void setup() {
  Serial.begin(9600);

  lcd.begin (16,2);                                  
      
  

                                        
}
void loop() {
  temp = analogRead(ana1);                                                   
  voltaj=1.4829 * temp - 447.44;
  //derece =voltaj/0.005;
  lcd.print("SICAKLIK: ");
  lcd.print(voltaj);
  lcd.println("*C");
  delay(500);
  lcd.clear();                                          
}
