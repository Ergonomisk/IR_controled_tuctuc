# IR_controled_tuctuc
 # IR Remote Controlled Tuctuc

**Author**: Erik Ovuka Andersson  
**Date**: 2025-02-07  

## Project Overview
This project enables an autonomous **Tuctuc** vehicle to be controlled via an **IR remote**. The vehicle can move forward, turn left, turn right, and operate a servo motor using specific IR remote commands. The system is built using an **Arduino**, an **IR receiver**, and motor control through relays.

## Features
- **IR Remote Control**: Receives and decodes IR signals to control the Tuctuc.
- **Directional Movement**: Supports forward movement, left turns, and right turns.
- **Servo Motor Control**: The servo motor can be rotated via remote commands.
- **Relay-Based Motor Actuation**: Uses relays to switch the motors on and off.

## Components
1. **Arduino-compatible microcontroller**
2. **IR Receiver Module** (e.g., TSOP1838)
3. **Relay Modules** for motor control
4. **Servo Motor** (e.g., SG90)
5. **Remote Control** (IR-based, compatible with the IR receiver)
6. **Power Supply** (Battery pack or external power source)

## Libraries Used
1. **IRremote** ([GitHub](https://github.com/Arduino-IRremote/Arduino-IRremote)) - For decoding IR signals
2. **Servo** - For controlling the servo motor
3. **Arduino Core** - Standard Arduino functions

## Pin Configuration
| Component          | Pin Number |
|--------------------|------------|
| **Left Wheel Relay**  | 4 |
| **Right Wheel Relay** | 7 |
| **Servo Motor**       | 3 |
| **IR Receiver**       | Defined in `PinDefinitionsAndMore.h` |

## Setup Instructions
1. **Install Required Libraries**: Download and install the **IRremote** and **Servo** libraries using the Arduino Library Manager.
2. **Connect Components**: Wire the **IR receiver**, **relays**, and **servo motor** to the Arduino as per the pin configuration above.
3. **Upload Code**: Compile and upload the code to the Arduino using the **Arduino IDE**.
4. **Test with Remote**: Use the IR remote to control the **Tuctuc** and verify movement and servo functionality.

## Function Descriptions
- **`goForward()`** - Activates both wheel relays to move forward.
- **`turnLeft()`** - Activates the right wheel relay to turn left.
- **`turnRight()`** - Activates the left wheel relay to turn right.
- **IR Signal Handling**:
  - `0x46` → Move forward
  - `0x44` → Turn left
  - `0x43` → Turn right
  - `0x40` → Move servo motor

## Usage Instructions
1. **Power the system on**.
2. **Point the IR remote at the receiver** and press the corresponding buttons to move the Tuctuc.
3. **Observe movement and servo responses** to confirm correct functionality.

## Future Improvements
- Add **speed control** using PWM for smoother movement.
- Implement **obstacle detection** with ultrasonic sensors.
- Enable **autonomous navigation** using sensor fusion techniques.

## License
This project is **open-source** under the **MIT License**. See [LICENSE](LICENSE) for details.

