const int buton = 10;

const int relay = 13;
int bstate = 0;

void setup() {
  pinMode(relay,OUTPUT);
   pinMode(buton,INPUT);

}

void loop() {
  bstate = digitalRead(buton);

  if (bstate==LOW)
  {
    digitalWrite (relay,HIGH);
  }
  else 
  {
    digitalWrite (relay,LOW);
  }
   
}
