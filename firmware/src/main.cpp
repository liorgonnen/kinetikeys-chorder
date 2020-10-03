#include <Arduino.h>
#include <bluefruit.h>

#define KEY1 PIN_A0
#define KEY2 PIN_A1
#define KEY3 PIN_A2
#define KEY4 PIN_A3
#define KEY5 PIN_A4
#define NUM_KEYS 5

uint8_t KEYS[] = { KEY1, KEY2, KEY3, KEY4, KEY5 };

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


BLEDis bledis;
BLEHidAdafruit blehid;

void startAdv()
{  
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  
  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for the dev name in the advertising packet
  Bluefruit.Advertising.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html   
   */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void setupBluetooth() {
  Bluefruit.begin();
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
  Bluefruit.setName("Kinetikeys Chorder");

  // Configure and Start Device Information Service
  bledis.setManufacturer("Lior Gonnen");
  bledis.setModel("rev-0");
  bledis.begin();

  /* Start BLE HID
   * Note: Apple requires BLE device must have min connection interval >= 20m
   * ( The smaller the connection interval the faster we could send data).
   * However for HID and MIDI device, Apple could accept min connection interval 
   * up to 11.25 ms. Therefore BLEHidAdafruit::begin() will try to set the min and max
   * connection interval to 11.25  ms and 15 ms respectively for best performance.
   */
  blehid.begin();

  // Set callback for set LED from central
  //blehid.setKeyboardLedCallback(set_keyboard_led);

  /* Set connection interval (min, max) to your perferred value.
   * Note: It is already set by BLEHidAdafruit::begin() to 11.25ms - 15ms
   * min = 9*1.25=11.25 ms, max = 12*1.25= 15 ms 
   */
  /* Bluefruit.Periph.setConnInterval(9, 12); */

  // Set up and start advertising
  startAdv();
}

void setupPins() {
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  
  for (uint8_t i = 0; i < NUM_KEYS; i++) {
    pinMode(KEYS[i], INPUT_PULLUP);
  }
}

void setup()
{
  setupPins();

  setupBluetooth();

  Serial.begin(114400);
}

int pendingChord = 0;

void loop() {
  int currentChord = 0;
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
        blehid.keyPress(KEY_VALUES[pendingChord - 1]);
        delay(5);
        blehid.keyRelease();
        delay(5);
      }
      pendingChord = 0;
    } 
    else {
      pendingChord |= currentChord;
    }
  }
}
