#include <Arduino.h>
#include "drv_infrared.hpp"
#include "drv_labratory.hpp"
#include "drv_movement.hpp"
#include "drv_ultrasonic.hpp"
#include "pathfinding.hpp"

//pinData sensors[numSensors];
int check = 0;


int find_rock = 0;
int rock_sample = 0;

int lab_beacon = 0;
int lab_wall = 0;

int gripper = 0;
int lab_color_wall = 2;

int ir_bottom_left = 0;
int ir_bottom_right = 0; 



void setup() {
  Serial.begin(9600);
  //setupSensors(sensors);

  // PIN_SETUP
  int labratory_pin = 9;

  int infrared_bottom_left_pin = 5;
  int infrared_bottom_right_pin = 5;
  int infrared_bottom_middle_pin = 5;
  int infrared_forward_pin = 5;

  int ultrasound_pin = 5;

  int movement_pin = 5;
  int gripper_pin = 5;


  //PIN_MODE
  pinMode(labratory_pin, INPUT); // IR_LABRATORY_DETECTOR
  pinMode(infrared_bottom_left_pin, INPUT);
  pinMode(infrared_bottom_right_pin, INPUT);
  pinMode(infrared_bottom_middle_pin, INPUT);
  pinMode(infrared_forward_pin, INPUT);
  pinMode(ultrasound_pin, INPUT);
  pinMode(movement_pin, INPUT);
  pinMode(gripper_pin, INPUT);
}

void checkObstacles(){

  //checkMountain(ultrasound_pin);      //check for mountain

      //check for crater

      //check for border
} 

void loop() {
  //finding the rock loop

  //move 100 cm out of the lab
  //Rotate 90 degrees


  while (find_rock == 0) {
    //drive(3, motorL, motorR);                  //call drive forward

    // call check function
    while (check == 1){
      // call turn function
      // call check function
    }
    check = 0;

      //check for rock sample (rock_sample)
    if(rock_sample == 1){
      find_rock = 1;
      //close gripper
    }
  }

  find_rock = 0;


  while (lab_wall = 0){
    while (lab_beacon = 0){
      //call lab beacon (int lab_beacon)
      //call turn (10 degrees)
    }
  lab_beacon = 0;

  //call check function
  while (check == 1){
    // call turn function
    // call check function
  }
    check = 0;

  //call drive forward

  	  if(lab_beacon == 1){
        //check for lab wall (IR function) (int lab wall)
      }
  }
  lab_wall = 0;


  while(gripper = 0){
    //check for lab wall color (IR function)
  
    //lab_wall_color

    //black = 0 (Right wall)
    //white = 1 (Left wall)

    if(lab_color_wall = 0){
      lab_wall = 1;
      while(lab_wall = 1) {
      // call turn left function (5 degrees)
      // call IR for lab_wall
      }
  
      for(int i = 0; i<32; i++) {
        //need to drive 125 cm infront
        // call drive forward (4cm)
        //call check IR for lab_wall
      if(lab_wall == 1){}
      // call turn left function (5 degrees)
      }
    lab_wall = 0;

    //call rotate 90 degrees

    //need to drive 15cm infront

    //call rotate 90 degrees
    }

    if(lab_color_wall = 1){
      lab_wall = 1;
      while(lab_wall = 1) {
      // call turn right function (5 degrees)
      // call IR for lab_wall
      }
  
      for(int i = 0; i<32; i++) {
      //need to drive 125 cm infront
      // call drive forward (4cm)
      //call check IR for lab_wall
        if(lab_wall == 1){
          // call turn right function (5 degrees)
        }
      }
      lab_wall = 0;

      //call rotate 90 degrees

      //need to drive 15cm infront

      //call rotate 90 degrees
    }

    lab_wall = 0;

    while (lab_wall == 0){
      // drive forward (2 cm)
      //call check IR for lab_wall
      //check IR left and IR right for possible ramp
      if(ir_bottom_left = 1){
        //call turn left function (3 degrees)
      }
      if(ir_bottom_right = 1){
        //call turn right function (3 degrees)
      }
    }
  //call drop sample function

  lab_color_wall = 2;
  }

}

