# Robotic Arm Motion Control

An Arduino/ESP32-based robotic hand project focused on human motion replication through a wearable sensor glove.

## Project Overview

The goal is to develop a 15-degree-of-freedom (15-DOF) robotic hand and wrist capable of reproducing human hand movements in real time.

A wearable glove equipped with flex sensors and inertial measurement sensors will capture hand and wrist movements and transmit the data wirelessly to the robotic system.

## Project Objectives

- Develop a 15-DOF anthropomorphic robotic hand.
- Capture finger movements using flex sensors.
- Track hand and wrist orientation using an IMU.
- Implement wireless communication between the glove and robotic hand.
- Control multiple servo motors with coordinated movement.
- Develop calibration and safety mechanisms.

## System Architecture

**Motion Capture Glove**
- ESP32 microcontroller
- 5 flex sensors
- IMU sensor
- Wireless communication

**Robotic Hand**
- ESP32 microcontroller
- PCA9685 servo driver
- 15 servo motors
- External power supply

## Degrees of Freedom

| Component | DOF |
|---|---:|
| Thumb | 3 |
| Index Finger | 2 |
| Middle Finger | 2 |
| Ring Finger | 2 |
| Little Finger | 2 |
| Wrist | 2 |
| Forearm Rotation | 1 |
| Finger Abduction | 1 |
| **Total** | **15** |

## Technologies

- C / C++
- Arduino IDE
- ESP32
- Servo Motor Control
- Sensor Integration
- Wireless Communication
- 3D Mechanical Design

## Development Status

**Status:** Initial planning and architecture design.

This project is currently under development. Hardware integration, firmware implementation and mechanical design will be documented as development progresses.

## License

This project is licensed under the MIT License.
