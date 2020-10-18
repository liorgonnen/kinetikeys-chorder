#ifndef CHORDEDKEYBOARDMSLAVE_H
#define CHORDEDKEYBOARDMSLAVE_H

#include <ChordedKeyboardHalf.h>
#include <BLEPeripheralConnection.h>
#include <Arduino.h>

#define KEY_S_P 9
#define KEY_S_R 10
#define KEY_S_M 11
#define KEY_S_I 12
#define KEY_S_T 13

class ChordedKeyboardSlave : public ChordedKeyboardHalf
{
public:
    ChordedKeyboardSlave();

protected:
    void setupBleConnection() override;
    void loop() override;

private:
    Chord previousChord = 0;
    BLEUart masterUartService;
    BLEPeripheralConnection bleMasterConnection;

    constexpr static SwitchPinArray switchPins = { KEY_S_P, KEY_S_R, KEY_S_M, KEY_S_I, KEY_S_T };
};

#endif