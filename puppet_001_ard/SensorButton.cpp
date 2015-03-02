//
// SensorButton_h_.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 01/03/15 16:51
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			SensorButton.h .h and ReadMe.txt for references
//


#include "SensorButton.h"

void SensorButton::loop() {
    this->read();
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
    
}

void SensorButton::read() {
    this->raw = !digitalRead(this->pin);
    this->value = this->raw;
}