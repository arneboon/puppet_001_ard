//
// SensorDistance_h_.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 03/03/15 19:52
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			SensorDistance.h .h and ReadMe.txt for references
//

#include "SensorDistance.h"

SensorDistance::SensorDistance() {    
    this->pinTrigger = 0;
    this->pinEcho = 0;
    this->maxDistance = 0;
}

void SensorDistance::setup(String _address, uint8_t _pinTrigger, uint8_t _pinEcho, unsigned int _maxDistance) {
    this->address = _address;
    this->pinTrigger = _pinTrigger;
    this->pinEcho = _pinEcho;
    this->maxDistance = _maxDistance;
    
    Serial.print("add sensor: ");
    Serial.println(this->address);
    
    /*
    Serial.print("pin trigger: ");
    Serial.println(this->pinTrigger);
    Serial.print("pin echo: ");
    Serial.println(this->pinEcho);
    */
    
    this->sonar = new NewPing(this->pinTrigger, this->pinEcho, this->maxDistance);
}

void SensorDistance::loop() {
    this->read();
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
}

void SensorDistance::read() {
    this->value = (uint8_t) sonar->ping_cm();
}

