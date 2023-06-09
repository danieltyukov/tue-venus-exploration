#ifndef DRV_INFRARED_H
#define DRV_INFRARED_H
#include <Arduino.h>

const int numBlackSensors = 2;              // number of sensors
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

void setupBlackSensors(pinData sensors[], int numSensors);
bool irBlackRead(int cutoff, pinData& sensor);
lightness irRead(int cutoff1, int cutoff2, pinData& sensor);

#endif  // DRV_INFRARED_H
