///
/// @file		Config.h
/// @brief		Header
/// @details	<#details#>
/// @n	
/// @n @b		Project puppet_001_ard
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		19/04/15 12:03
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

#ifndef Config_h
#define Config_h


namespace WifiCredentials {
    char ssid[] = "MY_NETWORK_SSID";
    char passphrase[] = "MY_NETWORK_PASSWORD";
}

namespace PinLayout {
    /**
    //-- Labkit Manual Routing
    const int8_t led = A3;
    const int8_t magnet_analog = A1;
    const int8_t magnet_digital = A2;
    const int8_t ninedof_sda = A4;
    const int8_t ninedof_slc = A5;
    const int8_t btn_1 = 2;
    const int8_t btn_2 = 3;
    const int8_t btn_3 = 5;
    const int8_t btn_4 = 6;
    const int8_t distance_trigger = 8;
    const int8_t distance_echo = 8;
    const int8_t flex = A0;
    **/

    //-- Maplab Board 001 PCB
    const int8_t led = 45;
    const int8_t magnet_analog = A9;
    const int8_t magnet_digital = 23;
    const int8_t ninedof_sda = 20;
    const int8_t ninedof_slc = 21;
    const int8_t btn_1 = 35;
    const int8_t btn_2 = 37;
    const int8_t btn_3 = 39;
    const int8_t btn_4 = 41;
    const int8_t btn_5 = 43;
    const int8_t distance_trigger = A11;
    const int8_t distance_echo = A11;
    const int8_t flex = A10;
}

namespace Settings {
    const int16_t distance_mac_cm = 400;
    const int16_t median_iterations = 0;
    
    /* NOTE
     * SensorDistance: Wait 50ms between pings (about 20 pings/sec).
     *  29ms should be the shortest delay between pings.
     */
    const int16_t delay = 30;
}

#endif
