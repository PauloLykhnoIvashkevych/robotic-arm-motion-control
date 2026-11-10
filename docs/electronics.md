# Electronics and Hardware Requirements

## 1. Overview

This document defines the electronic architecture and hardware requirements for the 15-DOF Robotic Hand Motion Control System.

The system consists of two main electronic units:

1. A wearable motion capture glove.
2. A robotic hand and wrist controlled by servo motors.

The design prioritizes accurate motion tracking, reliable communication, modularity and electrical safety.

## 2. Main Electronic Architecture

The system uses two ESP32 microcontrollers.

- ESP32 #1 reads and processes the glove sensors.
- ESP32 #2 receives movement data and controls the servo driver.

Wireless communication is implemented using ESP-NOW.

## 3. Bill of Materials (BOM)

### 3.1 Microcontrollers

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 Development Board | 2 | Glove and robotic hand controllers |

### 3.2 Motion Capture Glove

| Component | Quantity | Purpose |
|---|---:|---|
| Flex Sensors | 5 | Measure finger bending |
| IMU Sensor (BNO085 or equivalent) | 1 | Track wrist orientation |
| Additional IMU Sensors | Up to 5 | Improve individual finger motion tracking |
| Voltage Divider Resistors | As required | Adapt flex sensor signals |
| Glove Structure | 1 | Wearable sensor platform |
| Connecting Wires | As required | Electrical connections |

Additional sensors will be evaluated during prototyping. The final configuration depends on measurement accuracy, comfort and budget.

### 3.3 Robotic Hand Electronics

| Component | Quantity | Purpose |
|---|---:|---|
| Servo Motors | 15 | Independent joint actuation |
| PCA9685 PWM Driver | 1 | Generate servo control signals |
| External DC Power Supply | 1 | Power the servo motors |
| Power Distribution Board | 1 | Distribute motor power |
| Fuse Protection | As required | Protect against excessive current |
| Emergency Stop Switch | 1 | Disconnect motor power |

The PCA9685 provides 16 PWM channels, allowing control of 15 servos with one channel available for future expansion.

### 3.4 Supporting Components

- Breadboards for initial prototyping.
- PCB or custom distribution board for final assembly.
- Connectors and terminal blocks.
- Heat-shrink tubing.
- Electrical wiring.
- Mechanical mounting hardware.

## 4. Sensor System

### 4.1 Flex Sensors

Five flex sensors will be positioned along the fingers.

Each sensor measures resistance changes caused by bending.

The ESP32 reads the resulting voltage through an analog input using a voltage divider circuit.

The measured values are calibrated to represent finger movement.

### 4.2 Inertial Measurement Unit

The glove will use an IMU to measure hand and wrist orientation.

The BNO085 is a candidate because it provides orientation information and sensor fusion.

The IMU communicates with the ESP32 through I2C.

Additional finger-mounted IMUs may be evaluated to improve motion capture accuracy.

### 4.3 Sensor Calibration

Each sensor requires an individual calibration process.

Calibration will establish:

- Minimum sensor reading.
- Maximum sensor reading.
- Neutral hand position.
- Movement range.
- Filtering parameters.

Sensor readings will be normalized before being converted into robotic joint targets.

## 5. Servo Motor Control

### 5.1 PWM Driver

The PCA9685 will generate PWM signals for the 15 servo motors.

Communication between the ESP32 and PCA9685 uses I2C.

The controller will assign one PWM channel to each servo.

### 5.2 Servo Selection

Servo selection will depend on:

- Required torque.
- Operating voltage.
- Rotation range.
- Speed.
- Physical dimensions.
- Stall current.
- Mechanical mounting requirements.

The final servo models will be selected after the mechanical design and load calculations.

## 6. Power Management

The servo motors must use a dedicated external power supply.

The ESP32 and sensor electronics must have a suitable regulated logic supply.

The power system must include:

- Correct voltage for each servo model.
- Sufficient current capacity for simultaneous movement.
- Common ground between the controller and servo driver.
- Overcurrent protection.
- Suitable wiring and connectors.
- Emergency motor power disconnection.

The power supply current rating must be calculated using the servo stall current and the expected simultaneous motor load.

The ESP32 must not power the servo motors directly.

## 7. Communication

The glove and robotic hand controllers will communicate using ESP-NOW.

The communication packet should contain:

- Sensor readings.
- Calibrated joint targets.
- Packet sequence number.
- Connection status.
- Error or validity flags.

The receiving controller must detect communication loss and move the system into a safe state.

## 8. Electrical Safety

The design must consider:

- Servo stall conditions.
- Excessive current.
- Power supply overheating.
- Incorrect wiring.
- Short circuits.
- Communication failure.
- Unexpected mechanical movement.

An emergency stop must disconnect servo power without relying exclusively on software.

Mechanical movement limits must also prevent joints from exceeding their safe ranges.

## 9. Preliminary Component List

| Component | Quantity | Status |
|---|---:|---|
| ESP32 | 2 | Proposed |
| Flex Sensors | 5 | Proposed |
| BNO085 IMU | 1 | Candidate |
| Additional Finger IMUs | Up to 5 | Under evaluation |
| PCA9685 | 1 | Proposed |
| Servo Motors | 15 | Selection pending |
| DC Power Supply | 1 | Sizing pending |
| Emergency Stop | 1 | Proposed |
| Power Distribution Board | 1 | Proposed |

## 10. Testing Plan

### Initial Electronics Tests

- [ ] Test ESP32 communication.
- [ ] Read all flex sensors.
- [ ] Test IMU orientation measurements.
- [ ] Validate sensor calibration.
- [ ] Test PCA9685 communication.
- [ ] Test one servo independently.
- [ ] Test multiple servos simultaneously.
- [ ] Measure power consumption.
- [ ] Validate emergency stop operation.

### Integration Tests

- [ ] Transmit glove sensor data wirelessly.
- [ ] Convert sensor data into joint targets.
- [ ] Synchronize robotic hand movements.
- [ ] Test communication failure handling.
- [ ] Validate movement limits.

## 11. Budget and Procurement

The project does not impose a strict component budget at this stage.

Component selection will prioritize reliability, compatibility, mechanical performance and long-term expandability.

Purchases will only be finalized after checking component specifications and power requirements.

## 12. Current Development Status

**Phase:** Electronic architecture and component selection.

The final hardware configuration remains subject to testing, mechanical design and electrical calculations.
