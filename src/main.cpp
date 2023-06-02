#include <Arduino.h>
#include "drv_infrared.hpp"

pinData sensors[numSensors];

void setup() {
  Serial.begin(9600);

  setupSensors(sensors);
}

void loop() {
  int value1 = irRead(700, 500, sensors[0]);
  int value2 = irRead(700, 500, sensors[1]);

  Serial.print("Sensor 1 Average: ");
  Serial.print(sensors[0].average);
  Serial.print(", ");
  Serial.println(value1);

  Serial.print("Sensor 2 Average: ");
  Serial.print(sensors[1].average);
  Serial.print(", ");
  Serial.println(value2);
  delay(100);
}
