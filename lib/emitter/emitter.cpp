#include "emitter.hpp"

void emitIRSignal(int pin) {
    tone(pin, 38000);
    delay(30);
    tone(pin, 0);
    delay(30);
}