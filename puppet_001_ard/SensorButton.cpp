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

SensorButton::SensorButton() {
    this->raw = 0;
}

void SensorButton::loop() {
    this->read();
    this->bounce();
}

void SensorButton::read() {
    this->raw = !digitalRead(this->pin);
    this->value = this->raw;
}

void SensorButton::bounce() {
    if (this->value != this->pValue) {
//        this->print();
        this->send();
        if (this->value == HIGH) {
            //--on
        } else {
            //--off
        }
    }
    this->pValue = this->value;
}

