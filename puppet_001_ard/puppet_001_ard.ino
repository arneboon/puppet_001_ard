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
#include <WiFiUdp.h>
#include "SensorAnalog.h"
#include "SensorDigital.h"
#include "SensorButton.h"
#include "SensorDistance.h"
#include "SensorDof.h"
#include "Config.h"

//-------------------------------------------------
WifiShield wifiShield;
WiFiUDP Udp;

SensorDigital magnetDigital;
SensorAnalog magnetAnalog;
SensorButton btn1;
SensorButton btn2;
SensorButton btn3;
SensorButton btn4;
SensorButton btn5;
SensorDistance distance;
SensorDof dof;
SensorAnalog flex;

//-------------------------------------------------
void setup()
{   
    Serial.begin(9600);
    Serial.flush();
    delay(50);
    Serial.println("----------------");
    Serial.println("setup");
    
    magnetAnalog.setup("/mc/magnet/analog", PinLayout::magnet_analog, INPUT);
    magnetDigital.setup("/mc/magnet/digital", PinLayout::magnet_digital, INPUT_PULLUP);
    btn1.setup("/mc/button/1", PinLayout::btn_1, INPUT_PULLUP);
    btn2.setup("/mc/button/2", PinLayout::btn_2, INPUT_PULLUP);
    btn3.setup("/mc/button/3", PinLayout::btn_3, INPUT_PULLUP);
    btn4.setup("/mc/button/4", PinLayout::btn_4, INPUT_PULLUP);
    btn5.setup("/mc/button/5", PinLayout::btn_5, INPUT_PULLUP);
    distance.setup("/mc/distance", PinLayout::distance_trigger, PinLayout::distance_echo, Settings::distance_mac_cm, Settings::median_iterations);
    dof.setup("/mc/dof", PinLayout::ninedof_sda, PinLayout::ninedof_slc);
    flex.setup("/mc/flex", PinLayout::flex, INPUT);
    
    magnetAnalog.broadcast(true);
    magnetDigital.broadcast(true);
    btn1.broadcast(true);
    btn2.broadcast(true);
    btn3.broadcast(true);
    btn4.broadcast(true);
    btn5.broadcast(true);
    distance.broadcast(true);
    dof.broadcast(true);
    flex.broadcast(true);
    
    wifiShield.setup(WifiCredentials::ssid, WifiCredentials::passphrase);
    
    Udp.begin(8888);
    
    pinMode(PinLayout::led, OUTPUT);
    digitalWrite(PinLayout::led, HIGH);
}

//-------------------------------------------------
void loop() {
    magnetAnalog.loop();
    magnetDigital.loop();
    btn1.loop();
    btn2.loop();
    btn3.loop();
    btn4.loop();
    btn5.loop();
    distance.loop();
    dof.loop();
    flex.loop();
    
    delay(Settings::delay);
}