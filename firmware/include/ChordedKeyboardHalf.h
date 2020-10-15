
#ifndef CHORDEDKEYBOARDHALF_H
#define CHORDEDKEYBOARDHALF_H

#define KEY_M_P PIN_A0
#define KEY_M_R PIN_A1
#define KEY_M_M PIN_A2
#define KEY_M_I PIN_A3
#define KEY_M_T PIN_A4

#define KEY_S_P 9
#define KEY_S_R 10
#define KEY_S_M 11
#define KEY_S_I 12
#define KEY_S_T 13


class ChordedKeyboardHalf
{
protected:
    ChordedKeyboardHalf() { };
    
    //uint8_t KEYS[] = { KEY1, KEY2, KEY3, KEY4, KEY5 };

public:
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif