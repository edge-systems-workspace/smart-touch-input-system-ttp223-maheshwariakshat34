#include <Arduino.h>

const int touchPin = 2;
int touchState = 0;

void setup() {
    Serial.begin(9600);
    pinMode(touchPin, INPUT);
    Serial.println("System Ready");
}