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

SensorDigital::SensorDigital() {
    this->raw = 0;
}

void SensorDigital::loop() {
    this->read();
    this->print();
}

void SensorDigital::read() {
    this->raw = digitalRead(this->pin);
    this->value = this->raw;
}
