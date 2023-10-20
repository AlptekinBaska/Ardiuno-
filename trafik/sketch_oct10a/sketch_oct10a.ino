
int kirmizi=13;
int sari=12;
int yesil=11;
const int REDTIME=5000;
const int YELLOWTIME=1000;
const int GREENTIME=4000;
void setup() {
  Serial.begin(9600);
  pinMode(kirmizi,OUTPUT);
  pinMode(sari,OUTPUT);
  pinMode(yesil,OUTPUT);
  digitalWrite(kirmizi,LOW);
  digitalWrite(sari,LOW);
  digitalWrite(yesil,LOW);

}

void loop() {
  Serial.println("Bekle");
  digitalWrite(kirmizi,HIGH);
  delay(REDTIME);
  digitalWrite(kirmizi,LOW);

  Serial.println("HAZIR OL");
  digitalWrite(sari,HIGH);
  delay(YELLOWTIME);
  digitalWrite(sari,LOW);
  
  Serial.println("geç");
  digitalWrite(yesil,HIGH);
  delay(GREENTIME);
  digitalWrite(yesil,LOW);

}
