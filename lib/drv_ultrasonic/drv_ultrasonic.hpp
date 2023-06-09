#ifndef DRV_ULTRASONIC_H
#define DRV_ULTRASONIC_H

#include <Arduino.h>
#include <Servo.h>

const int pingPin = 9;

bool detectObstacle();
void detect_mountain(bool check_forward_mountain,bool check_left_mountain,bool check_right_mountain,int pin);

#endif  // DRV_ULTRASONIC_H