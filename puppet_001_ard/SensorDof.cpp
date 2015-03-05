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
    
    this->pRoll;
    this->pPitch;
    this->pHeading;
}

void SensorDof::setup(String _address, uint8_t _sda, uint8_t _slc) {
    this->sda = _sda;
    this->slc = _slc;
    this->address = _address;
    
    Serial.print("add sensor: ");
    Serial.println(this->address);
    
    char address[this->address.length() + 1];
    this->address.toCharArray(address, this->address.length() + 1);
    msg.setAddress(address);
    
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
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
}

void SensorDof::read() {
    //--accelerometer
    this->accel->getEvent(&this->accel_event);
    if (this->dof->accelGetOrientation(&this->accel_event, &this->orientation))
    {
        this->roll = this->orientation.roll;
        this->pitch = this->orientation.pitch;
    }
    
    //--magnetometer
    this->mag->getEvent(&this->mag_event);
    if (this->dof->magTiltCompensation(SENSOR_AXIS_Z, &this->mag_event, &this->accel_event)) {
        if (this->dof->magGetOrientation(SENSOR_AXIS_Z, &this->mag_event, &this->orientation)) {
            this->heading = this->orientation.heading;
        }
    }
}

void SensorDof::onChange() {
    //--roll
    if (this->roll != this->pRoll) {
        this->send();
    }
    this->pRoll = this->roll;
    
    //--pitch
    if (this->pitch != this->pPitch) {
        this->send();
    }
    this->pPitch = this->pitch;
    
    //--heading
    if (this->heading != this->pHeading) {
        this->send();
    }
    this->pHeading = this->heading;
}

void SensorDof::print() {
    Serial.print("print: ");
    Serial.print(this->address);
    Serial.print(", ");
    Serial.print(this->roll);
    Serial.print(", ");
    Serial.print(this->pitch);
    Serial.print(", ");
    Serial.print(this->heading);
    Serial.println();
}

void SensorDof::send() {
    if (this->bBroadcast) {
        Serial.print("send: ");
        Serial.print(this->address);
        Serial.print(", ");
        Serial.print(this->roll);
        Serial.print(", ");
        Serial.print(this->pitch);
        Serial.print(", ");
        Serial.print(this->heading);
        Serial.println();
        
        msg.empty();
        msg.add((int16_t) this->roll);
        msg.add((int16_t) this->pitch);
        msg.add((int16_t) this->heading);
        
        Udp.beginPacket(this->outIp, this->outPort);
        msg.send(Udp);
        Udp.endPacket();
        msg.empty();
    }
}


