#ifndef JUMPER_H
#define JUMPER_H

#include <stdint.h>

class Jumper
{
public:
    Jumper(uint8_t pin1, uint8_t pin2) : pin1(pin1), pin2(pin2) { }

    bool isSet() const;

private:
    uint8_t pin1;
    uint8_t pin2;
};

#endif