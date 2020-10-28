#include <ChordedKeyboardHalf.h>

void (*resetFunc)(void) = 0; // Declare reset function at address 0

void ChordedKeyboardHalf::setup() 
{
    Serial.println("ChordedKeyboardHalf::setup");

    setupPins();
    setupBleConnection();
}

void ChordedKeyboardHalf::setupPins() const
{
    Serial.println("ChordedKeyboardHalf::setupPins");

    pinMode(LED_BUILTIN, OUTPUT);
    
    for (uint8_t i = 0; i < NUM_KEYS; i++) {
        pinMode(switchPins[i], INPUT_PULLUP);
    }
}

void ChordedKeyboardHalf::hardReset() 
{
    resetFunc();
}

Chord ChordedKeyboardHalf::getCurrentChord() 
{
    Chord currentChord = 0;
    for (uint8_t i = 0; i < NUM_KEYS; i++) {
        if (digitalRead(switchPins[i]) == LOW) {
            currentChord = currentChord | (1 << i);
        }
    }

    return currentChord;
}