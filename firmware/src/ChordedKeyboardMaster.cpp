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

bool pressed = false;
bool slavePressed = false;
//uint32_t lastTime = 0;
uint8_t pendingChord = 0;

void ChordedKeyboardMaster::loop()
{
    // uint32_t timeNow = millis();
    // if (timeNow - lastTime > 1500) {
    //     lastTime = timeNow;
    //     Serial.println("Master is ALIVE");
    // }

    int currentChord = 0;
    for (uint8_t i = 0; i < NUM_KEYS; i++) {
        if (digitalRead(switchPins[i]) == LOW) {
            currentChord = currentChord | (1 << i);
        }
    }

    delay(10);

    if (currentChord != pendingChord) {
        if (currentChord == 0) {
            if (pendingChord <= LEFT_HAND_SIZE && pendingChord != 0) {
                char key = LEFT_HAND[pendingChord];
                if (key != 0) {
                    Serial.printf("(0x%x) Sending: %c\n", pendingChord, key);
                    bleHidService.keyPress(key);
                    delay(5);
                    bleHidService.keyRelease();
                    delay(5);
                }
            }
            pendingChord = 0;
        }
        else {
           pendingChord |= currentChord;
        }
    } 

    delay(10);
    
    if (slaveChord != 0) {
        bleHidService.keyPress('S');
        delay(10);
        bleHidService.keyRelease();
    }
}

