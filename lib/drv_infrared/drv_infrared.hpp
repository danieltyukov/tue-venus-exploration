#ifndef DRV_INFRARED_H
#define DRV_INFRARED_H

#include <Arduino.h>

const int numSensors = 2;                   // number of sensors
const int numReadings = 10;                 // number of readings for average

struct pinData {
  int sensorPin;
  int readings[numReadings];
  int readIndex;
  long total;
  int average;
};

void setupSensors(pinData sensors[]);
int irRead(int cutoff1, int cutoff2, pinData & sensor);

#endif  // DRV_INFRARED_H
