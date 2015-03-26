//
// SensorAnalog_.cpp 
// Class library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 28/02/15 16:17
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			SensorAnalog .h and ReadMe.txt for references
//


#include "SensorAnalog.h"

SensorAnalog::SensorAnalog() {
    this->fromLow = 0;
    this->fromHigh = 1024;
    this->toLow = -100;
    this->toHigh = 100;
}

void SensorAnalog::loop() {
    this->read();
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
}

void SensorAnalog::read() {
    this->raw = analogRead(this->pin);
//    this->value = this->raw;
    this->value = map(this->raw, this->fromLow, this->fromHigh, this->toLow, this->toHigh);
}
