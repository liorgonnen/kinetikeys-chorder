#include <ChordedKeyboardSlave.h>

ChordedKeyboardSlave::ChordedKeyboardSlave()
{
    Serial.println("Running in SLAVE mode");
}

void ChordedKeyboardSlave::setupPins() const
{
    Serial.println("ChordedKeyboardSlave::setupPins");
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
    
}