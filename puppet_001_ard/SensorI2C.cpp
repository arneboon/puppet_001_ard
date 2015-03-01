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


#include "SensorI2C.h"

SensorI2C::SensorI2C() {
    this->raw = 0;
}

void SensorI2C::setup(String _address, uint8_t _sda, uint8_t _slc) {
    this->sda = _sda;
    this->slc = _slc;
    this->address = _address;
    
    Serial.println("i2c");
}

void SensorI2C::loop() {

}

void SensorI2C::read() {

}
