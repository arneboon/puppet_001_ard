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


#include "SensorDof.h"

SensorDof::SensorDof() {
    this->seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    this->bConnectedAccel = false;
    this->bConnectedMag = false;
    
    this->roll;
    this->pitch;
    this->heading;
    
    this->pRoll;
    this->pPitch;
    this->pHeading;
    
    this->fromLow = -180;
    this->fromHigh = 180;
    this->toLow = -100;
    this->toHigh = 100;
}

void SensorDof::setup(String _address, uint8_t _sda, uint8_t _slc) {
    this->sda = _sda;
    this->slc = _slc;
    this->address = _address;
    
    Serial.print("add sensor: ");
    Serial.println(this->address);
    
    char address[this->address.length() + 1];
    this->address.toCharArray(address, this->address.length() + 1);
    msg.setAddress(address);
    
    this->dof = new Adafruit_9DOF();
    this->accel = new Adafruit_LSM303_Accel_Unified(30301);
    this->mag = new Adafruit_LSM303_Mag_Unified(30302);
    
    this->init();
}

void SensorDof::init() {
    if (this->accel->begin()) {
        this->bConnectedAccel = true;
        Serial.println("[OK] 9dof accel");
    } else {
        Serial.println("[Error] no LSM303 accell detected");
    }
    
    if (this->mag->begin()) {
        this->bConnectedMag = true;
        Serial.println("[OK] 9dof mag");
    } else {
        Serial.println("[Error] no LSM303 mag detected");
    }
}


void SensorDof::loop() {
    this->read();
    
    if (this->bOnChange) {
        this->onChange();
    } else {
        this->send();
    }
}

void SensorDof::read() {
    
    /*** heading tilt compensated ***/
//    //--accelerometer
//    this->accel->getEvent(&this->accel_event);
//    if (this->dof->accelGetOrientation(&this->accel_event, &this->orientation))
//    {
//        this->roll = this->orientation.roll;
//        this->pitch = this->orientation.pitch;
//    }
//    
//    //--magnetometer
//    this->mag->getEvent(&this->mag_event);
//    if (this->dof->magTiltCompensation(SENSOR_AXIS_Z, &this->mag_event, &this->accel_event)) {
//        if (this->dof->magGetOrientation(SENSOR_AXIS_Z, &this->mag_event, &this->orientation)) {
//            this->heading = this->orientation.heading;
//        }
//    }
    
//    /*** fusion heading compensated ***/
//    this->accel->getEvent(&this->accel_event);
//    this->mag->getEvent(&this->mag_event);
//    
//    //--fusion roll/pitch
//    if (this->dof->fusionGetOrientation(&this->accel_event, &this->mag_event, &this->orientation)) {
//        this->roll = this->orientation.roll;
//        this->pitch = this->orientation.pitch;
//    }
//    
//    //--fusion compensated heading
//    if (this->dof->magTiltCompensation(SENSOR_AXIS_Z, &this->mag_event, &this->accel_event)) {
//        if (this->dof->fusionGetOrientation(&this->accel_event, &this->mag_event, &this->orientation)) {
//            this->heading = this->orientation.heading;
//        }
//    }
//
    //--accelleration
    this->accel->getEvent(&this->accel_event);
    
    this->accellerationX = (int16_t) this->accel_event.acceleration.x;
    this->accellerationY = (int16_t) this->accel_event.acceleration.y;
    this->accellerationZ = (int16_t) this->accel_event.acceleration.z;
    
    //--pitch, roll
    this->mag->getEvent(&this->mag_event);

    if (this->dof->fusionGetOrientation(&this->accel_event, &this->mag_event, &this->orientation)) {
        this->roll = map(this->orientation.roll, this->fromLow, this->fromHigh, this->toLow, this->toHigh);
        this->pitch = map(this->orientation.pitch, this->fromLow, this->fromHigh, this->toLow, this->toHigh);
        if (this->dof->magTiltCompensation(SENSOR_AXIS_Z, &this->mag_event, &this->accel_event)) {
            this->heading = map(this->orientation.heading, this->fromLow, this->fromHigh, 0, 360);
        }
    }
}

void SensorDof::onChange() {
    //--roll
    if (this->roll != this->pRoll) {
        this->send();
    }
    this->pRoll = this->roll;
    
    //--pitch
    if (this->pitch != this->pPitch) {
        this->send();
    }
    this->pPitch = this->pitch;
    
    //--heading
    if (this->heading != this->pHeading) {
        this->send();
    }
    this->pHeading = this->heading;
    
    //--accelleration
    if (this->accellerationX != this->pAccellerationX
        || this->accellerationY != this->pAccellerationY
        || this->accellerationZ != this->pAccellerationZ) {
        this->send();
    }
    this->pAccellerationX = this->accellerationX;
    this->pAccellerationY = this->accellerationY;
    this->pAccellerationZ = this->accellerationZ;
}

void SensorDof::print() {
    Serial.print("print: ");
    Serial.print(this->address);
    Serial.print(", ");
    Serial.print(this->roll);
    Serial.print(", ");
    Serial.print(this->pitch);
    Serial.print(", ");
    Serial.print(this->heading);
    Serial.print(", ");
    Serial.print(this->accellerationX);
    Serial.println();
}

//void SensorDof::send() {
//    if (this->bBroadcast) {
//        Serial.print("send: ");
//        Serial.print(this->address);
//        Serial.print(", ");
//        Serial.print(this->roll);
//        Serial.print(", ");
//        Serial.print(this->pitch);
//        Serial.print(", ");
//        Serial.print(this->heading);
//        Serial.println();
//        
//        msg.empty();
//        msg.add((int16_t) this->roll);
//        msg.add((int16_t) this->pitch);
//        msg.add((int16_t) this->heading);
//        msg.add((float) this->accelleration.x);
//        msg.add((float) this->accelleration.y);
//        msg.add((float) this->accelleration.z);
//        
//        Udp.beginPacket(this->outIp, this->outPort);
//        msg.send(Udp);
//        Udp.endPacket();
//        msg.empty();
//    }
//}

void SensorDof::send() {
    if (this->bBroadcast) {
        Serial.print("send: ");
        Serial.print(this->address);
        Serial.print(", ");
        Serial.print(this->roll);
        Serial.print(", ");
        Serial.print(this->pitch);
        Serial.print(", ");
        Serial.print(this->heading);
        Serial.print(", ");
        Serial.print(this->accellerationX);
        Serial.print(", ");
        Serial.print(this->accellerationY);
        Serial.print(", ");
        Serial.print(this->accellerationZ);
        Serial.println();
        
        this->bndl.add("/dof/rph")
            .add((int16_t) this->roll)
            .add((int16_t) this->pitch)
            .add((int16_t) this->heading);
        
        Udp.beginPacket(this->outIp, this->outPort);
        this->bndl.send(Udp);
        Udp.endPacket();
        this->bndl.empty();
        
        this->bndl.add("/dof/accelleration/xyz")
            .add((int16_t) this->accellerationX)
            .add((int16_t) this->accellerationY)
            .add((int16_t) this->accellerationZ);

        Udp.beginPacket(this->outIp, this->outPort);
        this->bndl.send(Udp);
        Udp.endPacket();
        this->bndl.empty();
    }
}

