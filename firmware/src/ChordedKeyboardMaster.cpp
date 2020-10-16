#include <ChordedKeyboardMaster.h>

ChordedKeyboardMaster::ChordedKeyboardMaster() : ChordedKeyboardHalf()
{
    Serial.println("Running in MASTER mode");
}

//int pendingChord = 0;
void ChordedKeyboardMaster::loop()
{
    // Dummy code for testing begins
    uint16_t p1 = digitalRead(KEY_M_P);
    uint16_t p2 = digitalRead(KEY_M_R);
    uint16_t p3 = digitalRead(KEY_M_M);
    uint16_t p4 = digitalRead(KEY_M_I);
    uint16_t p5 = digitalRead(KEY_M_T);

    if (p1 == LOW) Serial.print("P");
    if (p2 == LOW) Serial.print("R");
    if (p3 == LOW) Serial.print("M");
    if (p4 == LOW) Serial.print("I");
    if (p5 == LOW) Serial.print("T");

    if (p1 == LOW || p2 == LOW || p3 == LOW || p4 == LOW || p5 == LOW) {
        Serial.println();
    }

    if (p1 == LOW && p2 == LOW && p3 == LOW && p4 == LOW && p5 == LOW) {
        Serial.println("RESET!");
        hardReset();
    }
    // Dummy code for testing ends

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

void ChordedKeyboardMaster::setupPins() const 
{
    Serial.println("ChordedKeyboardMaster::setupPins");

    pinMode(LED_BUILTIN, OUTPUT);

    // Dummy code for testing
    pinMode(KEY_M_P, INPUT_PULLUP);
    pinMode(KEY_M_R, INPUT_PULLUP);
    pinMode(KEY_M_M, INPUT_PULLUP);
    pinMode(KEY_M_I, INPUT_PULLUP);
    pinMode(KEY_M_T, INPUT_PULLUP);
    
//   for (uint8_t i = 0; i < NUM_KEYS; i++) {
//     pinMode(KEYS[i], INPUT_PULLUP);
//   }
}