#include <Arduino.h>
#include <bluefruit.h>
#include <Jumper.h>
#include <ChordedKeyboardHalf.h>
#include <ChordedKeyboardMaster.h>
#include <ChordedKeyboardSlave.h>

ChordedKeyboardHalf* keyboard;

void setup()
{
    Serial.begin(115200); 
    while (!Serial);
    Serial.println("Serial connected!");  

    keyboard = new ChordedKeyboardMaster();
    //keyboard = new ChordedKeyboardSlave();
    
    // Jumper jumper(5, 6);
    // if (jumper.isSet()) {
    //     keyboard = new ChordedKeyboardSlave(); 
    // }
    // else {
    //     keyboard = new ChordedKeyboardMaster();
    // }

    keyboard->setup();
}

void loop() {
    keyboard->loop();
}
    