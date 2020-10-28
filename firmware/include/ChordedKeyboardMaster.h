#ifndef CHORDEDKEYBOARDMASTER_H
#define CHORDEDKEYBOARDMASTER_H

#include <Arduino.h>
#include <ChordedKeyboardHalf.h>
#include <BLECentralConnection.h>
#include <BLEPeripheralConnection.h>

#define KEY_M_I PIN_A0
#define KEY_M_M PIN_A1
#define KEY_M_R PIN_A2
#define KEY_M_P PIN_A3
#define KEY_M_T PIN_A4

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

    Chord pendingChord = 0;
    Chord slavePendingChord = 0;

    static void onSlaveInputReceived(Chord chord);

    static Chord slaveChord;

    constexpr static SwitchPinArray switchPins = { KEY_M_T, KEY_M_I, KEY_M_M, KEY_M_R, KEY_M_P };

private:
    void sendKey(const char key);
    void processKey(Chord currentChord, Chord& pendingChord, char keymap[], size_t keymapSize);
};

#endif