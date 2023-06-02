const int numSensors = 2;                   // number of sensors
const int numReadings = 10;                 // number of readings for average

struct pinData {
  int sensorPin;
  int readings[numReadings];
  int readIndex;
  long total;
  int average;
};

pinData sensors[numSensors];

void setup() {
  Serial.begin(9600);

  // Initialize sensor objects
  for (int i = 0; i < numSensors; i++) {
    sensors[i].sensorPin = A0 + i * 4;
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


