#include "drv_infrared.hpp"

void setupBlackSensors(pinData sensors[], int numSensors) {
  // Initialize sensor objects
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A0 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}

lightness irRead(int cutoff1, int cutoff2, pinData& sensor) {
  int analogValue = analogRead(sensor.sensorPin);                     // Read the value from the analog channel

  sensor.total -= sensor.readings[sensor.readIndex];                   // Subtract the last reading
  sensor.readings[sensor.readIndex] = analogValue;                     // Store the new reading
  sensor.total += sensor.readings[sensor.readIndex];                   // Add the new reading to the total
  sensor.readIndex = (sensor.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor.readIndex, numReadings);                  // Number of valid readings
  sensor.average = sensor.total / count;                               // Calculate the rolling average

  if (sensor.average > cutoff1)
    return black;
  else if (sensor.average < cutoff2)
    return white;
  else
    return grey;
}

bool irBlackRead(int cutoff, pinData& sensor) {
  int analogValue = analogRead(sensor.sensorPin);                     // Read the value from the analog channel

  sensor.total -= sensor.readings[sensor.readIndex];                   // Subtract the last reading
  sensor.readings[sensor.readIndex] = analogValue;                     // Store the new reading
  sensor.total += sensor.readings[sensor.readIndex];                   // Add the new reading to the total
  sensor.readIndex = (sensor.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor.readIndex, numReadings);                  // Number of valid readings
  sensor.average = sensor.total / count;                               // Calculate the rolling average

  if (sensor.average > cutoff)
    return true;
  else 
    return false;
}


bool checkCrater(int infrared_bottom_left_pin , int infrared_bottom_right_pin, int infrared_bottom_middle_pin){

}

bool checkBorder(int infrared_bottom_left_pin , int infrared_bottom_right_pin, int infrared_bottom_middle_pin){
}

bool checkRockSample(int infrared_bottom_middle_pin){

}

bool checkRampBorder(int infrared_bottom_left_pin , int infrared_bottom_right_pin){

}

bool checkLabWall(int infrared_forward_pin){

}