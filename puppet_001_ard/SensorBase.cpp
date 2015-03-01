//
// puppet_001_ardLibrary.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard Library
//
// Created by 	Arne Boon, 28/02/15 15:29
// 				Studio Arne Boon
//
// Copyright 	© Arne Boon, 2015
// Licence		All rights reserved
//
// See 			puppet_001_ardLibrary.cpp.h and ReadMe.txt for references
//


#include "SensorBase.h"

SensorBase::SensorBase() {
    this->outPort = OSC_OUT_PORT;
}

void SensorBase::setup(String _address, uint8_t _pin, uint8_t _mode) {
    this->pin = _pin;
    this->mode = _mode;
    this->address = _address;
    
    pinMode(this->pin, this->mode);
    
    char address[this->address.length() + 1];
    this->address.toCharArray(address, this->address.length() + 1);
    msg.setAddress(address);
}

void SensorBase::loop() {

}

void SensorBase::read() {
    
}

void SensorBase::printRaw() {
    Serial.println(this->raw);    
}

void SensorBase::print() {
    Serial.print("print: ");
    Serial.print(this->address);
    Serial.print(" ");
    Serial.println(this->value);
}

void SensorBase::send() {
    Serial.print("send: ");
    Serial.print(this->address);
    Serial.print(" ");
    Serial.println(this->value);
    
    msg.empty();
    msg.add((int8_t) this->value);
    
    IPAddress outIp(192, 168, 1, 67);
    
//    Udp.beginPacket(outIp, this->outPort);
    Udp.beginPacket(outIp, 9999);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
}

void SensorBase::start() {
    
}

void SensorBase::stop() {
    
}

void SensorBase::toggle() {
    
}

void SensorBase::setAddress(String _address) {
    this->address = _address;
}
