
# Sensor Calibration

## 1. Overview

Sensor calibration is an essential process in the 15-DOF Robotic Hand Motion Control project.

It ensures that the wearable glove accurately detects finger bending and wrist orientation, allowing the robotic hand to reproduce human movements consistently.

The calibration process covers:

- Flex sensor calibration.
- IMU calibration.
- Sensor range mapping.
- Servo position calibration.

## 2. Flex Sensor Calibration

Flex sensors measure the bending of the fingers.

Each sensor produces an analog value that changes according to the bending angle.

### Calibration Procedure

1. Place the glove on the user's hand.
2. Keep the finger fully extended.
3. Record the sensor reading.
4. Slowly bend the finger completely.
5. Record the second sensor reading.
6. Repeat the process for each finger.
7. Store the calibration values.

### Calibration Values

| Finger | Minimum Reading | Maximum Reading |
|---|---:|---:|
| Thumb | To be measured | To be measured |
| Index | To be measured | To be measured |
| Middle | To be measured | To be measured |
| Ring | To be measured | To be measured |
| Little | To be measured | To be measured |

The values must be measured experimentally and must not be assumed.

## 3. IMU Calibration

The IMU sensor measures wrist orientation and movement.

### Calibration Procedure

1. Place the glove in a neutral position.
2. Keep the wrist straight and still.
3. Initialize the IMU sensor.
4. Record the initial orientation.
5. Move the wrist through its intended range of motion.
6. Check that the readings change consistently.
7. Store the neutral reference position.

The IMU calibration should also account for sensor offsets and measurement noise.

## 4. Sensor Data Mapping

The sensor readings are converted into normalized movement values.

For flex sensors, the measured range is mapped to a percentage between 0% and 100%.

The mapping must account for sensors whose readings increase or decrease when bent.

## 5. Servo Position Calibration

Each servo motor must be calibrated individually.

The calibration process includes:

- Identifying the safe minimum position.
- Identifying the safe maximum position.
- Setting the neutral position.
- Checking the mechanical limits.
- Matching servo movement to the corresponding finger movement.

Servo limits must be established through testing to prevent mechanical damage.

## 6. Calibration Data Storage

The calibration values should be stored in the glove controller firmware.

Recommended parameters include:

- Flex sensor minimum values.
- Flex sensor maximum values.
- IMU neutral orientation.
- Servo minimum positions.
- Servo maximum positions.
- Servo movement direction.

## 7. Calibration Validation

After calibration, the system should be tested.

Validation tests include:

- Fully opening the hand.
- Closing each finger independently.
- Testing different finger bending angles.
- Moving the wrist in different directions.
- Checking whether the robotic hand follows the glove.
- Repeating movements to verify consistency.

## 8. Development Status

This document defines the proposed calibration procedure.

Actual sensor readings, IMU offsets and servo limits must be recorded during hardware testing.

Calibration values are not considered final until they have been measured and validated on the physical prototype.

