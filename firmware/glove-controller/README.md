# Glove Controller

## 1. Overview

The Glove Controller is responsible for capturing human hand and wrist movements through a wearable motion capture glove.

It reads sensor data, processes the measurements and transmits movement information wirelessly to the robotic hand controller.

The system is based on an ESP32 microcontroller.

## 2. Main Responsibilities

- Read the five finger flex sensors.
- Measure hand and wrist orientation using an IMU.
- Process and filter sensor measurements.
- Calibrate sensor values.
- Convert sensor readings into movement data.
- Transmit movement information to the robotic hand controller.
- Monitor communication status.

## 3. Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 | 1 | Main glove controller |
| Flex Sensors | 5 | Measure finger bending |
| BNO085 IMU | 1 | Track hand and wrist orientation |
| Voltage Divider Resistors | As required | Read flex sensor signals |
| Glove Structure | 1 | Support the sensors |
| Connecting Wires | As required | Electrical connections |

Additional IMU sensors may be evaluated during development to improve finger movement tracking.

## 4. Sensor Processing

The ESP32 reads the flex sensors through its analog inputs.

Each sensor measures changes in resistance when a finger bends.

The IMU provides orientation data through the I2C interface.

The collected measurements are processed and calibrated before transmission.

## 5. Calibration

Each sensor requires an individual calibration process.

Calibration includes:

- Minimum and maximum readings.
- Neutral hand position.
- Finger movement range.
- Sensor filtering.

This process helps ensure that the robotic hand reproduces the movements captured by the glove.

## 6. Wireless Communication

The Glove Controller communicates with the Robotic Hand Controller using ESP-NOW.

The transmitted data should include:

- Finger movement values.
- Wrist orientation.
- Packet sequence number.
- Data validity information.

The receiving controller uses this information to calculate the corresponding servo positions.

## 7. Main Firmware File

`glove_controller.ino`

This file contains the main firmware for reading sensors, processing movement data and managing wireless communication.

## 8. Development Status

**Current phase:** Sensor integration and firmware development.

Sensor calibration, wireless communication and integration with the robotic hand will be tested during the next development stages.
