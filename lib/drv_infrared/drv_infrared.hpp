#ifndef DRV_INFRARED_H
#define DRV_INFRARED_H
#include <Arduino.h>

const int numSensors = 5;
const int numReadings = 1;

struct pinData {
  int sensorPin;
  int readings[numReadings];
  int readIndex;
  long total;
  int average;
};

// void setupSensors(pinData sensors[], int numSensors);
void setupLeftSensors(pinData sensors[], int numSensors);
void setupRightSensors(pinData sensors[], int numSensors);
void setupMiddleSensors(pinData sensors[], int numSensors);
void setupMiddleSensorsLeft(pinData sensors[], int numSensors);
void setupMiddleSensorsRight(pinData sensors[], int numSensors);

bool checkRockSample(int cutoff, pinData& sensor_front);
bool checkRockSampleLeft(int cutoff, pinData& sensor_front_left);
bool checkRockSampleRight(int cutoff, pinData& sensor_front_right);
bool checkRampBorderLeft(int cutoff, pinData& sensor_left);
bool checkRampBorderRight(int cutoff, pinData& sensor_right);
bool checkLabWall(int cutoff, pinData& sensor_front);
#endif  // DRV_INFRARED_H
