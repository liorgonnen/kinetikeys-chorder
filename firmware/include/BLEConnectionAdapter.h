#ifndef BLECONNECTIONADAPTER_H
#define BLECONNECTIONADAPTER_H

#include <bluefruit.h>

/**
 * GAP: Generic Access Profile
 * GATT: Generic Attribute Profile - Defines the format of the data exposed by the BLE device
 * CCCD: Client Characteristic Configuration Descvriptor
 * Service: A grouping of one of more attributes
 * Characteristics: A Characteristic is always part of a service and represents a piece of
 * data/information that the server wants to expose to the client
 * 
 * Central: a device that discovers and listens to other devices that are Advertising. 
 * A Central also has the capability of connecting to an Advertising device.
 * 
 * Peripheral: a device that Advertises and accepts Connections from Central devices. 
 * 
 * Connection process:
 * 1. Peripheral starts advertising and send out connectable advertising packets
 * 2. Central device needs to be scanning for advertisements while the peripheral is advertising
 * 3. Central sends a connection request
 * 4. Peripheral always listens for a short time after it sends the advertisement, this allows it
 * to accept the connection request from the central device
 * 5. Connection is now "created", but not "established"
 * 6. A connection becomes "established" once the device receives a packet from its peer device
 * 7. After the connection is established Central becomes "Master" and Peripheral becomes "Slave"
 * 8. Master is responsible for managing the connection, controlling the connection parameteters
 * and timing of events within the connection
 */
class BLEConnectionAdapter
{

};

#endif
