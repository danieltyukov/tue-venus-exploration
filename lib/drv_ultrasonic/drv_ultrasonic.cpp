#include <Arduino.h>
#include <Servo.h>

int pos = 0;    // variable to store the servo position
int obstacle;   // variable 1 == there is an obstacle; 0 == there is no obstacle
int x = 45;

const int pingPin = 9;

bool detect_obstacle() {
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

Servo myservo;

void setup(){
  // initialize serial communication:
  Serial.begin(9600); 
  myservo.attach(11);
}

void loop(){    
  for (pos = 45; pos <= 135; pos += 1) { // goes from 45 degrees to 135 degrees
    if(pos % 15 == 0){                   // checks every 15 degrees if there is an obstacle in that direction
      myservo.write(pos);  
      delay(250);
      obstacle = detect_obstacle();
      Serial.println(obstacle);
    }
  }

  for (pos = 135; pos >= 45; pos -= 1) { // goes from 135 degrees to 0 degrees
    if(pos % 15 == 0){                   // checks every 15 degrees if there is an obstacle in that direction
      myservo.write(pos);  
      delay(250);
      obstacle = detect_obstacle();
      Serial.println(obstacle);
    }
  }
}
