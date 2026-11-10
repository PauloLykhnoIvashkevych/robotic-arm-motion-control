# System Architecture

## 1. Overview

The Robotic Arm Motion Control project aims to develop a 15-DOF robotic hand and wrist controlled through a wearable motion capture glove.

The system is divided into two main units:

- **Glove Controller:** Captures human hand and wrist movements.
- **Robotic Hand Controller:** Processes incoming sensor data and controls the robotic servos.

The objective is to reproduce the user's hand movements as naturally and accurately as possible.

## 2. System Architecture

```text
         HUMAN HAND
              |
              v
      MOTION CAPTURE GLOVE
              |
       +------+------+
       |             |
   Flex Sensors     IMU
       |             |
       +------+------+
              |
          ESP32 #1
              |
       Wireless Link
          (ESP-NOW)
              |
              v
          ESP32 #2
              |
       PCA9685 Driver
              |
       Servo Motors
              |
              v
       ROBOTIC HAND
          15 DOF
```

## 3. Motion Capture Glove

The glove is responsible for measuring human hand movements.

### Components

- ESP32 microcontroller
- 5 Flex Sensors
- IMU sensor (MPU6050 or equivalent)
- Voltage divider circuits
- Wearable glove structure

### Responsibilities

- Measure finger bending.
- Track wrist orientation.
- Read sensor values.
- Calibrate sensor measurements.
- Transmit movement data wirelessly.

## 4. Robotic Hand

The robotic hand reproduces the movements captured by the glove.

### Components

- ESP32 microcontroller
- PCA9685 16-channel PWM driver
- 15 servo motors
- Mechanical hand structure
- External power supply

### Degrees of Freedom

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

## 5. Communication

The two ESP32 controllers will communicate wirelessly using ESP-NOW.

The glove controller will transmit calibrated sensor measurements to the robotic hand controller.

The receiving controller will convert those measurements into servo positions.

## 6. Control Pipeline

1. Read glove sensors.
2. Filter sensor measurements.
3. Apply calibration.
4. Convert sensor values into target angles.
5. Transmit movement data.
6. Receive data on the robotic hand.
7. Apply movement limits.
8. Move the corresponding servo motors.

## 7. Safety and Reliability

The system should include:

- Servo angle limits.
- Sensor calibration.
- Communication timeout detection.
- Safe default positions.
- Power supply protection.
- Emergency stop functionality.

## 8. Development Roadmap

- [ ] Design the robotic hand mechanics.
- [ ] Select the 15 servo motors.
- [ ] Build the motion capture glove.
- [ ] Integrate flex sensors and IMU.
- [ ] Develop wireless communication.
- [ ] Implement servo control.
- [ ] Test individual movements.
- [ ] Integrate the complete system.
- [ ] Optimize movement accuracy and response time.

## 9. Project Status

**Current phase:** Architecture and system planning.

Hardware selection, mechanical design and firmware implementation are still in progress.
