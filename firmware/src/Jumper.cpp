#include <Jumper.h>
#include <Arduino.h>

bool Jumper::isSet() const
{
    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2, OUTPUT);

    // If pins are connected, pin1 should reflect LOW
    digitalWrite(pin2, LOW);

    delay(20);

    bool isSet = digitalRead(pin1) == LOW;

    // Return the pin to high impedance state
    pinMode(pin2, INPUT);

    return isSet;
}