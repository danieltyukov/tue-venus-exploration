#include "drv_labratory.hpp"

bool checkLabDetected(int labratory_pin) {
    int j = 0;
    for (int i = 0; i < 40; i++) {
        j+=digitalRead(labratory_pin);
        delay(5);
    }
    int avg = j/40;
    return !avg;
}