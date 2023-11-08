#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

#define SO  A0
#define CS  A1
#define SCK A2

#define G_led 8 
#define R_led 9 
#define  motor 13

float temp_c;

void setup(){

pinMode(R_led,OUTPUT);
pinMode(G_led,OUTPUT); 
pinMode(motor,OUTPUT); 

lcd.begin(16, 2); 


}
 
void loop()
{
lcd.setCursor(0,0);
lcd.print("SICAKLIK");
temp_c = Thermocouple_read();
if(isnan(temp_c))
{
delay(1000);
lcd.clear();
loop();
}


lcd.setCursor(0,1);
lcd.print(temp_c,1);
lcd.write(0xdf); // to display °
lcd.print("C  ");



    
if(temp_c>1000){ 
digitalWrite(motor, HIGH);
digitalWrite(G_led, LOW);   
digitalWrite(R_led, HIGH); 
delay(300);
}
else
{  
digitalWrite(G_led, HIGH); 
digitalWrite(R_led, LOW); 
}
  
digitalWrite(motor, LOW);
delay(500); 
}

double Thermocouple_read()
{

uint32_t v_out;
pinMode(CS, OUTPUT);
pinMode(SO, INPUT);
pinMode(SCK, OUTPUT);
digitalWrite(CS, LOW);
delay(1); 
v_out = shiftIn(SO, SCK, MSBFIRST);
v_out <<= 8;
v_out |= shiftIn(SO, SCK, MSBFIRST);
 
digitalWrite(CS, HIGH);
if (v_out & 0x4) 
{ 
//Termokupl bağlantısı kesildi
return NAN; 
}
//Alttaki üç bit (0,1,2) atılan durum bitleridir
v_out >>= 3;
// Geriye kalan bitler 0,25 derece (C) sayımlarının sayısıdır
return v_out*0.2529;
}
