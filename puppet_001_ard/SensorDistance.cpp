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
    this->medianIterations = 0;
    
    this->pingRaw = 0;
    this->pingMedian = 0;
    this->pingCm = 0;
}

void SensorDistance::setup(String _address, uint8_t _pinTrigger, uint8_t _pinEcho, unsigned int _maxDistance, uint8_t _medianIterations) {
    this->address = _address;
    this->pinTrigger = _pinTrigger;
    this->pinEcho = _pinEcho;
    this->maxDistance = _maxDistance;
    this->medianIterations = _medianIterations;
    
    Serial.print("add sensor: ");
    Serial.println(this->address);
    
    char address[this->address.length() + 1];
    this->address.toCharArray(address, this->address.length() + 1);
    msg.setAddress(address);
    
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

    if (this->medianIterations >= 1) {
        this->pingMedian = sonar->ping_median(this->medianIterations);
        this->pingCm = sonar->convert_cm(this->pingMedian);
    } else {
        this->pingCm = sonar->ping_cm();
    }
    
    this->value = this->pingCm;
    if (this->value == 0) {
        this->value = this->maxDistance;
    }
}
