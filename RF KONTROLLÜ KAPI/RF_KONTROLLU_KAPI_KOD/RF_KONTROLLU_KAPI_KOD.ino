
int openswitch = A5;
int closeswitch = A4;
int led1=11;
int led2=12;
int in1=2;
int in2=4;

void setup() {
  pinMode(openswitch, INPUT);
  pinMode(closeswitch, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
}
void loop() 
{
 int openy=digitalRead(openswitch);
 int closy=digitalRead(closeswitch);

if(openy ==1 && closy == 1)
 {
  digitalWrite(in1,0);
  digitalWrite(in2,0); 
 }
 else if(openy==1)
 {
  digitalWrite(led1,HIGH);
  digitalWrite(in2,1);
  delay(10);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(led1,LOW);
 }
 else if(closy==1)
 {
  digitalWrite(led2,HIGH);
  digitalWrite(in1,1);
  digitalWrite(in2,0); 
  delay(10);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(led2,LOW);
 }
 else
 {
  digitalWrite(in1,0);
  digitalWrite(in2,0);
 }
}
