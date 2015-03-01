///
/// @file		WifiShield_h_.h
/// @brief		Library header
/// @details	<#details#>
/// @n	
/// @n @b		Project puppet_001_ard
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		01/03/15 17:18
/// @version	<#version#>
/// 
/// @copyright	(c) Arne Boon, 2015
/// @copyright	<#license#>
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
#elif defined(RFDUINO) // RFduino specific
#include "Arduino.h"
#elif defined(SPARK) // Spark specific
#include "application.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

#ifndef WifiShield_CLASS
#define WifiShield_CLASS

#include <Arduino.h>
#include "WifiShield.h"

#include <SPI.h>
#include <WiFi.h>
//#include <WiFiUdp.h>
//#include <OSCMessage.h>

class WifiShield {
    
public:
    
    WifiShield();

//    WiFiUDP Udp;
    
    void setup(String _ssid, String _pass);
    void loop();
    
private:
    
    void printCurrentNet();
    void printWifiData();
    
    String ssid;
    String pass;
//    char ssid[];
//    char pass[];
    int status;
    
//    IPAddress outIp;
//    uint8_t outPort;
    
};


#endif