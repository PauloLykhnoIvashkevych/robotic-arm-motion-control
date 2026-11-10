
/*
 * Robotic Arm Motion Control
 * Glove Controller
 *
 * Reads five flex sensors using an ESP32.
 * Displays raw and averaged sensor values.
 *
 * Hardware: ESP32
 */

#include <Arduino.h>

// Flex sensor analog input pins
const int FLEX_PINS[5] = {
    32, 33, 34, 35, 36
};

// Number of flex sensors
const int SENSOR_COUNT = 5;

// Number of samples used for averaging
const int SAMPLE_COUNT = 10;

// Sensor readings
int sensorValues[SENSOR_COUNT];

void initializeSensors() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        pinMode(FLEX_PINS[i], INPUT);
    }

    analogReadResolution(12);

    for (int i = 0; i < SENSOR_COUNT; i++) {
        analogSetPinAttenuation(
            FLEX_PINS[i],
            ADC_11db
        );
    }
}

int readFlexSensor(int pin) {
    long total = 0;

    for (int i = 0; i < SAMPLE_COUNT; i++) {
        total += analogRead(pin);
        delayMicroseconds(500);
    }

    return total / SAMPLE_COUNT;
}

void readAllSensors() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensorValues[i] = readFlexSensor(
            FLEX_PINS[i]
        );
    }
}

void printSensorData() {
    Serial.println("=== FLEX SENSOR DATA ===");

    for (int i = 0; i < SENSOR_COUNT; i++) {
        Serial.print("Finger ");
        Serial.print(i + 1);
        Serial.print(": ");

        Serial.println(sensorValues[i]);
    }

    Serial.println("========================");
}

void setup() {
    Serial.begin(115200);

    initializeSensors();

    Serial.println();
    Serial.println("Robotic Hand Motion Control");
    Serial.println("Glove Controller initialized");
    Serial.println("Waiting for sensor readings...");
}

void loop() {
    readAllSensors();

    printSensorData();

    delay(100);
}
