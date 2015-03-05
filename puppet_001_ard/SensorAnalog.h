///
/// @file		SensorAnalog_.h
/// @brief		Class library header
/// @details	<#details#>
/// @n
/// @n @b		Project puppet_001_ard
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		28/02/15 16:17
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

#ifndef SensorAnalog_CLASS
#define SensorAnalog_CLASS

#include <Arduino.h>
#include "SensorBase.h"

class SensorAnalog: public SensorBase {
    
public:
    
    SensorAnalog();
    
    void loop();
    void read();
    
    void setRange(int16_t _fromLow, int16_t _fromHigh, int16_t _toLow, int16_t _toHigh);
    
protected:
    
    int16_t fromLow;
    int16_t fromHigh;
    int16_t toLow;
    int16_t toHigh;
};


#endif
