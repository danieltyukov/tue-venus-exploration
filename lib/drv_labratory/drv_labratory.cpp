#include "drv_labratory.hpp"

bool checkLabDetected(int pin) {
    int j = 0;
    for (int i = 0; i < 40; i++) {
        j+=digitalRead(pin);
        delay(5);
    }
    int avg = j/40;
    if (avg = 1) {
        return false;
    }
    else {
        return true;
    }
}