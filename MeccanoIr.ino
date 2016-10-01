/* Example sketch for the MECCANO / ERECTOR IR LIBRARY
  Created by TheDIYGuy999, September 2016
*/

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
  if (joystickA < 10) buildIrSignal(1); // A +
  if (joystickA > 90) buildIrSignal(2); // A -
  if (joystickB < 10) buildIrSignal(3); // B +
  if (joystickB > 90) buildIrSignal(4); // B -
  if (joystickC < 10) buildIrSignal(5); // C +
  if (joystickC > 90) buildIrSignal(6); // C -
  if (joystickD < 10) buildIrSignal(7); // D +
  if (joystickD > 90) buildIrSignal(8); // D -
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
