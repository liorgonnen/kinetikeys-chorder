#include <BLECentralConnection.h>

BLEClientBas BLECentralConnection::slaveBatteryService;
BLEClientDis BLECentralConnection::slaveDeviceInfoService;
BLEClientUart BLECentralConnection::slaveUartService;
SlaveInputReceivedCallback BLECentralConnection::slaveInputReceivedCallback;

void BLECentralConnection::setup() {
    Serial.println("BLECentralConnection::setup - Begin");

    Bluefruit.setConnLedInterval(250);

    slaveUartService.setRxCallback(onSlaveInputReceived);
    slaveUartService.begin();

    slaveBatteryService.begin();
    slaveDeviceInfoService.begin();
    
    Bluefruit.Central.setConnectCallback(onDeviceConnected);
    Bluefruit.Central.setDisconnectCallback(onDeviceDisconnected);
    Bluefruit.Central.setConnIntervalMS(30, 30);

    Bluefruit.Scanner.setRxCallback(onScanResponse);
    Bluefruit.Scanner.restartOnDisconnect(true);
    Bluefruit.Scanner.setInterval(160, 80); // in unit of 0.625 ms
    Bluefruit.Scanner.useActiveScan(false);
    Bluefruit.Scanner.start(0); // 0 = Don't stop scanning after n seconds
    Serial.println("BLECentralConnection::setup - End");
}

void BLECentralConnection::setOnInputReceivedCallback(SlaveInputReceivedCallback callback) {
    slaveInputReceivedCallback = callback;
}

void BLECentralConnection::onDeviceConnected(uint16_t connectionHandle) {
    Serial.println("Slave CONNECTED successfully!");

    if (slaveBatteryService.discover(connectionHandle)) {
        Serial.print("Slave battery level: ");
        Serial.print(slaveBatteryService.read());
        Serial.println("%");
    }

    if (slaveUartService.discover(connectionHandle)) {
        slaveUartService.enableTXD();
        Serial.println("Ready to receive from slave");
    }
}

void BLECentralConnection::onDeviceDisconnected(uint16_t connectionHandle, uint8_t reason)
{
    Serial.print("Slave DISCONNECTED. Reason: 0x");
    Serial.println(reason, HEX);

    Bluefruit.Scanner.resume();
}

void BLECentralConnection::onScanResponse(ble_gap_evt_adv_report_t* report)
{
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

void BLECentralConnection::onSlaveInputReceived(BLEClientUart& slaveUart)
{
    Serial.println("BLECentralConnection::onSlaveInputReceived");

    uint8_t slaveChord;
    slaveUart.read(&slaveChord, sizeof(uint8_t));

    Serial.printf("Slave input received: %d", slaveChord);
    
    if (slaveInputReceivedCallback) {
        slaveInputReceivedCallback(slaveChord);
    }

    if (slaveChord != 0) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
    }
}

bool BLECentralConnection::isSlaveConnected() {
    return Bluefruit.Central.connected() && slaveUartService.discovered();
}
