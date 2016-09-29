/*
  MeccanoIr.h - Not a "real" library for MECCANO / ERECTOR IR devices - just put it in the same folder as your sketch.
  Created by TheDIYGuy999 September 2016
  Released into the public domain.
*/

#ifndef MeccanoIr_h
#define MeccanoIr_h

#include "Arduino.h"

//
// =======================================================================================================
// IR CODE DEFINITION
// =======================================================================================================
//

// Meccano binary code: // means "1", no marking means "0"

// CHANNEL A *************************************************

// A + IR code---------------------------
byte IrSignalAplus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 60, //
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  30, 60, //
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  120, 240 
};

// A - IR code---------------------------
byte IrSignalAminus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 30,
  30, 60, //
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  30, 30,
  30, 60, //
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  120, 240 
};

// CHANNEL B *************************************************

// B + IR code---------------------------
byte IrSignalBplus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 60, //
  30, 30,
  30, 30, 
  30, 60, //
  30, 30, 
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 60, // 
  30, 30, 
  30, 30,
  120, 240 
};

// B - IR code---------------------------
byte IrSignalBminus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 30,
  30, 60, //
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  30, 60, //
  30, 30, 
  30, 60, //
  30, 30,
  30, 30,
  120, 240 
};

// CHANNEL C *************************************************

// C + IR code---------------------------
byte IrSignalCplus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 60, // 
  30, 30, 
  30, 30, 
  30, 30, 
  30, 60, //
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 30, 
  30, 60, //
  30, 30,
  120, 240 
};

// C - IR code---------------------------
byte IrSignalCminus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 60, //
  30, 30,
  30, 30,
  30, 60, //
  30, 30, 
  30, 30,
  30, 60, //
  30, 30,
  120, 240 
};

// CHANNEL D *************************************************

// D + IR code---------------------------
byte IrSignalDplus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 60, //
  30, 30,
  30, 30, 
  30, 30, 
  30, 30,
  30, 60, //
  30, 60, //
  30, 30,
  30, 30,
  30, 30,
  30, 30,
  30, 60, //
  120, 240 
};

// D - IR code---------------------------
byte IrSignalDminus[] = {
  // ON, OFF (in 10's of microseconds)
  180, 180,
  30, 30,
  30, 60, //
  30, 30,
  30, 30, 
  30, 30,
  30, 60, //
  30, 30,
  30, 60, //
  30, 30, 
  30, 30,
  30, 30,
  30, 60, //
  120, 240 
};

//
// =======================================================================================================
// IR SIGNAL GENERATION
// =======================================================================================================
//

void buildIrSignal(byte IrSignal[], byte s) {
  for (int i = 0; i < (s - 1); i = i + 2) {
    // This procedure sends an 38KHz modulated hi-pulse to the IRledPin----
    long microsecs = IrSignal[i] * 10;
    while (microsecs > 0) {
      // 38 kHz is about 13 microseconds high and 13 microseconds low
      digitalWrite(3, HIGH);
#if F_CPU == 16000000 // 16MHz CPU
      delayMicroseconds(10);
#endif
      digitalWrite(3, LOW);
#if F_CPU == 16000000 // 16MHz CPU
      delayMicroseconds(10);
#endif
      microsecs -= 26; // 38KHz = 13us hi / 13us lo
    }

    // IRledPin low delay----
    delayMicroseconds(IrSignal[i + 1] * 10);

  } // End of for loop
  delay(70);
}

#endif
