#include "drv_ultrasonic.hpp"

bool detectObstacle(int ultrasound_pin) {

//DEFINE THE PIN USED

 long duration;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  return (duration < 980); // treshold
}



bool checkMountain(int ultrasound_pin){
  // initialize serial communication:
  Serial.begin(9600);
  Servo myservo; 
  myservo.attach(11);
  const int pingPin = 9;
  myservo.write(90);
 
  
   //forward
   myservo.write(90);
   delay(250);
   bool check_forward = detectObstacle(ultrasound_pin);
  delay(600);
   //right
   myservo.write(45);
   delay(250);
   bool check_right= detectObstacle(ultrasound_pin);
   delay(600);
   //left
   myservo.write(150);
   delay(250);
   bool check_left= detectObstacle(ultrasound_pin);
    delay(600);
    if(check_forward == true || check_left == true || check_right == true){
      return true;
    }
    else{
      return false;
    }
   
}