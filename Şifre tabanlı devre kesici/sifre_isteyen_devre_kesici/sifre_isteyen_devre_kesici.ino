
#include <LiquidCrystal.h> //library for LCD 

// Kütüphaneyi arayüz pinlerinin numaraları ile başlat
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 
 // Tuş takımı için kütüphane kodunu ekleyin
#include <Keypad.h> //Tuş takımı için kütüphane
 
int Lock = A0;    // röle

const byte numRows= 4;  //tuş takımındaki satır sayısı
const byte numCols= 4;    //tuş takımındaki sütun sayısı
 
char keymap[numRows][numCols]= 
{
{'7', '8', '9', '/'}, 
{'4', '5', '6', 'X'}, 
{'1', '2', '3', '-'},
{'C', '0', '=', '+'}
};
 
char keypressed;                 //Anahtarların saklandığı yer çok sık değişiyor
char code[]= {'1','2','3','4'};  //Varsayılan kodu değiştirebilir veya 'n' basamaklı bir kod haline getirebilirsiniz
 
char check1[sizeof(code)];  //Yeni anahtarın saklandığı yer
char check2[sizeof(code)];  //Yeni anahtarın tekrar saklandığı yer, böylece öncekiyle karşılaştırılır
 
short a=0,i=0,s=0,j=0;   //Değişkenler
 
byte rowPins[numRows] = {0,1,2,3}; //tuş takımının satır pin çıkışlarına bağlanın
byte colPins[numCols]= {4,5,6,7}; //tuş takımının sütun pin çıkışlarına bağlanın
 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
 
void setup()
{
  lcd.begin(20, 4); // LCD'nin sütun ve satır sayısını ayarlayın:

  pinMode(Lock, OUTPUT);
}
 
void loop()
{
  keypressed = myKeypad.getKey();  //Sürekli bir tuşa basılmasını beklemek
  if(keypressed == 'C')  // C to open the lock
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter Code");   //Message to show
    ReadCode();               //Call the code function
    if(a==sizeof(code))   //ReadCode işlevi a'ya bir değer atar (kod dizisinin boyutuna sahip olduğunda doğrudur)
    {
      OpenDoor();   //Open lock function
    }
    else
    {
      lcd.clear();
      lcd.print("YANLIS SIFRE!!"); 
      lcd.setCursor(0,1);
      lcd.print("C BAS TEKRAR");
      lcd.setCursor(0,2);
      lcd.print("DENEYIN");
    }
  }

  if(keypressed == 'X')
  {
    lcd.clear();
    digitalWrite(Lock, LOW);
    lcd.print("KESICI KAPALI:");
    lcd.setCursor(0,1);
    lcd.print("ACMAK ICIN C BASIN");
    lcd.setCursor(0,2);
    lcd.print("DEVRE KESILDI!!"); 
  }
}

//Kodu Alma İşlevi
void ReadCode()
{
  lcd.setCursor(0,2);
  lcd.print("and Press '='");
  
  //Tüm değişkenler 0'a ayarlandı
  i=0;
  a=0;
  j=0;
  
  while(keypressed != '=')  //Kullanıcı kodu onaylamak için = tuşuna basar, aksi takdirde kodu saklayabilir
  {
    keypressed = myKeypad.getKey();                         
    if(keypressed != NO_KEY && keypressed != '=' ) //Yazılan char = değilse ve ikisi de "hiçbir şey" değilse
    {
      lcd.setCursor(j,1);  //Bu, bir tuşa basıldığında LCD'ye "*" yazılması için konumu j tarafından kontrol edilir.
      lcd.print("*");
      j++;
      
      if(keypressed == code[i]&& i<sizeof(code)) //yazılan karakter doğruysa a ve i bir sonraki karakteri doğrulamak için artar
      {
        a++;
        i++;
      }
      else
      a--;  //yazılan karakter yanlışsa bir azalma olur ve kodun boyutuna eşit olamazsa []
    }
  }
  
  keypressed = NO_KEY;
}

 //Door Opening function
void OpenDoor()
{
  lcd.clear();
  lcd.print("BASARILI...");
  digitalWrite(Lock,HIGH);
  delay(2000);
  lcd.clear();
  lcd.print("DEVRE KIRICI AKTIF.");
  lcd.setCursor(0,2);
  lcd.print("KAPATMAK ICIN X BASIN");
  lcd.setCursor(0,3);
  lcd.print("KESICI"); 
 }

 
