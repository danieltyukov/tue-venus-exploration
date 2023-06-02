#ifndef DRV_OBSTACLE_H
#define DRV_OBSTACLE_H

#include <Arduino.h>
#include <Servo.h>

const int pingPin = 9;

bool detectObstacle();

#endif  // DRV_OBSTACLE_H