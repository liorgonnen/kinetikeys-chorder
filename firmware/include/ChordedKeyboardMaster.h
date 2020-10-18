#ifndef CHORDEDKEYBOARDMASTER_H
#define CHORDEDKEYBOARDMASTER_H

#include <Arduino.h>
#include <ChordedKeyboardHalf.h>
#include <BLECentralConnection.h>
#include <BLEPeripheralConnection.h>

#define KEY_M_P PIN_A0
#define KEY_M_R PIN_A1
#define KEY_M_M PIN_A2
#define KEY_M_I PIN_A3
#define KEY_M_T PIN_A4

// Dummy key map for now
/*char KEY_VALUES[] = {
  'a',
  'b',
  'c',
  'd',
  'e',
  'f',
  'g',
  'h',
  'i',
  'j',
  'k',
  'l',
  'm',
  'n',
  'o',
  'p',
  'q',
  'r',
  's',
  't',
  'u',
  'v',
  'w',
  'x',
  'y',
  'z',
};*/

//const int NUM_KEY_VALUES = (sizeof(KEY_VALUES) / sizeof(char));

class ChordedKeyboardMaster : public ChordedKeyboardHalf
{
public:
    ChordedKeyboardMaster();

    void loop() override;

protected:
    void setupBleConnection() override;

    BLEHidAdafruit bleHidService;
    BLEPeripheralConnection bleHidConnection;
    BLECentralConnection bleSlaveConnection;

    constexpr static SwitchPinArray switchPins = { KEY_M_P, KEY_M_R, KEY_M_M, KEY_M_I, KEY_M_T };
};

#endif