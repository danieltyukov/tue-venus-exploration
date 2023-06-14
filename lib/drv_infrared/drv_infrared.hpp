#ifndef DRV_INFRARED_H
#define DRV_INFRARED_H
#include <Arduino.h>

const int numSensors = 4;              // number of sensors
const int numReadings = 2;                 // number of readings for average

struct pinData {
  int sensorPin;
  int readings[numReadings];
  int readIndex;
  long total;
  int average;
};
enum lightness {

  black,
  grey,
  white
  
};

void setupSensors(pinData sensors[], int numSensors);
bool irBlackRead(int cutoff, pinData& sensor);
lightness irRead(int cutoff1, int cutoff2, pinData& sensor);

bool checkGround(int cutoff, pinData& sensor_left, pinData& sensor_right);
bool checkRockSample(int cutoff, pinData& sensor_front);
bool checkRampBorderLeft(int cutoff, pinData& sensor_left);
bool checkRampBorderRight(int cutoff, pinData& sensor_right);
bool checkLabWall(int cutoff, pinData& sensor_front);
bool checkLabColor(int cutoff, pinData& sensor_front);
#endif  // DRV_INFRARED_H
