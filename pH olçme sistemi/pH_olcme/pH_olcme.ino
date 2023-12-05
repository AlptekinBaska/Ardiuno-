#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define SensorPin 0          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Sensör geri bildiriminin ortalama değerini saklayın
float b;
int buf[10],temp;
void setup()
{
  Serial.begin(9600);  
  Serial.println("Ready");    //Test the serial monitor

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(" pH OLCER"); 
  
  delay(2000); 
  lcd.clear();
}
void loop()
{
  for(int i=0;i<10;i++)       //Değeri düzeltmek için sensörden 10 örnek değer alın
  { 
    buf[i]=analogRead(SensorPin); // 10 değeri diziye kaydetme
    delay(10);
  }
  for(int i=0;i<9;i++)        //analogu küçükten büyüğe sıralayın
  {
    for(int j=i+1;j<10;j++) //2 sıralı orneği karşılaştırma
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j]; // 2 ornek aynıysa değişkene atama
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //6  örneğinin ortalama değerini alın
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //analogu milivolta dönüştürün
  phValue=3.5*phValue;     //milivoltu pH değerine dönüştürün

  
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  Serial.println(" "); 

  lcd.setCursor(0,0);
  lcd.print("pH DEGERI :  "); 
  lcd.setCursor(0,12);
  lcd.print(phValue);
  delay(800);
}
