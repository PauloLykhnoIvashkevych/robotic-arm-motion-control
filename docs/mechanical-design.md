
# Mechanical Design – 15-DOF Robotic Hand

## 1. Overview

This document describes the mechanical design of the 15-DOF robotic hand and wrist.

The system is designed to reproduce human hand movements using 15 independently controlled servo motors.

The mechanical structure must provide sufficient movement, stability, durability and precision while maintaining a human-like hand shape.

## 2. Degrees of Freedom (DOF)

The robotic hand will have 15 degrees of freedom distributed across the fingers and wrist.

| Joint Group | Degrees of Freedom |
|---|---:|
| Thumb | 2 |
| Index Finger | 3 |
| Middle Finger | 3 |
| Ring Finger | 3 |
| Little Finger | 3 |
| Wrist | 1 |
| **Total** | **15** |

Each degree of freedom represents an independently controlled movement.

## 3. Finger Structure

Each finger consists of mechanical segments connected by rotating joints.

### 3.1 Finger Segments

The mechanical structure will reproduce the main anatomical sections of human fingers:

- Proximal phalanx.
- Middle phalanx.
- Distal phalanx.

The thumb will use a simplified mechanical structure adapted to its different anatomy.

### 3.2 Finger Movement

The robotic fingers will reproduce bending and extension movements.

The mechanical design must allow:

- Independent finger movement.
- Coordinated finger bending.
- Hand opening and closing.
- Natural movement limits.
- Stable joint alignment.

## 4. Wrist Mechanism

The wrist will provide one degree of freedom.

The mechanism will allow a controlled wrist movement while supporting the weight of the robotic hand.

The wrist structure must provide:

- Mechanical stability.
- Secure servo mounting.
- Controlled movement range.
- Protection against excessive movement.

## 5. Servo Motor Integration

A total of 15 servo motors will control the robotic joints.

Each servo will be assigned to a specific degree of freedom.

Servo mounting positions must consider:

- Available mechanical space.
- Required torque.
- Joint movement range.
- Cable routing.
- Ease of maintenance.

The final servo placement will depend on the selected motor dimensions and mechanical prototypes.

## 6. Mechanical Transmission

The project will evaluate suitable transmission mechanisms for transferring servo movement to the finger joints.

Possible solutions include:

- Direct servo-to-joint connections.
- Tendon or cable-driven mechanisms.
- Linkage-based mechanisms.

The final solution will be selected according to movement precision, available space, mechanical complexity and durability.

## 7. Materials and Manufacturing

The robotic hand may use 3D-printed components for its structural parts.

Candidate materials include:

| Material | Potential Application |
|---|---|
| PLA | Initial prototypes |
| PETG | Stronger structural components |
| TPU | Flexible parts and protective elements |
| Metal fasteners | Joint connections and reinforcement |

Material selection will depend on mechanical testing and component availability.

## 8. Mechanical Assembly

The assembly process is expected to follow these stages:

1. Manufacture the palm structure.
2. Manufacture the finger segments.
3. Assemble finger joints.
4. Install the servo motors.
5. Connect the mechanical transmission system.
6. Assemble the wrist mechanism.
7. Route and secure electrical cables.
8. Test each joint independently.

## 9. Mechanical Safety

The mechanical design must include:

- Physical movement limits.
- Secure servo mounting.
- Reinforced joint connections.
- Protection against cable entanglement.
- Prevention of excessive joint movement.
- Accessible components for maintenance.

The structure must also prevent mechanical interference between adjacent fingers.

## 10. Testing and Validation

The mechanical prototype will be evaluated through:

- Individual finger movement tests.
- Full hand opening and closing.
- Wrist movement tests.
- Joint alignment inspection.
- Servo mounting stability tests.
- Repeated movement tests.
- Mechanical interference checks.

The final design must demonstrate stable and repeatable movement.

## 11. Current Development Status

Phase: Mechanical design and prototyping.

The joint distribution and general mechanical architecture are defined as preliminary design decisions.

Final dimensions, servo mounting positions, transmission mechanisms and materials must be validated through CAD design and physical prototyping.

