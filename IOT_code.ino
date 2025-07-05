#include <NewPing.h>
const int LeftMotorForward   = 7;
const int LeftMotorBackward  = 6;
const int RightMotorForward  = 5;
const int RightMotorBackward = 4;
//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2
#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
void setup(){
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  }
void loop(){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  if (distance <= 20){
    Serial.println(distance);
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    if (distance >= distanceLeft){
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
    distance = readPing();
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}
void moveStop(){
   digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}
void moveForward(){
  if(!goesForward){
 goesForward=true;
 digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }}
void moveBackward(){
 goesForward=false;
 digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  }
void turnRight(){
 digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
   digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 }
void turnLeft(){
 digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
   digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 delay(500);
 digitalWrite(LeftMotorForward, HIGH);
 digitalWrite(RightMotorForward, HIGH);
 digitalWrite(LeftMotorBackward, LOW);
 digitalWrite(RightMotorBackward, LOW);
}
