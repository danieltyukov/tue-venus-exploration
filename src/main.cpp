#include <Arduino.h>
#include <Servo.h>
#include "drv_movement.hpp"
#include "drv_ultrasound.hpp"
#include "drv_infrared.hpp"
#include "drv_labratory.hpp"

// pins
#define LEFT_MOTOR_PIN 12
#define RIGHT_MOTOR_PIN 13
#define ULTRASOUND_PIN 10
#define GRIPPER_PIN 9
#define BEACON_PIN 8
// #define LAB_BEACON_PIN 3

#define LEFT_IR_DOWN_PIN A0
#define RIGHT_IR_DOWN_PIN A1

#define MIDDLE_IR_DOWN_PIN A2
#define MID_LEFT_IR_DOWN_PIN A4
#define MID_RIGHT_IR_DOWN_PIN A5

// #define MIDDLE_IR_UP_PIN A3
// #define LEFT_IR_UP_PIN A4
// #define RIGHT_IR_UP_PIN A5

Servo motorL; 
Servo motorR; 
Servo gripper;

pinData sensor_left, sensor_right, sensor_front, sensor_front_left, sensor_front_right;

bool block_picked_up = false;

void setup() {
  // pinMode(LAB_BEACON_PIN, OUTPUT);

  motorL.attach(LEFT_MOTOR_PIN);
  motorR.attach(RIGHT_MOTOR_PIN);
  gripper.attach(GRIPPER_PIN);

  // Setup sensors
  setupLeftSensors(&sensor_left, 1);
  setupRightSensors(&sensor_right, 1);
 
  setupMiddleSensorsLeft(&sensor_front_left, 1);
  setupMiddleSensorsRight(&sensor_front_right, 1);
  
  Serial.begin(9600);

  setGripper(true, gripper);
  setGripper(false, gripper);
}

void loop() {
  // block_picked_up = true;

  // if (block_picked_up) {
  //   // move forward until checkRampBorderLeft and checkRampBorderRight
  //   drive(5, motorL, motorR);

  //   if(checkRampBorderLeft(700, sensor_left) && checkRampBorderRight(700, sensor_right)) {
  //       Serial.println("RAMP!!!");
  //       delay(20);
  //       drive(20, motorL, motorR);
  //       delay(20);
  //       setGripper(false, gripper);
  //       drive(-100, motorL, motorR);
  //       block_picked_up = false;
  //   }
  // }

  checkLabDetected(BEACON_PIN);
  // Check for an obstacle
  bool isObstacle = detectObstacle(ULTRASOUND_PIN);

  Serial.println("Left Border");
  Serial.println(sensor_left.average);
  Serial.println("Right Border");
  Serial.println(sensor_right.average);
  Serial.println("Front 1");
  Serial.println(sensor_front.average);
  Serial.println("Front 2");
  Serial.println(sensor_front_left.average);
  Serial.println("Front 3");
  Serial.println(sensor_front_right.average);
  Serial.println(" ");

  if (block_picked_up) {
    while(!checkLabDetected(BEACON_PIN)) {
      turn(25, motorL, motorR);
      delay(20);
    }
  }

  if (!isObstacle) {
    // If no obstacle is detected, move forwardsensor_front_left
    drive(5, motorL, motorR);

    if(checkRampBorderLeft(700, sensor_left) && checkRampBorderRight(700, sensor_right)) {
        Serial.println("RAMP!!!");
        drive(-5, motorL, motorR);
        delay(10);
        turn(75, motorL, motorR);
        delay(10);
    }

    // Check for borders and rock samples
    else if(checkRampBorderLeft(700, sensor_left)) {
        Serial.println("LEFT BORDER!!!");
        // If left border detected, turn right
        turn(75, motorL, motorR);
        delay(10);
    }
    else if(checkRampBorderRight(700, sensor_right)) {
        Serial.println("RIGHT BORDER!!!");
        // If right border detected, turn left
        turn(-75, motorL, motorR);
        delay(10);
    }

    if (!block_picked_up) {
      if(checkRockSample(150, sensor_front)) {
        Serial.println("ROCK SAMPLE!!!");
        // If rock sample detected, grab it
        setGripper(false, gripper);
        delay(20);
        drive(10, motorL, motorR);
        delay(20);
        setGripper(true, gripper);
        delay(100);
        block_picked_up = true;
      }
      else if(checkRockSampleRight(500, sensor_front_right)) {
        Serial.println("ROCK SAMPLE RIGHT!!!");
        // If rock sample detected, grab it
        setGripper(false, gripper);
        delay(20);
        turn(20, motorL, motorR);
        delay(20);
        drive(10, motorL, motorR);
        delay(20);
        setGripper(true, gripper);
        delay(100);
        block_picked_up = true;
      }
      else if(checkRockSampleLeft(500, sensor_front_left)) {
        Serial.println("ROCK SAMPLE LEFT!!!");
        // If rock sample detected, grab it
        setGripper(false, gripper);
        delay(20);
        turn(-20, motorL, motorR);
        delay(20);
        drive(10, motorL, motorR);
        delay(20);
        setGripper(true, gripper);
        delay(100);
        block_picked_up = true;
      }
    }

  } else {
    Serial.println("MOUNTAIN!!!");
    // If an obstacle is detected, stop, then turn right
    drive(-5, motorL, motorR);
    delay(10);
    turn(-100, motorL, motorR); // Turn left
    delay(20);
  }
}