#include <BLECentralConnection.h>

void BLECentralConnection::setup() {
    BLEConnectionAdapter::setup();
    Bluefruit.Central.setConnectCallback(onDeviceConnected);
    Bluefruit.Central.setDisconnectCallback(onDeviceDisconnected);

    Bluefruit.Scanner.setRxCallback(onScanResponse);
    Bluefruit.Scanner.restartOnDisconnect(true);
    Bluefruit.Scanner.setInterval(160, 80); // in unit of 0.625 ms
    Bluefruit.Scanner.useActiveScan(false);
    Bluefruit.Scanner.start(0);                   // // 0 = Don't stop scanning after n seconds
}

void BLECentralConnection::onDeviceConnected(uint16_t connectionHandle) {
    Serial.println("Device CONNECTED");
}

void BLECentralConnection::onDeviceDisconnected(uint16_t connectionHandle, uint8_t reason)
{
    Serial.println("Device DISCONNECTED");
}

void BLECentralConnection::onScanResponse(ble_gap_evt_adv_report_t* report)
{
  //Check if advertising contain BleUart service
//   if (Bluefruit.Scanner.checkReportForService(report, bleCentral)) {
//     Serial.print("BLE UART service detected. Connecting ... ");

//     // Connect to device with bleuart service in advertising
//     Bluefruit.Central.connect(report);
//   }
//   else {      
//     // For Softdevice v6: after received a report, scanner will be paused
//     // We need to call Scanner resume() to continue scanning
//     Bluefruit.Scanner.resume();
//   }
}
