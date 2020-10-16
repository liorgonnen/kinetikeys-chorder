#ifndef CHORDEDKEYBOARDMSLAVE_H
#define CHORDEDKEYBOARDMSLAVE_H

#include <ChordedKeyboardHalf.h>
#include <BLEPeripheralConnection.h>
#include <Arduino.h>

class ChordedKeyboardSlave : public ChordedKeyboardHalf
{
public:
    ChordedKeyboardSlave();

protected:
    void setupPins() const override;
    void setupBleConnection() override;
    void loop() override;

private:
    BLEUart masterUartService;
    BLEPeripheralConnection bleMasterConnection;
};

#endif