#include "drv_ultrasonic.hpp"

bool detectObstacle() {
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



void detect_mountain(bool check_forward, bool check_left, bool check_right, int pin){
  // initialize serial communication:
  Serial.begin(9600);
  Servo myservo; 
  myservo.attach(11);
  const int pingPin = 9;
  myservo.write(90);
 

   //forward
   myservo.write(90);
   delay(250);
   check_forward = detect_obstacle();
   //right
   myservo.write(45);
   delay(250);
   check_right= detect_obstacle();
   //left
   myservo.write(135);
   delay(250);
   check_right= detect_obstacle();

   return;
}