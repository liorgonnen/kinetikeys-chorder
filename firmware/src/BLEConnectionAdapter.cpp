#include <BLEConnectionAdapter.h>

void BLEConnectionAdapter::setup() {
    // 1 connection as peripheral, 1 connection as central
    Bluefruit.begin(1, 1);
    Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
    Bluefruit.setName("Kinetikeys");
}
