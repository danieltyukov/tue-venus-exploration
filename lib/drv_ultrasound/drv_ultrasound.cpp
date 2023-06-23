#include "drv_ultrasound.hpp"

bool detectObstacle(int ultrasound_pin) {

    long duration;

    pinMode(ultrasound_pin, OUTPUT);
    digitalWrite(ultrasound_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasound_pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(ultrasound_pin, LOW);
    pinMode(ultrasound_pin, INPUT);
    duration = pulseIn(ultrasound_pin, HIGH);

    return (duration/58.0 < 30.0); // compare with a distance threshold (30 cm in this case)
}