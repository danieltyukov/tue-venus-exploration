#include "drv_movement.hpp"

#include <Servo.h>

int center = 93;

void drive(int distance, Servo motorL, Servo motorR)
{
    // This operation is called a ternary operator. You can look it up if you do not fully understand.
    // It's goal is to set c to either 1 or -1 depending on if the input is negative or not.
    // This is to allow for backwards motion.
    int c = distance < 0 ? -1 : 1;

    // We add a small number to our defined center to let the motor start spinning.
    // This value is multiplied by C to make it go forward or backward.
    // Because the motors oppose each other, one has a negative sign and the other a positive sign.
    motorL.write(center + 5 * c);
    motorR.write(center - 5 * c);

    // After a delay, which is defined by the argument of distance, we return them back to center.
    delay(abs(distance * 1000));
    motorL.write(center);
    motorR.write(center);
}

void turn(int angle, Servo motorL, Servo motorR)
{
    // Same ternary operator condition as in void drive(), same endgoal.
    int c = angle < 0 ? -1 : 1;

    // The operation is the same as for regular driving, but the negative sign is now positive
    // so the wheels spin to turn the robot.
    motorL.write(center + 3 * c);
    motorR.write(center + 3 * c);
    delay(abs(angle * 10));
    motorL.write(center);
    motorR.write(center);
}

void setGripper(bool state, Servo gripper)
{
    // Gripper operation is exceptionally easy, as it is a standard servo.
    gripper.write(state ? 140 : 0);
}
