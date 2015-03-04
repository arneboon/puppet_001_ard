//
// SensorI2C_h_.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 28/02/15 16:31
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			SensorI2C.h .h and ReadMe.txt for references
//


#include "SensorDof.h"

SensorDof::SensorDof() {
    this->seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    this->bConnectedAccel = false;
    this->bConnectedMag = false;
    
    this->roll;
    this->pitch;
    this->heading;
}

void SensorDof::setup(String _address, uint8_t _sda, uint8_t _slc) {
    this->sda = _sda;
    this->slc = _slc;
    this->address = _address;
    
    Serial.print("add sensor: ");
    Serial.println(this->address);
    
    this->dof = new Adafruit_9DOF();
    this->accel = new Adafruit_LSM303_Accel_Unified(30301);
    this->mag = new Adafruit_LSM303_Mag_Unified(30302);
    
    this->init();
}

void SensorDof::init() {
    if (this->accel->begin()) {
        this->bConnectedAccel = true;
        Serial.println("[OK] 9dof accel");
    } else {
        Serial.println("[Error] no LSM303 accell detected");
    }
    
    if (this->mag->begin()) {
        this->bConnectedMag = true;
        Serial.println("[OK] 9dof mag");
    } else {
        Serial.println("[Error] no LSM303 mag detected");
    }
}


void SensorDof::loop() {
    this->read();
}

void SensorDof::read() {
    
    /* Calculate pitch and roll from the raw accelerometer data */
    this->accel->getEvent(&this->accel_event);
    if (this->dof->accelGetOrientation(&this->accel_event, &this->orientation))
    {
        this->roll = this->orientation.roll;
        this->pitch = this->orientation.pitch;
        /* 'orientation' should have valid .roll and .pitch fields */
//        Serial.print(F("Roll: "));
//        Serial.println(this->orientation.roll);
//        Serial.print(F("Pitch: "));
//        Serial.println(this->orientation.pitch);
    }
    
    /* Calculate the heading using the magnetometer */
    this->mag->getEvent(&this->mag_event);
    if (this->dof->magTiltCompensation(SENSOR_AXIS_Z, &this->mag_event, &this->accel_event)) {
        if (this->dof->magGetOrientation(SENSOR_AXIS_Z, &this->mag_event, &this->orientation)) {
            /* 'orientation' should have valid .heading data now */
            Serial.print(F("Heading: "));
            Serial.println(orientation.heading);
        }
    }

}
