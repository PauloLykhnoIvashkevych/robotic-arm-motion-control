# Hardware

## 1. Overview

This directory contains the hardware documentation for the 15-DOF Robotic Hand Motion Control project.

It describes the physical components, electronic systems and hardware organization required to build the robotic hand and wearable motion capture glove.

## 2. Hardware Architecture

The hardware is divided into two main systems:

### Motion Capture Glove
- ESP32 microcontroller.
- Five flex sensors.
- IMU sensor for wrist orientation.
- Supporting electronic components.
- Wearable glove structure.

### Robotic Hand
- 15 servo motors.
- ESP32 microcontroller.
- PCA9685 PWM driver.
- External power supply.
- Power distribution and safety components.
- Mechanical hand and wrist structure.

## 3. Hardware Documentation

The hardware design is supported by the following documents:

| Document | Description |
|---|---|
| `../docs/electronics.md` | Electronic components and hardware requirements |
| `../docs/wiring.md` | Electrical connections and wiring |
| `../docs/mechanical-design.md` | Mechanical structure and joint design |
| `../docs/calibration.md` | Sensor and servo calibration |

## 4. Software Integration

The hardware communicates with the embedded software through two ESP32 controllers.

The glove controller captures human hand movements and transmits the data wirelessly.

The robotic hand controller processes the received information and controls the 15 servo motors.

Software-related hardware files and resources are organized in the `software/` directory.

## 5. Safety Considerations

The hardware design must consider:

- Correct power supply specifications.
- Servo current requirements.
- Electrical protection.
- Secure wiring and connections.
- Emergency stop functionality.
- Mechanical movement limits.

## 6. Development Status

**Current phase:** Hardware documentation and component planning.

Final component selection, assembly and testing will take place during the prototyping and integration stages.
