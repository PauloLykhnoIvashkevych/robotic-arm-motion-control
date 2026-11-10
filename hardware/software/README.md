# Hardware Software

## 1. Overview

This directory contains software resources related to the configuration, communication and testing of the hardware components used in the 15-DOF Robotic Hand Motion Control project.

It supports the integration between the wearable motion capture glove and the robotic hand.

## 2. Main Functions

The software associated with the hardware is responsible for:

- Configuring the ESP32 microcontrollers.
- Reading sensor measurements.
- Processing movement data.
- Managing wireless communication.
- Controlling the servo driver.
- Supporting hardware testing and calibration.

## 3. System Components

The software interacts with the following hardware components:

| Component | Software Function |
|---|---|
| ESP32 | Sensor processing and system control |
| Flex Sensors | Finger movement measurement |
| IMU | Hand and wrist orientation tracking |
| PCA9685 | Servo motor signal generation |
| Servo Motors | Robotic joint movement |

## 4. System Communication

The system uses two ESP32 microcontrollers.

The glove controller collects sensor data and transmits movement information using ESP-NOW.

The robotic hand controller receives this information and generates the corresponding servo commands through the PCA9685 driver.

## 5. Development and Testing

Software testing will include:

- Sensor reading validation.
- ESP32 communication tests.
- Servo control tests.
- Calibration procedures.
- Hardware and firmware integration.

## 6. Development Status

**Current phase:** Software organization and hardware integration planning.

Additional software resources will be added as development progresses.
