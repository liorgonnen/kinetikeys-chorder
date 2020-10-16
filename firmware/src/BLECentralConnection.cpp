#include <BLECentralConnection.h>

BLEClientBas BLECentralConnection::slaveBatteryService;
BLEClientDis BLECentralConnection::slaveDeviceInfoService;
BLEClientUart BLECentralConnection::slaveUartService;

void BLECentralConnection::setup() {
    Serial.println("BLECentralConnection::setup - Begin");

    slaveBatteryService.begin();
    slaveDeviceInfoService.begin();
    slaveUartService.begin();
    
    Bluefruit.Central.setConnectCallback(onDeviceConnected);
    Bluefruit.Central.setDisconnectCallback(onDeviceDisconnected);

    Bluefruit.Scanner.setRxCallback(onScanResponse);
    Bluefruit.Scanner.restartOnDisconnect(true);
    Bluefruit.Scanner.setInterval(160, 80); // in unit of 0.625 ms
    Bluefruit.Scanner.useActiveScan(false);
    Bluefruit.Scanner.start(0); // 0 = Don't stop scanning after n seconds
    Serial.println("BLECentralConnection::setup - End");
}

void BLECentralConnection::onDeviceConnected(uint16_t connectionHandle) {
    Serial.println("Slave CONNECTED successfully!");

    if (slaveBatteryService.discover(connectionHandle)) {
        Serial.print("Slave battery level: ");
        Serial.print(slaveBatteryService.read());
        Serial.println("%");
    }
}

void BLECentralConnection::onDeviceDisconnected(uint16_t connectionHandle, uint8_t reason)
{
    Serial.println("Slave DISCONNECTED");
}

void BLECentralConnection::onScanResponse(ble_gap_evt_adv_report_t* report)
{
    Serial.println("BLECentralConnection::onScanResponse");
    if (Bluefruit.Scanner.checkReportForService(report, slaveUartService)) {
        Serial.print("BLE UART service detected. Connecting ... ");
        Bluefruit.Central.connect(report);
    }
    else {      
        // For Softdevice v6: after received a report, scanner will be paused
        // We need to call Scanner resume() to continue scanning
        Bluefruit.Scanner.resume();
    }
}
