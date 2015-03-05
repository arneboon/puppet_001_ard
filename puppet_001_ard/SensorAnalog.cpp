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
    this->raw = 0;
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
    this->value = this->raw;
}
