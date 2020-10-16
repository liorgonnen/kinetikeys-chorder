#ifndef CHORDEDKEYBOARDMASTER_H
#define CHORDEDKEYBOARDMASTER_H

#include <Arduino.h>
#include <ChordedKeyboardHalf.h>
#include <BLECentralConnection.h>
#include <BLEPeripheralConnection.h>

#define NUM_KEYS 5

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
    void setupPins() const override;
    void setupBleConnection() override;

    BLEHidAdafruit bleHidService;
    BLEPeripheralConnection bleHidConnection;
    BLECentralConnection bleSlaveConnection;
};

#endif