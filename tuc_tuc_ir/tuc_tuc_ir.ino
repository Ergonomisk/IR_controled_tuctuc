/*
* Name: IR Remote Controlled Tuctuc
* Author: Erik Ovuka Andersson
* Date:  2025-02-07
* Description: This project uses an IR remote to control a tuctuc's movement.
* The tuctuc moves forward, turns left, turns right, and can control a servo motor.
*/

// Include necessary libraries
#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
#include <Servo.h>

// Init constants
const int relay_l_wheel = 4;
const int relay_r_wheel = 7;
const int servoPin = 3;

// Construct objects
Servo Servo1;

void setup() {
    // Init communication
    Serial.begin(115200);
    while (!Serial);

    // Output start information
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    // Init IR receiver
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
    Serial.println(F(" at pin " STR(IR_RECEIVE_PIN)));

    // Init hardware
    pinMode(relay_l_wheel, OUTPUT);
    pinMode(relay_r_wheel, OUTPUT);
    Servo1.attach(servoPin);
}

void loop() {
    // Check if an IR signal has been received and decoded
    if (IrReceiver.decode()) {

        // Handle unknown IR protocols
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            IrReceiver.printIRResultRawFormatted(&Serial, true);
            IrReceiver.resume();
        } else {
            // Print decoded IR signal
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.printIRSendUsage(&Serial);
            IrReceiver.resume();
        }
        Serial.println();

        // Handle IR commands
        switch (IrReceiver.decodedIRData.command) {
          case 0x43:  // Turn right
            turnRight();
            break;
          case 0x44:  // Turn left
            turnLeft();
            break;
          case 0x46:  // Move forward
            goForward();
            break;
          case 0x40:  // Control servo
            Servo1.write(0);
            delay(500);
            Servo1.write(90);
            break;
        }
    }
}

/*
* Moves the robot forward
* Parameters: void
* Returns: void
*/
void goForward() {
  digitalWrite(relay_r_wheel, HIGH);
  digitalWrite(relay_l_wheel, HIGH);
  delay(200);
  digitalWrite(relay_r_wheel, LOW);
  digitalWrite(relay_l_wheel, LOW);
}

/*
* Turns the robot left
* Parameters: void
* Returns: void
*/
void turnLeft() {
  digitalWrite(relay_r_wheel, HIGH);
  delay(50);
  digitalWrite(relay_r_wheel, LOW);
}

/*
* Turns the robot right
* Parameters: void
* Returns: void
*/
void turnRight() {
  digitalWrite(relay_l_wheel, HIGH);
  delay(50);
  digitalWrite(relay_l_wheel, LOW);
}
