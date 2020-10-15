#ifndef BLECENTRALCONNECTION_H
#define BLECENTRALCONNECTION_H

#include "BLEConnectionAdapter.h"

// GATT Server
// A peripheral can advertise to let other device know it's there, but
// It's the Cetnral that actually sends the connection request
class BLECentralConnection : public BLEConnectionAdapter
{
public:
    void setup() override;

private:
    static void onScanResponse(ble_gap_evt_adv_report_t* report);
    static void onDeviceConnected(uint16_t connectionHandle);
    static void onDeviceDisconnected(uint16_t connectionHandle, uint8_t reason);
};

#endif