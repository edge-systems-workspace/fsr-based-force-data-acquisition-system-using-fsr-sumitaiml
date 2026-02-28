#include <Arduino.h>
/**
 * @file main.cpp
 * @brief FSR-based force data acquisition system - main application
 * @author Sumit kumar singh
 * @date 2026-02-28
 * @version 1.0.0
 * @license MIT
 *
 * @details
 * This firmware reads analog values from a Force Sensitive Resistor (FSR)
 * attached to the analog input pin A0. It prints raw ADC readings to the
 * Serial Monitor and emits a simple pressure/no-pressure message based on a
 * configurable threshold. Use this as a starting point for calibration and
 * mapping ADC values to force units.
 *
 * @note
 * - Adjust PRESSURE_THRESHOLD to suit your sensor and mechanical setup.
 * - Consider averaging or filtering the readings for more stable output.
 *
 * @todo
 * - Add calibration routine to convert ADC to Newtons or grams.
 * - Add configurable serial output format (CSV/JSON) for PC-side logging.
 */

const int FSR_PIN = A0;

int fsrReading = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("FSR Force Measurement System - Initialized");
}

void loop() {
    fsrReading = analogRead(FSR_PIN);
    Serial.print("FSR raw ADC: ");
    Serial.println(fsrReading);
    const int PRESSURE_THRESHOLD = 100;
    if (fsrReading > PRESSURE_THRESHOLD) {
        Serial.println("Pressure detected");
    } else {
        Serial.println("No pressure");
    }
    delay(500);
}
