#include <PS4Controller.h>

// AUTHOR : GRECK Vincent
// This code allow a robot to move thanks to funtions.
// - - - - - - - - - - - - - - - - - - - - - - - - - 

// - - - - - - - - - - 
//    MOTOR SECTION
// - - - - - - - - - -
//PWM and motor configuration
// Motor A -> Left
const int motor1Pin1 = 27;
const int motor1Pin2 = 26;
const int enable1Pin = 14;
const int motor1channel = 0;

// Motor B -> Right
const int motor2Pin1 = 25;
const int motor2Pin2 = 33;
const int enable2Pin = 12;
const int motor2channel = 1;

// Setting PWM properties
const int freq = 30000;
const int resolution = 8;

void setup() {

  Serial.begin(115200);
  PS4.begin("7e:03:72:85:07:7a");
  Serial.println("Ready.");

  //Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  ledcSetup(motor1channel, freq, resolution);
  ledcSetup(motor2channel, freq, resolution);
  //Configurate PWM for motors
  ledcAttachPin(enable1Pin, motor1channel);
  ledcAttachPin(enable2Pin, motor2channel);
}

void loop() {

  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
        
    if (PS4.Cross())
    {
      Serial.println("Cross Button");
    }
    if (PS4.Circle())
    {
      Serial.println("Circle Button");
    }
    
    // acceleration command
    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
      // if left acceleration we check the direction
      int mDirection = 1;
      if (PS4.L1()) mDirection = -1;
      controlMotorLeft(mDirection,PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
      // if right acceleration we check the direction
      int mDirection = 1;
      if (PS4.R1()){ 
        Serial.printf("R1 button at %d\n");
        mDirection = -1;
        }
      controlMotorRight(mDirection,PS4.R2Value());
    }

    // delay(20);
  }
  else
  {
    // we dont do anything
    int mDirection = 0;
    controlMotorLeft(mDirection,0);
    controlMotorRight(mDirection,0);
  }
}

// - - - - - - - - - - 
//    FUNK SECTION
// - - - - - - - - - -
// this function control the M1
// motor direction : 1 -> advance -1 go back
// motor speed -> PWM
void controlMotorRight(int motorDirection, int motorSpeed)
{
  // motor direction
  if( motorDirection == 1)
  {
      digitalWrite(motor2Pin1,HIGH);
      digitalWrite(motor2Pin2,LOW);
  }
  if( motorDirection == -1 )
  {
      digitalWrite(motor2Pin1,LOW);
      digitalWrite(motor2Pin2,HIGH);
  }
    ledcWrite(motor2channel, motorSpeed);
}

// this function control the M1
// motor direction : 1 -> advance -1 go back
// motor speed -> PWM
void controlMotorLeft(int motorDirection, int motorSpeed)
{
    // motor direction
  if( motorDirection == 1)
  {
      digitalWrite(motor1Pin1,HIGH);
      digitalWrite(motor1Pin2,LOW);
  }
  if( motorDirection == -1 )
  {
      digitalWrite(motor1Pin1,LOW);
      digitalWrite(motor1Pin2,HIGH);
  }
    ledcWrite(motor1channel, motorSpeed);
}
