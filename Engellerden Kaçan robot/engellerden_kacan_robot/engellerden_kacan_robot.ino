
#include <Servo.h>     
#include <NewPing.h>      

//l298n kontrol pinleri
const int solmotorileri = 7;
const int solmotorgeri = 6;
const int sagmotorileri= 4;
const int sagmotorgeri = 5;

//ultrasonıc sensor pinleri
#define trig_pin A1 
#define echo_pin A2 

#define maxmesafe 200
boolean goesForward = false; //ileri gitmiyorsa
int mesafe = 100;

NewPing sonar(trig_pin, echo_pin,maxmesafe);
Servo servo_motor;


void setup(){

  pinMode(sagmotorileri, OUTPUT);
  pinMode(solmotorileri, OUTPUT);
  pinMode(solmotorgeri, OUTPUT);
  pinMode(sagmotorgeri, OUTPUT);
  
  servo_motor.attach(10); //servo motor bağlandığı pin

  servo_motor.write(115);
  delay(2000);
  mesafe = readPing();
  delay(100);
  mesafe = readPing();
  delay(100);
  mesafe = readPing();
  delay(100);
  mesafe = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (mesafe <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (mesafe >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    mesafe= readPing();
}

int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int mesafe = readPing();
  delay(100);
  servo_motor.write(115);
  return mesafe;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int mesafe = readPing();
  delay(100);
  servo_motor.write(115);
  return mesafe;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm(); //ping göndererek mesafe ogrenme
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(sagmotorileri, LOW);
  digitalWrite(solmotorileri, LOW);
  digitalWrite(sagmotorgeri, LOW);
  digitalWrite(solmotorgeri, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(solmotorileri, HIGH);
    digitalWrite(sagmotorileri, HIGH);
  
    digitalWrite(solmotorgeri, LOW);
    digitalWrite(sagmotorgeri, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(solmotorgeri, HIGH);
  digitalWrite(sagmotorgeri, HIGH);
  
  digitalWrite(solmotorileri, LOW);
  digitalWrite(sagmotorileri, LOW);
  
}

void turnRight(){

  digitalWrite(solmotorileri, HIGH);
  digitalWrite(sagmotorgeri, HIGH);
  
  digitalWrite(solmotorgeri, LOW);
  digitalWrite(sagmotorileri, LOW);
  
  delay(500);
  
  digitalWrite(solmotorileri, HIGH);
  digitalWrite(sagmotorileri, HIGH);
  
  digitalWrite(solmotorgeri, LOW);
  digitalWrite(sagmotorgeri, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(solmotorileri, HIGH);
  digitalWrite(sagmotorileri, HIGH);
  
  digitalWrite(solmotorileri, LOW);
  digitalWrite(sagmotorgeri, LOW);

  delay(500);
  
  digitalWrite(solmotorileri, HIGH);
  digitalWrite(sagmotorileri, HIGH);
  
  digitalWrite(solmotorgeri, LOW);
  digitalWrite(sagmotorgeri, LOW);
}
