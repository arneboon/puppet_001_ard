///
/// @file		puppet_001_ard.ino
/// @brief		Main sketch
/// Project 	puppet_001_ard Library
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		01/03/15 19:19
/// @version	<#version#>
/// 
/// @copyright	(c) Arne Boon, 2015
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
/// @n
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

//-------------------------------------------------
#include "WifiShield.h"

#include "SensorAnalog.h"
#include "SensorDigital.h"
#include "SensorButton.h"
#include "SensorI2C.h"

#include <WiFiUdp.h>

//-------------------------------------------------
#define PIN_LED A3
#define PIN_MANGNET_ANALOG A1
#define PIN_MAGNET_DIGITAL A2
#define PIN_NINEDOF_SDA A4
#define PIN_NINEDOF_SLC A5
#define PIN_BTN_1 2
#define PIN_BTN_2 3
#define PIN_BTN_3 5
#define PIN_BTN_4 6

#define SSID "HG655D-A14F3D"
#define PASS "PU7LAKLW"


//-------------------------------------------------
WifiShield wifiShield;

SensorDigital magnetDigital;
SensorAnalog magnetAnalog;
SensorI2C nineDof;
SensorButton btn1;
SensorButton btn2;
SensorButton btn3;
SensorButton btn4;

WiFiUDP Udp;

//-------------------------------------------------
void setup()
{   
    Serial.begin(9600);
    Serial.println("setup");
    
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, HIGH);
    
    magnetAnalog.setup("/magnet/analog", PIN_MANGNET_ANALOG, INPUT);
    magnetDigital.setup("/magnet/digital", PIN_MAGNET_DIGITAL, INPUT_PULLUP);
    nineDof.setup("/9dof", PIN_NINEDOF_SDA, PIN_NINEDOF_SLC);
    btn1.setup("/button/1", PIN_BTN_1, INPUT_PULLUP);
    btn2.setup("/button/2", PIN_BTN_2, INPUT_PULLUP);
    btn3.setup("/button/3", PIN_BTN_3, INPUT_PULLUP);
    btn4.setup("/button/4", PIN_BTN_4, INPUT_PULLUP);
    
    wifiShield.setup(SSID, PASS);
    
    Udp.begin(8888);
}

//-------------------------------------------------
void loop() {
    //    magnetAnalog.loop();
    //    magnetDigital.loop();
    //    nineDof.loop();
    btn1.loop();
    btn2.loop();
    btn3.loop();
    btn4.loop();
    
    delay(100);
}