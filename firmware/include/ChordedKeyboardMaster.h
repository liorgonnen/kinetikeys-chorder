#ifndef CHORDEDKEYBOARDMASTER_H
#define CHORDEDKEYBOARDMASTER_H

#include <ChordedKeyboardHalf.h>
#include <Arduino.h>

class ChordedKeyboardMaster : public ChordedKeyboardHalf
{
public:
    ChordedKeyboardMaster();

    void setup() override;
    void loop() override;

private:
    void setupPins() const;
};

#endif