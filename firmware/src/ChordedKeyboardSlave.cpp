#include <ChordedKeyboardSlave.h>

constexpr SwitchPinArray ChordedKeyboardSlave::switchPins;

ChordedKeyboardSlave::ChordedKeyboardSlave() : ChordedKeyboardHalf(switchPins)
{
    Serial.println("Running in SLAVE mode");
}

void ChordedKeyboardSlave::setupBleConnection()
{
    Serial.println("ChordedKeyboardSlave::setupBleConnection");

    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 0);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys (Slave)");

    bleMasterConnection.setup(masterUartService);
}

void ChordedKeyboardSlave::loop()
{
    Chord currentChord = 0;
    for (uint8_t i = 0; i < NUM_KEYS; i++) {
        if (digitalRead(switchPins[i]) == LOW) {
            currentChord = currentChord | (1 << i);
        }
    } 

    if (currentChord != previousChord) {
        Serial.printf("Sending to master: %d\n", currentChord);

        previousChord = currentChord;
        masterUartService.write(currentChord);
        masterUartService.flush();
    }        
}