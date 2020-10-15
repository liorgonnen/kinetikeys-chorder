#include <Arduino.h>
#include <bluefruit.h>
#include <Jumper.h>
#include <ChordedKeyboardHalf.h>
#include <ChordedKeyboardMaster.h>
#include <ChordedKeyboardSlave.h>

#define NUM_KEYS 5


// Dummy key map for now
char KEY_VALUES[] = {
  'a',
  'b',
  'c',
  'd',
  'e',
  'f',
  'g',
  'h',
  'i',
  'j',
  'k',
  'l',
  'm',
  'n',
  'o',
  'p',
  'q',
  'r',
  's',
  't',
  'u',
  'v',
  'w',
  'x',
  'y',
  'z',
};

const int NUM_KEY_VALUES = (sizeof(KEY_VALUES) / sizeof(char));

BLEHidAdafruit bleHidService;
BLEClientUart blePeripheral;

ChordedKeyboardHalf* keyboard;

void peripheralRxCallback(uint16_t connectionHandle)
{

}

void centralRxCallback(BLEClientUart& service)
{

}

void onSecondaryChorderConnected(uint16_t connectionHandle) 
{
  /*Serial.println("Secondary chorder CONNECTED");

  Serial.print("Dicovering Device Information ... ");
  if (bleDeviceInfoService.discover(connectionHandle)) {
    Serial.println("Found it");
    char buffer[32+1];
    
    // read and print out Manufacturer
    memset(buffer, 0, sizeof(buffer));
    if (clientDis.getManufacturer(buffer, sizeof(buffer))) {
      Serial.print("Manufacturer: ");
      Serial.println(buffer);
    }

    // read and print out Model Number
    memset(buffer, 0, sizeof(buffer));
    if (clientDis.getModel(buffer, sizeof(buffer))) {
      Serial.print("Model: ");
      Serial.println(buffer);
    }

    Serial.println();
  }
  else {
    Serial.println("Found NONE");
  }

  Serial.print("Dicovering Battery ... ");
  if (bleBatteryService.discover(connectionHandle)) {
    Serial.println("Found it");
    Serial.print("Battery level: ");
    Serial.print(bleBatteryService.read());
    Serial.println("%");
  }
  else {
    Serial.println("Found NONE");
  }

  Serial.print("Discovering BLE Uart Service ... ");
  if (bleCenteral.discover(connectionHandle)) {
    Serial.println("Found it");

    Serial.println("Enable TXD's notify");
    bleCenteral.enableTXD();

    Serial.println("Ready to receive from peripheral");
  }
  else {
    Serial.println("Found NONE");
    
    // disconnect since we couldn't find bleuart service
    Bluefruit.disconnect(connectionHandle);
  }  */
}

/*void onSecondaryChorderDisconnected(uint16_t connectionHandle, uint8_t reason)
{
  Serial.println("Secondary chorder DISCONNECTED");
}

*/
void setupBluetooth() {

  // Configure and Start Device Information Service
  /*bleDeviceInfoService.setManufacturer("Lior Gonnen");
  bleDeviceInfoService.setModel("Chorder rev-0");
  bleDeviceInfoService.begin();

  blePeripheral.setRxCallback(peripheralRxCallback);
  blePeripheral.begin();

  bleCentral.setRxCallback(centralRxCallback);
  bleCentral.begin();

  bleHidService.begin();*/


}

void setup()
{
  Serial.begin(114400);

  Jumper jumper(5, 6);

  if (jumper.isSet()) {
    keyboard = new ChordedKeyboardSlave();
  }
  else {
    keyboard = new ChordedKeyboardMaster();
  }

  keyboard->setup();

  setupBluetooth();
}

int pendingChord = 0;

void loop() {
  keyboard->loop();
  /*int currentChord = 0;
  for (uint8_t i = 0; i < NUM_KEYS; i++) {
    if (digitalRead(KEYS[i]) == LOW) {
      currentChord = currentChord | (1 << i);
    }
  }

  delay(10);

  if (currentChord != pendingChord) {
    Serial.println(currentChord);
    if (currentChord == 0) {
      if (pendingChord <= NUM_KEY_VALUES) {
        bleHidService.keyPress(KEY_VALUES[pendingChord - 1]);
        delay(5);
        bleHidService.keyRelease();
        delay(5);
      }
      pendingChord = 0;
    } 
    else {
      pendingChord |= currentChord;
    }
  }*/
}
