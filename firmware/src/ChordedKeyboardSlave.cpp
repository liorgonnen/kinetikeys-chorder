#include <ChordedKeyboardSlave.h>

constexpr SwitchPinArray ChordedKeyboardSlave::switchPins;

ChordedKeyboardSlave::ChordedKeyboardSlave() : ChordedKeyboardHalf(switchPins)
{
    Serial.println("Running in SLAVE mode");
}

void ChordedKeyboardSlave::setupBleConnection()
{
    Serial.println("ChordedKeyboardSlave::setupBleConnection - Begin");

    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 0);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys (Slave)");

    bleMasterConnection.setup(masterUartService);

    Serial.println("ChordedKeyboardSlave::setupBleConnection - End");
}

// uint32_t lastPrintTime = 0;

void ChordedKeyboardSlave::loop()
{
    if (!Bluefruit.connected()) {
        return;
    }

    Chord currentChord = getCurrentChord();

    digitalWrite(LED_BUILTIN, (currentChord != 0) ? HIGH : LOW);

    if (currentChord != previousChord) {
        Serial.printf("Sending to master: %d\n", currentChord);
        previousChord = currentChord;
        masterUartService.write(currentChord);
    }          
}