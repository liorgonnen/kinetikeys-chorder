#include <ChordedKeyboardMaster.h>

ChordedKeyboardMaster::ChordedKeyboardMaster() : ChordedKeyboardHalf()
{
    Serial.println("Running in SLAVE mode");
}

void ChordedKeyboardMaster::setup()
{
    Serial.println("ChordedKeyboardMaster::setup");
    setupPins();
}

void ChordedKeyboardMaster::loop()
{
    Serial.println("ChordedKeyboardMaster::loop");
}

void ChordedKeyboardMaster::setupPins() const {
  // initialize LED digital pin as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
  
  
//   for (uint8_t i = 0; i < NUM_KEYS; i++) {
//     pinMode(KEYS[i], INPUT_PULLUP);
//   }
}