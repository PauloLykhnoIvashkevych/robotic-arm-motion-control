
# System Diagrams

This directory contains the technical diagrams of the 15-DOF Robotic Hand Motion Control project.

The diagrams describe the system architecture, electronic connections, sensor integration and communication between the wearable glove and the robotic hand.

## Project Diagrams

| File | Description |
|---|---|
| `system-architecture.md` | Overall system architecture and component interaction |
| `glove-circuit.md` | Wearable glove sensor circuit |
| `robotic-hand-circuit.md` | Robotic hand electronics and servo connections |
| `wiring-diagram.md` | Electrical wiring and connection reference |
| `motion-flow.md` | Human hand motion capture and replication process |

## System Overview

The system is divided into two main units:

1. **Motion Capture Glove:** Collects finger movements and wrist orientation using wearable sensors.
2. **Robotic Hand:** Receives motion data and controls 15 servo motors to reproduce the captured movements.

## Diagram Status

The diagrams are part of the system design and development documentation.

Electrical connections, component selection and mechanical joint mapping must be validated before hardware assembly.

## Technologies

- ESP32
- ESP-NOW wireless communication
- Flex sensors
- Inertial Measurement Unit (IMU)
- PCA9685 PWM servo driver
- Servo motors

