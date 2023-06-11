#include <Arduino.h>
#include "drv_infrared.hpp"
#include "drv_labratory.hpp"
#include "drv_movement.hpp"
#include "drv_ultrasonic.hpp"
#include "pathfinding.hpp"

//pinData sensors[numSensors];
bool check = false;


bool find_rock;
bool rock_sample;

bool lab_beacon = false;
bool lab_wall = false;

int gripper = 0;
int lab_color_wall = 2;

int ir_bottom_left = 0;
int ir_bottom_right = 0; 

// PIN_SETUP
  int labratory_pin = 9;

  int infrared_bottom_left_pin = 5;
  int infrared_bottom_right_pin = 5;
  int infrared_bottom_middle_pin = 5;
  int infrared_forward_pin = 5;

  int ultrasound_pin = 5;

  int movement_pin = 5;
  int gripper_pin = 5;

  Servo motorL;
  Servo motorR;
  Servo gripperServo;

void setup() {
  Serial.begin(9600);
  //setupSensors(sensors);

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

bool checkObstacles(int ultrasound_pin, int infrared_bottom_left_pin , int infrared_bottom_right_pin, int infrared_bottom_middle_pin){
    bool checkMountain;
    bool checkCrater;
    bool checkBorder;

    //checkMountain = checkMountain(ultrasound_pin);      //check for mountain  
  	
    // if (checkMountain == 1){
    //   //turn right
    // }

    // if (checkMountain == 2){
    //   //turn left
    // }

    //checkCrater = checkCrater(infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);     //check for crater
    //checkBorder = checkBorder(infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);     //check for border

  if(checkCrater == false && checkBorder == false && checkMountain == false){
    return 0;
  }

  else{
    return 1; 
  }
} 

void loop() {
  //finding the rock loop

  //move 100 cm out of the lab
  //Rotate 90 degrees


  while (find_rock == false) {
    drive(3, motorL, motorR);                  //call drive forward

    check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);

    while (check == true){
      turn(30, motorL, motorR);
      check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);
    }
    check = false;

    rock_sample = checkRockSample(infrared_bottom_middle_pin);
    if(rock_sample == true){
      find_rock = true;
      setGripper(1, gripperServo); //close gripper
    }
  }

  find_rock = false;


  while (lab_wall = false){
    while (lab_beacon = false){
      //call lab beacon (int lab_beacon)
      //call turn (10 degrees)
    }
    lab_beacon = false;

    check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);

    while (check == 1){
      turn(30, motorL, motorR);
      check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);
    }
    check = false;

  drive(3, motorL, motorR);

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

