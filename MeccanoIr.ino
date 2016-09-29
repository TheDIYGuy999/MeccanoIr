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

  if (joystickA > 90) buildIrSignal(IrSignalAplus, (sizeof(IrSignalAplus) / sizeof(byte))); // A +
  if (joystickA < 10) buildIrSignal(IrSignalAminus, (sizeof(IrSignalAminus) / sizeof(byte))); // A -

  if (joystickB > 90) buildIrSignal(IrSignalBplus, (sizeof(IrSignalBplus) / sizeof(byte))); // B +
  if (joystickB < 10) buildIrSignal(IrSignalBminus, (sizeof(IrSignalBminus) / sizeof(byte))); // B -

  if (joystickC > 90) buildIrSignal(IrSignalCplus, (sizeof(IrSignalCplus) / sizeof(byte))); // C +
  if (joystickC < 10) buildIrSignal(IrSignalCminus, (sizeof(IrSignalCminus) / sizeof(byte))); // C -

  if (joystickD > 90) buildIrSignal(IrSignalDplus, (sizeof(IrSignalDplus) / sizeof(byte))); // D +
  if (joystickD < 10) buildIrSignal(IrSignalDminus, (sizeof(IrSignalDminus) / sizeof(byte))); // D -
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
