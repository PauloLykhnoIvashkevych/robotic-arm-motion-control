# Robotic Hand Controller

## 1. Overview

This module is responsible for controlling the 15-DOF robotic hand and wrist.

It receives movement data from the motion capture glove and converts the information into servo motor commands.

The controller is designed to reproduce human hand movements through coordinated joint actuation.

## 2. Main Responsibilities

- Receive movement data from the glove controller.
- Process incoming sensor information.
- Convert movement values into servo positions.
- Control 15 independent servo motors.
- Manage communication with the PCA9685 PWM driver.
- Apply movement limits to protect the mechanical joints.
- Handle communication errors and unexpected conditions.

## 3. Hardware

The robotic hand controller is designed around the following components:

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 | 1 | Main controller |
| PCA9685 | 1 | Servo PWM control |
| Servo Motors | 15 | Joint movement |
| External Power Supply | 1 | Servo power |
| Emergency Stop | 1 | Motor power disconnection |

## 4. Communication

The controller receives movement information from the glove controller using ESP-NOW wireless communication.

The received data is processed and translated into individual servo positions.

The ESP32 communicates with the PCA9685 through the I2C interface.

## 5. Servo Configuration

The PCA9685 provides 16 PWM channels.

The system uses 15 channels to control the robotic hand and wrist.

Each servo is assigned to a specific joint. Servo positions must be calibrated according to the mechanical limits of each joint.

## 6. Safety

The controller must include:

- Software movement limits.
- Communication failure detection.
- Safe startup positions.
- Servo movement restrictions.
- Emergency stop support.

The emergency stop must disconnect motor power independently of the software.

## 7. Main Firmware File

`robotic_hand_controller.ino`

This file contains the main firmware for the robotic hand controller.

## 8. Development Status

**Current phase:** Firmware structure and controller development.

Servo calibration, wireless integration and full hardware testing will be completed during the integration phase.
