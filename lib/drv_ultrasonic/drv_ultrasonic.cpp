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



void checkMountain(int ultrasound_pin){
  // initialize serial communication:
  Serial.begin(9600);
  Servo myservo; 
  myservo.attach(11);
  const int pingPin = 9;
  myservo.write(90);
 

   //forward
   myservo.write(90);
   delay(250);
   //check_forward = detectObstacle(ultrasound_pin);
   //right
   myservo.write(45);
   delay(250);
   //check_right= detectObstacle(ultrasound_pin);
   //left
   myservo.write(135);
   delay(250);
   //check_left= detectObstacle(ultrasound_pin);

   return;
}