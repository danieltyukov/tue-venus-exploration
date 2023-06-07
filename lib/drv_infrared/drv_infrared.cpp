#include "drv_infrared.hpp"

// include functions with distinct names for all the different IR sensors (Different pins)


void setupSensors(pinData sensors[]) {
  // Initialize sensor objects
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A0 + i;
    sensors[i].readIndex = 0;
    sensors[i].total = 0;
    sensors[i].average = 0;
  }
}

int irRead(int cutoff1, int cutoff2, pinData& sensor) {
  int analogValue = analogRead(sensor.sensorPin);                     // Read the value from the analog channel

  sensor.total -= sensor.readings[sensor.readIndex];                   // Subtract the last reading
  sensor.readings[sensor.readIndex] = analogValue;                     // Store the new reading
  sensor.total += sensor.readings[sensor.readIndex];                   // Add the new reading to the total
  sensor.readIndex = (sensor.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor.readIndex + 1, numReadings);                  // Number of valid readings
  sensor.average = sensor.total / count;                               // Calculate the rolling average

  if (sensor.average > cutoff1)
    return 1;
  else if (sensor.average < cutoff2)
    return 2;
  else
    return 0;
}
