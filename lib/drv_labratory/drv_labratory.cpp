#include "drv_labratory.hpp"

bool checkLabDetected(int labratory_pin) {
    int j = 0;
    for (int i = 0; i < 40; i++)
    {
        j += digitalRead(8);
        // Serial.print(digitalRead(8));
        delay(20);
    }

    int avg = j / 40;
    // Serial.println();
    Serial.println(avg ? "not in sight" : "in sight");
    // return true if the beacon is in sight
    return !avg;
}