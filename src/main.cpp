#include <Arduino.h>

const int touchPin = 2;
int touchState = 0;

void setup() {
    Serial.begin(9600);
    pinMode(touchPin, INPUT);
    Serial.println("System Ready");
}
void loop() {
    touchState = digitalRead(touchPin);

    if (touchState == HIGH) {
        Serial.println("Touch Detected");
    } else {
        Serial.println("No Touch");
    }
}