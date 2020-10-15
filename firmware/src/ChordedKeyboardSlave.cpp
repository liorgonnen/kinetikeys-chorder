#include <ChordedKeyboardSlave.h>

ChordedKeyboardSlave::ChordedKeyboardSlave()
{
    Serial.println("Running in SLAVE mode");
}

void ChordedKeyboardSlave::setup()
{
    Serial.println("ChordedKeyboardSlave::setup");
}

void ChordedKeyboardSlave::loop()
{
    Serial.println("ChordedKeyboardSlave::loop");
}