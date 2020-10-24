#ifndef BLEPERIPHERALCONNECTION_H
#define BLEPERIPHERALCONNECTION_H

#include "BLEConnectionAdapter.h"
#include <Arduino.h>

// GATT Server
// A peripheral can advertise to let other device know it's there, but
// It's the Cetnral that actually sends the connection request
class BLEPeripheralConnection : public BLEConnectionAdapter
{
public:
    void setup(BLEService& mainService);

private:
    static BLEBas  batteryService;
    static BLEDis  deviceInfoService;
    static void onMasterConnected(uint16_t connectionHandle);
    static void onMasterDisconnected(uint16_t connectionHandle, uint8_t reason);
};

#endif