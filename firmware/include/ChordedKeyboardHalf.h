
#ifndef CHORDEDKEYBOARDHALF_H
#define CHORDEDKEYBOARDHALF_H

#include <Arduino.h>

#define NUM_KEYS 5

using SwitchPinArray = uint32_t[5];
using Chord = uint8_t;

class ChordedKeyboardHalf
{
public:
    void setup();
    virtual void loop() = 0;    

protected:
    ChordedKeyboardHalf(const SwitchPinArray& switchPins) : switchPins(switchPins) { };

    virtual void setupBleConnection() = 0;

    void hardReset();

    const SwitchPinArray& switchPins;

    Chord getCurrentChord();

private:
    void setupPins() const;
};

#endif