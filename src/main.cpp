/**
 * @file main.cpp
 * @brief Smart Touch Input System - TTP223 Capacitive Touch Sensor
 *
 * This application implements a simple touch detection system using a TTP223
 * capacitive touch sensor connected to an Arduino microcontroller. The system
 * continuously monitors the touch sensor and reports detection status via
 * serial communication.
 *
 * @author Akshat Lakhotiya
 * @date February 2026
 * @version 1.0
 *
 * @details
 * The system initializes serial communication at 9600 baud and configures
 * the touch sensor pin as an input. During each loop iteration, the touch
 * state is sampled and the result is transmitted serially.
 *
 * @hardware
 * - Arduino microcontroller (Uno, Nano, Mega, etc.)
 * - TTP223 Capacitive Touch Sensor Module
 * - Digital Pin 2 (touch sensor input)
 * - Serial Port (9600 baud for debugging/monitoring)
 *
 * @note Ensure proper decoupling capacitors are used with the TTP223 module
 * @see https://github.com/maheshwariakshat34/smart-touch-input-system-ttp223
 */

#include <Arduino.h>

/** @brief GPIO pin number for the TTP223 touch sensor input */
int touchPin = 2;

/** @brief Current state of the touch sensor (HIGH = touched, LOW = not touched) */
int touchState = 0;

/**
 * @brief Arduino setup function - called once on initialization
 *
 * Initializes the Arduino system, configures serial communication, and sets up
 * the touch sensor pin as a digital input. This function is called automatically
 * by the Arduino framework once after power-on or reset.
 *
 * @return void
 * @note Serial communication is configured at 9600 baud for debugging output
 * @see pinMode(), Serial.begin()
 */
void setup() {
    Serial.begin(9600);
    pinMode(touchPin, INPUT);
    Serial.println("System Ready");
}
/**
 * @brief Arduino main loop function - called repeatedly
 *
 * This function runs continuously after setup(). It performs the following operations:
 * -# Reads the current state of the touch sensor from the configured pin
 * -# Evaluates the touch state and generates appropriate output message
 * -# Transmits the status message via serial communication (9600 baud)
 * -# Adds a 300ms delay between sensor readings to prevent flooding the serial port
 *
 * The touch sensor outputs HIGH when touched and LOW when not touched.
 *
 * @return void
 * @note The 300ms delay can be adjusted to change the sampling frequency
 * @see digitalRead(), Serial.println(), delay()
 */
void loop() {
    touchState = digitalRead(touchPin);

    if (touchState == HIGH) {
        Serial.println("Touch Detected");
    } else {
        Serial.println("No Touch");
    }
    delay(300);
}