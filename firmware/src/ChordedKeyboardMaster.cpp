#include <ChordedKeyboardMaster.h>

constexpr SwitchPinArray ChordedKeyboardMaster::switchPins;

ChordedKeyboardMaster::ChordedKeyboardMaster() : ChordedKeyboardHalf(switchPins)
{
    Serial.println("Running in MASTER mode");
}

//int pendingChord = 0;
void ChordedKeyboardMaster::loop()
{
    if (!bleSlaveConnection.isSlaveConnected()) {
        return;
    }
    
//   int currentChord = 0;
//   for (uint8_t i = 0; i < NUM_KEYS; i++) {
//     if (digitalRead(KEYS[i]) == LOW) {
//       currentChord = currentChord | (1 << i);
//     }
//   }

//   delay(10);

//   if (currentChord != pendingChord) {
//     Serial.println(currentChord);
//     if (currentChord == 0) {
//       if (pendingChord <= NUM_KEY_VALUES) {
//         bleHidService.keyPress(KEY_VALUES[pendingChord - 1]);
//         delay(5);
//         bleHidService.keyRelease();
//         delay(5);
//       }
//       pendingChord = 0;
//     } 
//     else {
//       pendingChord |= currentChord;
//     }
//   }
}

void ChordedKeyboardMaster::setupBleConnection() 
{
    Serial.println("ChordedKeyboardMaster::setupBleConnection");
    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 1);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys");

    bleHidConnection.setup(bleHidService);
    bleSlaveConnection.setup();
}
