#include <ChordedKeyboardMaster.h>
#include <Keymap.h>

constexpr SwitchPinArray ChordedKeyboardMaster::switchPins;

Chord ChordedKeyboardMaster::slaveChord;

ChordedKeyboardMaster::ChordedKeyboardMaster() : ChordedKeyboardHalf(switchPins)
{
    Serial.println("Running in MASTER mode");
    bleSlaveConnection.setOnInputReceivedCallback(onSlaveInputReceived);
}

void ChordedKeyboardMaster::onSlaveInputReceived(Chord chord) {
    Serial.println("ChordedKeyboardMaster::onSlaveInputReceived");
    slaveChord = chord;
}

void ChordedKeyboardMaster::setupBleConnection() 
{
    Serial.println("ChordedKeyboardMaster::setupBleConnection");
    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 1);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys");

    bleSlaveConnection.setup();
    bleHidConnection.setup(bleHidService);
}

void ChordedKeyboardMaster::loop()
{
    processKey(getCurrentChord(), pendingChord, LEFT_HAND, LEFT_HAND_SIZE);

    processKey(slaveChord, slavePendingChord, RIGHT_HAND, RIGHT_HAND_SIZE);

    delay(10);
}

void ChordedKeyboardMaster::processKey(Chord currentChord, Chord& pendingChord, char keymap[], size_t keymapSize) {
    // If the current chord is the same as the pending one, there's nothing to do
    if (currentChord == pendingChord) {
        return;
    }

    // If any key is still pressed, update the pending chord
    if (currentChord != 0) {
        pendingChord |= currentChord;
        return;
    }

    if (pendingChord < keymapSize && pendingChord != 0) {
        sendKey(keymap[pendingChord]);
    }

    pendingChord = 0;
}

void ChordedKeyboardMaster::sendKey(const char key) {
    if (key != 0) {
        Serial.printf("Sending: %c\n", key);
        bleHidService.keyPress(key);
        delay(10);
        bleHidService.keyRelease();
    }
}

