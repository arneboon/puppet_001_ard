//
// SensorDigital_h_.cpp 
// Class library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 28/02/15 15:48
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			SensorDigital.h and ReadMe.txt for references
//


#include "SensorDigital.h"

void SensorDigital::loop() {
    this->read();
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
    
}

void SensorDigital::read() {
    /* TODO:
     * merge button class with sensordigital by inverting the reading so that press is HIGH
     * this->raw = !digitalRead(this->pin);
     * use struct readMode: NORMALLY_OPEN, NORMALLY_CLOSED on sensorDigital as function
     */
    
    this->raw = digitalRead(this->pin);
    this->value = this->raw;
}