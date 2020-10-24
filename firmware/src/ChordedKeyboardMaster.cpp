#include <ChordedKeyboardMaster.h>

constexpr SwitchPinArray ChordedKeyboardMaster::switchPins;

Chord ChordedKeyboardMaster::slaveChord;

ChordedKeyboardMaster::ChordedKeyboardMaster() : ChordedKeyboardHalf(switchPins)
{
    Serial.println("Running in MASTER mode");
    bleSlaveConnection.setOnInputReceivedCallback(onSlaveInputReceived);
}

void ChordedKeyboardMaster::onSlaveInputReceived(Chord chord) {
    slaveChord = chord;
}

void ChordedKeyboardMaster::setupBleConnection() 
{
    Serial.println("ChordedKeyboardMaster::setupBleConnection");
    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 1);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys1");

    bleSlaveConnection.setup();
    bleHidConnection.setup(bleHidService);
}

//int pendingChord = 0;
bool pressed = false;
bool slavePressed = false;
uint32_t lastTime = 0;

void ChordedKeyboardMaster::loop()
{
    uint32_t timeNow = millis();
    if (timeNow - lastTime > 1500) {
        lastTime = timeNow;
        Serial.println("Master is ALIVE");
    }


    delay(10);
    
    if (slaveChord != 0) {
        bleHidService.keyPress('S');
        delay(10);
        bleHidService.keyRelease();
    }
    uint8_t pressCount = 0;
    bool keyPressed = false;
    for (uint8_t n = 0; n < NUM_KEYS; n++) {
        if (digitalRead(switchPins[n]) == LOW) {
            keyPressed = true;
            pressCount++;
        }
    }

    if (pressCount > 3) {
        hardReset();
    }

    if (keyPressed && !pressed) {
        Serial.println("PRESS");
        pressed = true;
    }
    else if (!keyPressed && pressed) {
        Serial.println("RELEASE");
        pressed = false;
        bleHidService.keyPress('M');
        delay(10);
        bleHidService.keyRelease();
    }

    digitalWrite(LED_BUILTIN, keyPressed ? HIGH : LOW);

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

