#ifndef DRV_MOVEMENT_H
#define DRV_MOVEMENT_H

#include <Arduino.h>
#include <Servo.h>

#define CENTER 93

void drive(int distance, Servo motorL, Servo motorR);
void turn(int angle, Servo motorL, Servo motorR);
void setGripper(bool state, Servo gripper);

#endif // DRV_MOVEMENT_H