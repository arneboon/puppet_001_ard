///
/// @file		SensorI2C_h_.h
/// @brief		Library header
/// @details	<#details#>
/// @n	
/// @n @b		Project puppet_001_ard
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Arne Boon
/// @author		Studio Arne Boon
///
/// @date		28/02/15 16:31
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

#ifndef SensorI2C_CLASS
#define SensorI2C_CLASS

#include <Arduino.h>
#include "SensorBase.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_9DOF.h>
#include <Adafruit_L3GD20_U.h>

class SensorDof: public SensorBase {
    
public:
    
    SensorDof();
    
    void setup(String _address, uint8_t _sda, uint8_t _slc);
    
    void loop();
    void read();
    void send();
    void print();
    
private:
    
    uint8_t sda;
    uint8_t slc;
    
    Adafruit_9DOF *dof;
    Adafruit_LSM303_Accel_Unified *accel;
    Adafruit_LSM303_Mag_Unified *mag;
    
    float seaLevelPressure;
    
    void init();
    void onChange();
    
    bool bConnectedAccel;
    bool bConnectedMag;
    
    sensors_event_t accel_event;
    sensors_event_t mag_event;
    sensors_event_t mag_event_compensated;
    sensors_vec_t   orientation; //x.roll, x.pitch, x.heading
    
    int16_t roll;
    int16_t pitch;
    int16_t heading;
    int16_t accelleration;
    
    int16_t pRoll;
    int16_t pPitch;
    int16_t pHeading;
    int16_t pAccelleration;
};


#endif
