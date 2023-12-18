//Assign Names to Pins
const int Speed_Pin  = A0; //Speed Control Pin
const int Clockwise_Pin  = A1; //Clockwise Control Button Pin
const int AClockwise_Pin = A2; //Anti-Clockwise Control Button Pin

//Motor Driver Pins
const int IN1 = 13;
const int IN2 = 12;
const int ENA = 11;
 
void setup ()  
{
  pinMode(Clockwise_Pin,  INPUT_PULLUP);  // Set the pin as INPUT_PULLUP 
  pinMode(AClockwise_Pin, INPUT_PULLUP);  // Set the pin as INPUT_PULLUP 
  pinMode(Speed_Pin, INPUT);  // Set the pin as INPUT
  
  // Motor
  pinMode(IN1, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(IN2, OUTPUT);  // Set the pin as OUTPUT 
  pinMode(ENA, OUTPUT);   //PWM Pin
}  
void loop ()  
{
  int Clockwise  = digitalRead(Clockwise_Pin);  // read the input on pin:
  int AClockwise = digitalRead(AClockwise_Pin);  // read the input on pin:
  int Speed_Value = analogRead(Speed_Pin);  // read the input on pin:
  
  int Motor_Speed = map(Speed_Value, 0,1023, 0,255);
  analogWrite(ENA, Motor_Speed); //PWM Signal to control the speed of motor. (0 - 255)

  if(Clockwise == LOW)
  {
    // Start Motor Clockwise
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  
  else if(AClockwise == LOW)
  {
    // Start Motor Clockwise
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  
  else
  {
    // Start Motor Clockwise
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}
