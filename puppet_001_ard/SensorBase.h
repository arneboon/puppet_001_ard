///
/// @mainpage	puppet_001_ard Library
///
/// @details	Puppet 001 Arduino
/// @n			Library
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		28/02/15 15:29
/// @version	<#version#>
///
/// @copyright	(c) Arne Boon, 2015
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


///
/// @file		puppet_001_ardLibrary.h
/// @brief		Library header
/// Project 	puppet_001_ard Library
///
/// @details	<#details#>
/// @n
/// @n @b		Project puppet_001_ard
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		28/02/15 15:29
/// @version	<#version#>
///
/// @copyright	(c) Arne Boon, 2015
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(ROBOTIS) // Robotis specific
#include "libpandora_types.h"
#include "pandora.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#include "Arduino.h"
#elif defined(SPARK) // Spark specific
#include "application.h"
#elif defined(RFDUINO) // RFduino specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

#ifndef SensorBase_CLASS
#define SensorBase_CLASS 100

#define OSC_OUT_IP {192, 168, 1, 67}
#define OSC_OUT_PORT 9999

#include <Arduino.h>
#include <OSCMessage.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

class SensorBase {
    
public:
    
    SensorBase();
    
    void setup(String _address, uint8_t _pin, uint8_t _mode);
    void loop();
    
    void read();
    void printRaw();
    void print();
    
    void broadcast(bool _bBroadcast);
    void toggleBroadcast();

    void setAddress(String _address);
    
    void send();
    
    uint8_t getRaw() { return this->raw; };
    uint8_t getValue() { return this->value; };
    String getAddress() {return this->address; };

protected:
    uint8_t pin;
    uint8_t mode;
    
    uint8_t raw;
    uint8_t value;
    
    WiFiUDP Udp;
    IPAddress outIp;
    uint16_t outPort;
    
    String address;
    OSCMessage msg;
    
    bool bBroadcast;
};


#endif













