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
    // uint32_t timeNow = millis();
    // if (timeNow - lastPrintTime > 1500) {
    //     lastPrintTime = timeNow;
    //     Serial.println("Slave is ALIVE");
    // }

    // while (masterUartService.available()) {
    //     uint8_t ch = (uint8_t) masterUartService.read();
    //     Serial.printf("Received: %c", ch);
    // }

    bool keyPressed = false;
    Chord currentChord = 0;
    for (uint8_t i = 0; i < NUM_KEYS; i++) {
        if (digitalRead(switchPins[i]) == LOW) {
            currentChord = currentChord | (1 << i);
            keyPressed = true;
        }
    } 

    digitalWrite(LED_BUILTIN, keyPressed ? HIGH : LOW);

    if (currentChord != previousChord) {
        if (Bluefruit.connected()) {
            Serial.printf("Sending to master: %d\n", currentChord);
            previousChord = currentChord;
            masterUartService.write(currentChord);
        } else {
            Serial.println("Not connected to master yet");
        }
    }          
}