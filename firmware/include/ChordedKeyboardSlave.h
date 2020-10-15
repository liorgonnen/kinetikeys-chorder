#ifndef CHORDEDKEYBOARDMSLAVE_H
#define CHORDEDKEYBOARDMSLAVE_H

#include <ChordedKeyboardHalf.h>
#include <Arduino.h>

class ChordedKeyboardSlave : public ChordedKeyboardHalf
{
public:
    ChordedKeyboardSlave();

    void setup() override;
    void loop() override;
};

#endif