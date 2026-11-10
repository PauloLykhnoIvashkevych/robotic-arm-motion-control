# Wiring and Electrical Connections

## 1. Overview

This document describes the electrical connections for the 15-DOF Robotic Hand Motion Control System.

The hardware is divided into two independent electronic units:

- Motion Capture Glove
- Robotic Hand Controller

Both units communicate wirelessly using ESP-NOW.

## 2. System Wiring Architecture

```text
             MOTION CAPTURE GLOVE
             --------------------

       5x Flex Sensors
              |
       Voltage Dividers
              |
              v
          ESP32 #1
              ^
              |
         I2C Bus
              |
           BNO085
              |
              |
          ESP-NOW
              |
              v
       ROBOTIC HAND CONTROLLER
       -----------------------

          ESP32 #2
              |
            I2C
              |
              v
          PCA9685
              |
       15 PWM Channels
              |
              v
         15 Servo Motors
              |
       External Power Supply
```

## 3. Glove Controller Wiring

### 3.1 Flex Sensors

Each flex sensor is connected to an analog input using a voltage divider.

| Component | ESP32 Connection |
|---|---|
| Flex Sensor 1 | GPIO 32 |
| Flex Sensor 2 | GPIO 33 |
| Flex Sensor 3 | GPIO 34 |
| Flex Sensor 4 | GPIO 35 |
| Flex Sensor 5 | GPIO 36 |

Each sensor requires a fixed resistor to create a voltage divider.

The voltage divider output must remain within the ESP32 ADC input voltage limits.

The resistor value will be selected after measuring the resistance range of the actual flex sensors.

### 3.2 IMU Sensor (BNO085)

| BNO085 Pin | ESP32 #1 |
|---|---|
| VIN | Compatible regulated supply |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

The BNO085 communicates through the I2C protocol.

Check the exact breakout board specifications before connecting its power pins.

## 4. Robotic Hand Controller Wiring

### 4.1 PCA9685 PWM Driver

| PCA9685 Pin | ESP32 #2 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

The PCA9685 communicates with the ESP32 through I2C.

### 4.2 Servo Connections

Each servo has three wires:

| Servo Wire | Connection |
|---|---|
| Signal | PCA9685 PWM channel |
| VCC | External servo power supply |
| GND | Common ground |

### 4.3 PWM Channel Allocation

| Servo | PWM Channel | Joint |
|---|---:|---|
| Servo 1 | 0 | Wrist movement 1 |
| Servo 2 | 1 | Wrist movement 2 |
| Servo 3 | 2 | Thumb joint 1 |
| Servo 4 | 3 | Thumb joint 2 |
| Servo 5 | 4 | Thumb joint 3 |
| Servo 6 | 5 | Index joint 1 |
| Servo 7 | 6 | Index joint 2 |
| Servo 8 | 7 | Index joint 3 |
| Servo 9 | 8 | Middle joint 1 |
| Servo 10 | 9 | Middle joint 2 |
| Servo 11 | 10 | Middle joint 3 |
| Servo 12 | 11 | Ring joint 1 |
| Servo 13 | 12 | Ring joint 2 |
| Servo 14 | 13 | Little finger joint 1 |
| Servo 15 | 14 | Little finger joint 2 |

This is a preliminary channel allocation. The final mapping must match the mechanical design.

## 5. Power Distribution

The robotic hand uses a dedicated external power supply for the servo motors.

```text
          EXTERNAL DC POWER SUPPLY
                    |
              FUSE PROTECTION
                    |
              EMERGENCY STOP
                    |
                    v
             SERVO POWER RAIL
                    |
             PCA9685 V+ INPUT
                    |
             15 SERVO MOTORS
```

The controller electronics use a separate regulated logic supply.

### Important Power Requirements

- Never power the servo motors directly from the ESP32.
- Never assume all servos use the same voltage.
- Calculate the required current using the servo stall current.
- Use wiring and connectors rated for the expected current.
- Connect the grounds of the ESP32, PCA9685 and servo supply together.
- Keep servo power wiring separate from sensitive sensor wiring where practical.
- Verify polarity before applying power.

The emergency stop should interrupt the servo motor power supply. It must not depend only on software.

## 6. Communication Between Controllers

The two ESP32 boards communicate using ESP-NOW.

### Transmitter: ESP32 #1

1. Reads the five flex sensors.
2. Reads the BNO085.
3. Filters and calibrates sensor data.
4. Creates a movement data packet.
5. Sends the packet wirelessly.

### Receiver: ESP32 #2

1. Receives the movement packet.
2. Checks packet validity.
3. Converts the movement data into servo targets.
4. Applies joint limits.
5. Sends PWM commands to the PCA9685.

If communication is lost, the controller must stop accepting new movement commands and enter a predefined safe state.

## 7. Electrical Safety Checklist

- [ ] Verify all power supply voltages.
- [ ] Verify servo polarity.
- [ ] Verify common ground connections.
- [ ] Check for short circuits.
- [ ] Test the emergency stop.
- [ ] Test one servo before connecting all motors.
- [ ] Measure current consumption.
- [ ] Check cable temperature under load.
- [ ] Confirm sensor inputs remain within safe voltage limits.

## 8. Testing Procedure

### Stage 1: Glove

- [ ] Connect one flex sensor.
- [ ] Read analog values.
- [ ] Test all five flex sensors.
- [ ] Connect the BNO085.
- [ ] Validate orientation readings.
- [ ] Test sensor calibration.

### Stage 2: Robotic Hand

- [ ] Connect the PCA9685.
- [ ] Test I2C communication.
- [ ] Connect one servo.
- [ ] Test servo movement.
- [ ] Test all servos individually.
- [ ] Test multiple servos simultaneously.
- [ ] Validate emergency stop operation.

### Stage 3: Full System

- [ ] Establish ESP-NOW communication.
- [ ] Send sensor data from the glove.
- [ ] Convert sensor data into joint movement.
- [ ] Test synchronized movement.
- [ ] Test communication failure handling.

## 9. Implementation Notes

This wiring document represents the proposed architecture.

Final GPIO assignments, power supply specifications, connector types and wiring dimensions must be verified against the exact hardware models before physical assembly.

Never connect unverified components directly to the power supply.
