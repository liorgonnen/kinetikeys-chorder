#include <BLEPeripheralConnection.h>

BLEBas BLEPeripheralConnection::batteryService;
BLEDis BLEPeripheralConnection::deviceInfoService;

void BLEPeripheralConnection::setup(BLEService& mainService) {
    Serial.println("BLEPeripheralConnection::setup - Begin");
    
    // Advertising packet
    Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
    Bluefruit.Advertising.addTxPower();
    Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);

    mainService.begin();
    deviceInfoService.begin();
    batteryService.begin();
    Bluefruit.Advertising.addService(mainService);
    Bluefruit.Advertising.addService(batteryService);
    Bluefruit.Advertising.addService(deviceInfoService);

    // There is enough room for the dev name in the advertising packet
    Bluefruit.Advertising.addName();
    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
    Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
    Bluefruit.Advertising.start(0);                // 0 = Advertise untul connected

    Bluefruit.Periph.setConnectCallback(onMasterConnected);
    Bluefruit.Periph.setDisconnectCallback(onMasterDisconnected);
    Bluefruit.Periph.setConnIntervalMS(30, 30);

    Serial.println("BLEPeripheralConnection::setup - End");
}

void BLEPeripheralConnection::onMasterConnected(uint16_t connectionHandle)
{
    Serial.println("Connected to master");
}

void BLEPeripheralConnection::onMasterDisconnected(uint16_t connectionHandle, uint8_t reason)
{
    Serial.println("DISCONNECTED from Master");
}
