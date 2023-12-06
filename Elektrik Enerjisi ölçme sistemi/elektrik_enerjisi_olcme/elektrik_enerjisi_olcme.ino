// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

// Measuring Voltage
#include "EmonLib.h"   // enerji izleme kütüphanesi
EnergyMonitor emon1;   // Örnek oluştur

// ACS712 Kullanarak Akım Ölçme
const int Sensor_Pin = A1; //Akım sensörünü Arduino'nun A1'ine bağlayın
int sensitivity = 185; // 5v için 185 kullanılır
int offsetvoltage = 2542; 

void setup()
{
  emon1.voltage(A0,187, 1.7); // Gerilim: giriş pimi, kalibrasyon, faz_kaydırma

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);

  lcd.print("  AC ENERJI OLCER ");
}

void loop()
{
  //************************* voltaj ölçümü ******************************************
  emon1.calcVI(20,2000); // Hepsini hesaplayın. Yarım dalga boyu sayısı (geçişler), zaman aşımı
  int Voltage   = emon1.Vrms;  //Vrms'yi Değişkene çıkarın
  
  lcd.setCursor(0,2);
  lcd.print("V = ");
  lcd.print(Voltage);
  lcd.print("V  ");

  //************************* akım ölçümü ******************************************
  unsigned int temp=0;
  float maxpoint = 0;
  for(int i=0;i<500;i++)
  {
    if(temp = analogRead(Sensor_Pin), temp>maxpoint)
    {
      maxpoint = temp;
    }
  }
  float ADCvalue = maxpoint; 
  double eVoltage = (ADCvalue / 1024.0) * 5000; // mV elde edilir
  double Current = ((eVoltage - offsetvoltage) / sensitivity);
  double AC_Current = ( Current ) / ( sqrt(2) );

  lcd.print("I = ");
  lcd.print(AC_Current,2);
  lcd.print("A          "); //Ölçülecek akımın birimi

  //************************* GÜÇ ölçümü ******************************************
  int Power = (Voltage * AC_Current);
  
  lcd.setCursor(0,3);
  lcd.print("P = ");
  lcd.print(Power);
  lcd.print("W  "); //Ölçülecek gucun birimi
  
  //************************* Enerjiyi Ölçün ******************************************
  long milisec = millis(); // zamanı milisaniye cinsinden hesapla 
  long time=milisec/1000; // milisaniyeyi saniyeye dönüştür
  
  float Energy = (Power*time)/3600; //Watt-sn, 1 saati (3600 saniye) bölerek tekrar Watt-Sa'ya dönüştürülür.

  lcd.print("E = ");
  lcd.print(Energy,1);
  lcd.print("Wh    "); //Ölçülecek akımın birimi
  
  delay(200);
}
