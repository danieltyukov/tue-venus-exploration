#include "drv_infrared.hpp"

// void setupSensors(pinData sensors[], int numSensors) {
//   for (int i = 0; i < numSensors; i++) {
//     sensors[i].sensorPin = A0 + i;
//     sensors[i].readIndex = 0;
//     sensors[i].total = 0;
//     sensors[i].average = 0;
//   }
// }
void setupLeftSensors(pinData sensors[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A0 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}
void setupRightSensors(pinData sensors[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A1 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}
void setupMiddleSensors(pinData sensors[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A2 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}

void setupMiddleSensorsLeft(pinData sensors[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A4 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}

void setupMiddleSensorsRight(pinData sensors[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A5 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}

bool checkRockSample(int cutoff, pinData& sensor_front){
  int analogValue_front = analogRead(sensor_front.sensorPin);

  sensor_front.total -= sensor_front.readings[sensor_front.readIndex];
  sensor_front.readings[sensor_front.readIndex] = analogValue_front;
  sensor_front.total += sensor_front.readings[sensor_front.readIndex];
  sensor_front.readIndex = (sensor_front.readIndex + 1) % numReadings;

  int count = max(sensor_front.readIndex, numReadings);
  sensor_front.average = sensor_front.total / count;

    if (sensor_front.average < cutoff)
        // white block
        return true;
    else 
        // nothing
        return false;
}

bool checkRockSampleRight(int cutoff, pinData& sensor_front_right){
  int analogValue_front = analogRead(sensor_front_right.sensorPin);

  sensor_front_right.total -= sensor_front_right.readings[sensor_front_right.readIndex];
  sensor_front_right.readings[sensor_front_right.readIndex] = analogValue_front;
  sensor_front_right.total += sensor_front_right.readings[sensor_front_right.readIndex];
  sensor_front_right.readIndex = (sensor_front_right.readIndex + 1) % numReadings;

  int count = max(sensor_front_right.readIndex, numReadings);
  sensor_front_right.average = sensor_front_right.total / count;

    if (sensor_front_right.average < cutoff)
        // white block
        return true;
    else 
        // nothing
        return false;
}

bool checkRockSampleLeft(int cutoff, pinData& sensor_front_left){
  int analogValue_front = analogRead(sensor_front_left.sensorPin);

  sensor_front_left.total -= sensor_front_left.readings[sensor_front_left.readIndex];
  sensor_front_left.readings[sensor_front_left.readIndex] = analogValue_front;
  sensor_front_left.total += sensor_front_left.readings[sensor_front_left.readIndex];
  sensor_front_left.readIndex = (sensor_front_left.readIndex + 1) % numReadings;

  int count = max(sensor_front_left.readIndex, numReadings);
  sensor_front_left.average = sensor_front_left.total / count;

    if (sensor_front_left.average < cutoff)
        // white block
        return true;
    else 
        // nothing
        return false;
}

bool checkRampBorderLeft(int cutoff, pinData& sensor_left){
  int analogValue_left = analogRead(sensor_left.sensorPin);

  sensor_left.total -= sensor_left.readings[sensor_left.readIndex];
  sensor_left.readings[sensor_left.readIndex] = analogValue_left;
  sensor_left.total += sensor_left.readings[sensor_left.readIndex];
  sensor_left.readIndex = (sensor_left.readIndex + 1) % numReadings;

  int count = max(sensor_left.readIndex, numReadings);
  sensor_left.average = sensor_left.total / count;

  if (sensor_left.average > cutoff)
    // black
    return true;
  else 
    // white
    return false;
}

bool checkRampBorderRight(int cutoff, pinData& sensor_right){
  int analogValue_right = analogRead(sensor_right.sensorPin);

  sensor_right.total -= sensor_right.readings[sensor_right.readIndex];
  sensor_right.readings[sensor_right.readIndex] = analogValue_right;
  sensor_right.total += sensor_right.readings[sensor_right.readIndex];
  sensor_right.readIndex = (sensor_right.readIndex + 1) % numReadings;

  int count = max(sensor_right.readIndex, numReadings);
  sensor_right.average = sensor_right.total / count;

  if (sensor_right.average > cutoff)
    // black
    return true;
  else 
    // white
    return false;
}

bool checkLabWall(int cutoff, pinData& sensor_front){
  int analogValue_front = analogRead(sensor_front.sensorPin);

  sensor_front.total -= sensor_front.readings[sensor_front.readIndex];
  sensor_front.readings[sensor_front.readIndex] = analogValue_front;
  sensor_front.total += sensor_front.readings[sensor_front.readIndex];
  sensor_front.readIndex = (sensor_front.readIndex + 1) % numReadings;

  int count = max(sensor_front.readIndex, numReadings);
  sensor_front.average = sensor_front.total / count;

  if (sensor_front.average > cutoff)
    // black
    return false;
  else
    // white
    return true;
}