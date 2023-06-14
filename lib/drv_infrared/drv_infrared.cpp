#include "drv_infrared.hpp"

void setupSensors(pinData sensors[], int numSensors) {
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


bool checkGround(int cutoff, pinData& sensor_left, pinData& sensor_right){
  int analogValue_left = analogRead(sensor_left.sensorPin);                     // Read the value from the analog channel
  int analogValue_right = analogRead(sensor_right.sensorPin);

  sensor_left.total -= sensor_left.readings[sensor_left.readIndex];                   // Subtract the last reading
  sensor_left.readings[sensor_left.readIndex] = analogValue_left;                     // Store the new reading
  sensor_left.total += sensor_left.readings[sensor_left.readIndex];                   // Add the new reading to the total
  sensor_left.readIndex = (sensor_left.readIndex + 1) % numReadings;             // Move to the next position in the array

  sensor_right.total -= sensor_right.readings[sensor_right.readIndex];                   // Subtract the last reading
  sensor_right.readings[sensor_right.readIndex] = analogValue_right;                     // Store the new reading
  sensor_right.total += sensor_right.readings[sensor_right.readIndex];                   // Add the new reading to the total
  sensor_right.readIndex = (sensor_right.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_left.readIndex, numReadings);                  // Number of valid readings
  sensor_left.average = sensor_left.total / count;
  sensor_right.average = sensor_right.total / count;                               // Calculate the rolling average

  if (sensor_left.average  > cutoff || sensor_right.average > cutoff) return true;
  else return false; 
}



bool checkRockSample(int cutoff, pinData& sensor_front){
  int analogValue_front = analogRead(sensor_front.sensorPin);                     // Read the value from the analog channel

  sensor_front.total -= sensor_front.readings[sensor_front.readIndex];                   // Subtract the last reading
  sensor_front.readings[sensor_front.readIndex] = analogValue_front;                     // Store the new reading
  sensor_front.total += sensor_front.readings[sensor_front.readIndex];                   // Add the new reading to the total
  sensor_front.readIndex = (sensor_front.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_front.readIndex, numReadings);                  // Number of valid readings
  sensor_front.average = sensor_front.total / count;                               // Calculate the rolling average


}

bool checkRampBorderLeft(int cutoff, pinData& sensor_left){
  int analogValue_left = analogRead(sensor_left.sensorPin);                     // Read the value from the analog channel

  sensor_left.total -= sensor_left.readings[sensor_left.readIndex];                   // Subtract the last reading
  sensor_left.readings[sensor_left.readIndex] = analogValue_left;                     // Store the new reading
  sensor_left.total += sensor_left.readings[sensor_left.readIndex];                   // Add the new reading to the total
  sensor_left.readIndex = (sensor_left.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_left.readIndex, numReadings);                  // Number of valid readings
  sensor_left.average = sensor_left.total / count;                               // Calculate the rolling average

  if (sensor_left.average > cutoff)
    return true;
  else 
    return false;
}

bool checkRampBorderRight(int cutoff, pinData& sensor_right){
  int analogValue_right = analogRead(sensor_right.sensorPin);                     // Read the value from the analog channel

  sensor_right.total -= sensor_right.readings[sensor_right.readIndex];                   // Subtract the last reading
  sensor_right.readings[sensor_right.readIndex] = analogValue_right;                     // Store the new reading
  sensor_right.total += sensor_right.readings[sensor_right.readIndex];                   // Add the new reading to the total
  sensor_right.readIndex = (sensor_right.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_right.readIndex, numReadings);                  // Number of valid readings
  sensor_right.average = sensor_right.total / count;                               // Calculate the rolling average

  if (sensor_right.average > cutoff)
    return true;
  else 
    return false;

}

bool checkLabWall(int cutoff, pinData& sensor_front){
  int analogValue_front = analogRead(sensor_front.sensorPin);                     // Read the value from the analog channel

  sensor_front.total -= sensor_front.readings[sensor_front.readIndex];                   // Subtract the last reading
  sensor_front.readings[sensor_front.readIndex] = analogValue_front;                     // Store the new reading
  sensor_front.total += sensor_front.readings[sensor_front.readIndex];                   // Add the new reading to the total
  sensor_front.readIndex = (sensor_front.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_front.readIndex, numReadings);                  // Number of valid readings
  sensor_front.average = sensor_front.total / count;                               // Calculate the rolling average

  if (sensor_front.average > cutoff)
    return false;
  else 
    return true;
}

bool checkLabColor(int cutoff, pinData& sensor_front){
  int analogValue_left = analogRead(sensor_front.sensorPin);                     // Read the value from the analog channel

  sensor_front.total -= sensor_front.readings[sensor_front.readIndex];                   // Subtract the last reading
  sensor_front.readings[sensor_front.readIndex] = analogValue_left;                     // Store the new reading
  sensor_front.total += sensor_front.readings[sensor_front.readIndex];                   // Add the new reading to the total
  sensor_front.readIndex = (sensor_front.readIndex + 1) % numReadings;             // Move to the next position in the array

  int count = max(sensor_front.readIndex, numReadings);                  // Number of valid readings
  sensor_front.average = sensor_front.total / count;                               // Calculate the rolling average

  if (sensor_front.average > cutoff)
    return false;
  else 
    return true;

}