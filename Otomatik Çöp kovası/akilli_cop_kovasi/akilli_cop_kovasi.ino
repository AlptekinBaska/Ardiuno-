
// include the library code: 
#include <Servo.h> //library for Servo Motor 

Servo myservo;  // create servo object to control a servo

// defines pins numbers
const int trigPin = 2;
const int echoPin = 3;

// defines variables
long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  myservo.attach(7);  // attaches the servo on Digital pin 7
  myservo.write(3);
}
void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance in cm
  distance = duration*0.034/2;
  
  // Adust the distance Range (2cm to 400cm)
  int D = map(distance, 10, 1095, 2, 400);
  if(D<60)
  {
    myservo.write(93);
    delay(1000);
  }
  else
  {
    myservo.write(3);
  }
}
