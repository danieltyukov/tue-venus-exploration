#include <Arduino.h>
#include "drv_infrared.hpp"
#include "drv_labratory.hpp"
#include "drv_movement.hpp"
#include "drv_ultrasonic.hpp"
#include "pathfinding.hpp"

//pinData sensors[numSensors];
bool check = false;


bool find_rock = false;
bool rock_sample = false;

bool lab_beacon = false;
bool lab_wall = false;

bool gripper = false;
bool lab_color_wall = false;

bool ramp_left = false;
bool ramp_right = false;

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
    //if (checkMountain == 1){
    //   //turn right
    // }

    // if (checkMountain == 2){
    //   //turn left
    // }
  return (checkCrater(infrared_bottom_left_pin, infrared_bottom_middle_pin, infrared_bottom_right_pin) || checkBorder(infrared_bottom_left_pin, infrared_bottom_middle_pin, infrared_bottom_right_pin) || checkMountain(ultrasound_pin));
} 

void loop() {
  //finding the rock loop  

  drive(-100, motorL, motorR);   //move 100 cm out of the lab
  turn(90, motorL, motorR);      //Rotate 90 degrees


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
      gripper = false;
    }
  }

  find_rock = false;

  while (lab_wall = false){
    while (lab_beacon = false){
      lab_beacon = checkLabDetected(ultrasound_pin);    //call lab beacon (int lab_beacon)
      turn(30, motorL, motorR);   //call turn (10 degrees)
    }
    lab_beacon = false;

    check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);

    while (check == true){
      turn(30, motorL, motorR);
      check = checkObstacles(ultrasound_pin, infrared_bottom_left_pin , infrared_bottom_right_pin, infrared_bottom_middle_pin);
    }
    check = false;

    drive(3, motorL, motorR);

  	  if(lab_beacon == true){
        lab_wall = checkLabWall(infrared_forward_pin);    //check for lab wall (IR function) (int lab wall)
      }
  }
  lab_wall = false;

  while(gripper = false){
    lab_color_wall = checkLabColor(infrared_forward_pin);//check for lab wall color (IR function)
  
    //lab_wall_color

    //black = false (Right wall)
    //white = true (Left wall)

    if(lab_color_wall = false){
      lab_wall = true;
      while(lab_wall = true) {
        turn(5, motorL, motorR);     // call turn left function (5 degrees)
        checkLabWall(infrared_forward_pin);   // call IR for lab_wall
      }

      for(int i = 0; i<32; i++) {
        //need to drive 125 cm infront
        drive(4, motorL, motorR);   // call drive forward (4cm)
        lab_wall = checkLabWall(infrared_forward_pin);   //call check IR for lab_wall
        if(lab_wall == true){
          turn(5, motorL, motorR);  // call turn left function (5 degrees)
        }
        lab_wall = false;
      }
    
      turn(90, motorL, motorR);     //call rotate 90 degrees right
      drive(15, motorL, motorR);   //need to drive 15cm infront
      turn(90, motorL, motorR);    //call rotate 90 degrees right
    }

    if(lab_color_wall = true){
      lab_wall = true;
      while(lab_wall = true) {
        turn(5, motorL, motorR);   // call turn right function (5 degrees)
        lab_wall = checkLabWall(infrared_forward_pin);   // call IR for lab_wall
      }
  
      for(int i = 0; i<32; i++) {
      //need to drive 125 cm infront
      drive(4, motorL, motorR);   // call drive forward (4cm)
      lab_wall = checkLabWall(infrared_forward_pin);    //call check IR for lab_wall
        if(lab_wall == true){
          turn(5, motorL, motorR);    // call turn right function (5 degrees)
        }
      }
      lab_wall = false;

      turn(-90, motorL, motorR);   //call rotate 90 degrees left
      drive(4, motorL, motorR);   //need to drive 15cm infront
      turn(-90, motorL, motorR);   //call rotate 90 degrees left
    }


    lab_wall = false;

    while (lab_wall == false){
      drive(2, motorL, motorR);   // drive forward (2 cm)
      lab_wall = checkLabWall(infrared_forward_pin);    //call check IR for lab_wall
      //check IR left and IR right for possible ramp
      ramp_left = checkRampBorderLeft(infrared_bottom_left_pin);
      ramp_right = checkRampBorderRight(infrared_bottom_right_pin);
      if(ramp_left = true){
        turn(3, motorL, motorR);   //call turn left function (3 degrees)
      }
      if(ramp_right = true){
        turn(3, motorL, motorR);   //call turn right function (3 degrees)
      }
    }
    setGripper(1, gripperServo);    //call drop sample function
    gripper = true;
  }

}

