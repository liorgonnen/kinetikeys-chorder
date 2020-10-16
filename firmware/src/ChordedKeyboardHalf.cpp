#include <ChordedKeyboardHalf.h>

void(* resetFunc) (void) = 0; //declare reset function at address 0

void ChordedKeyboardHalf::setup() 
{
    setupPins();
    setupBleConnection();
}

void ChordedKeyboardHalf::hardReset() 
{
    resetFunc();
}