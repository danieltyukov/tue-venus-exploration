#ifndef DRV_ULTRASONIC_H
#define DRV_ULTRASONIC_H

#include <Arduino.h>
#include <Servo.h>

const int pingPin = 9;

bool detectObstacle();
bool checkMountain(int ultrasound_pin);

#endif  // DRV_ULTRASONIC_H