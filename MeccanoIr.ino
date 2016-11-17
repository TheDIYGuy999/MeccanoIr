/* Example sketch for the MECCANO / ERECTOR IR LIBRARY
  Created by TheDIYGuy999, September - November 2016
*/

const float codeVersion = 1.1; // Software revision

//
// =======================================================================================================
// INCLUDE LIRBARIES & TABS
// =======================================================================================================
//

#include "MeccanoIr.h"

//
// =======================================================================================================
// GLOBAL VARIABLES
// =======================================================================================================
//

short joystickA;
short joystickB;
short joystickC;
short joystickD;

//
// =======================================================================================================
// MAIN ARDUINO SETUP (1x during startup)
// =======================================================================================================
//

void setup() {
  pinMode(3, OUTPUT); // The IR transmitter LED Pin (hardcoded in the MeccanoIr.h!)
}

//
// =======================================================================================================
// JOYSTICKS
// =======================================================================================================
//

void readJoysticks() {
  joystickA = map(analogRead(A0), 0, 1023, 0, 100);
  joystickB = map(analogRead(A1), 0, 1023, 0, 100);
  joystickC = map(analogRead(A2), 0, 1023, 0, 100);
  joystickD = map(analogRead(A3), 0, 1023, 0, 100);
}

//
// =======================================================================================================
// TRANSMIT MECCANO / ERECTOR IR SIGNAL
// =======================================================================================================
//

void transmitMeccanoIr() {

  static boolean A;
  static boolean B;
  static boolean C;
  static boolean D;

  // Channel A ----
  if (joystickA > 90) { // A +
    buildIrSignal(1);
    A = true;
  }
  if (joystickA < 10) { // A -
    buildIrSignal(2), A = true;
    A = true;
  }
  if (joystickA < 90 && joystickA > 10 && A) { // A OFF
    buildIrSignal(3);
    A = false;
  }

  // Channel B ----
  if (joystickB > 90) { // B +
    buildIrSignal(4);
    B = true;
  }
  if (joystickB < 10) { // B -
    buildIrSignal(5), A = true;
    B = true;
  }
  if (joystickB < 90 && joystickB > 10 && B) { // B OFF
    buildIrSignal(6);
    B = false;
  }

  // Channel C ----
  if (joystickC > 90) { // C +
    buildIrSignal(7);
    C = true;
  }
  if (joystickC < 10) { // C -
    buildIrSignal(8), A = true;
    C = true;
  }
  if (joystickC < 90 && joystickC > 10 && C) { // C OFF
    buildIrSignal(9);
    C = false;
  }

  // Channel D ----
  if (joystickD > 90) { // D +
    buildIrSignal(10);
    D = true;
  }
  if (joystickD < 10) { // D -
    buildIrSignal(11), A = true;
    D = true;
  }
  if (joystickD < 90 && joystickD > 10 && D) { // D OFF
    buildIrSignal(12);
    D = false;
  }
}

//
// =======================================================================================================
// MAIN LOOP
// =======================================================================================================
//

void loop() {
  readJoysticks();
  transmitMeccanoIr();
}
