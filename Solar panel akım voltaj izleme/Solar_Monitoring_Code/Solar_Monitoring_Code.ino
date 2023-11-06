// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

//Measuring Current Using ACS712 
int sensitivity = 185; //  185 5A MODÜL İÇİN 
int adcvalue= 0; 
int offsetvoltage = 2500;  //Sensor Callibration
double Voltage = 0; //voltage measuring 
double ecurrent = 0;// Current measuring 

void setup() 
{
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
 
  lcd.print("PANEL IZLEME");
  lcd.setCursor(0,1);
  lcd.print("SISTEMI");
} 

void loop()
{ 
  // Votage'ı ölçün ***********************************
  //analog pin A1'deki girişi okuyun:
  int sensorValue = analogRead(A1);
  // Analog okumayı (0 - 1023 arasında değişir) bir voltaja (0 - 5V) dönüştürün:
  float vol = (sensorValue * 5.0) / 1023.0;

  float voltage = vol * 5;
  lcd.setCursor(0,2);
  lcd.print("  VOLTAJ = ");
  lcd.print(voltage);
  lcd.print("V");

  // Akımı Ölç ***********************************
  adcvalue = analogRead(A0);//A0 analog pininden değerin okunması
  Voltage = (adcvalue / 1024.0) * 5000; // Size mV kazandırır
  ecurrent = ((Voltage - offsetvoltage) / sensitivity); 
  lcd.setCursor(0,3); 
  lcd.print("  AKIM= "); 
  lcd.print(ecurrent); 
  lcd.print("A"); //Ölçülecek akımın birimi
  delay(2000);
}
