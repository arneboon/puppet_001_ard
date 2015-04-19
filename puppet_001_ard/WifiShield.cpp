//
// WifiShield_h_.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		puppet_001_ard
//
// Created by 	Arne Boon, 01/03/15 17:18
// 				Studio Arne Boon
//
// Copyright 	(c) Arne Boon, 2015
// Licence		<#license#>
//
// See 			WifiShield.h .h and ReadMe.txt for references
//


#include "WifiShield.h"

WifiShield::WifiShield() {
    this->status = WL_IDLE_STATUS;
}

void WifiShield::setup(String _ssid, String _pass) {
    Serial.println("setup WifiShield");
    this->ssid = _ssid;
    this->pass = _pass;
    
    
    Serial.println(this->pass);

    //--check if wifi shield is present
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("[ERROR] WiFi shield not present");
        return;
    } else {
        Serial.println("[OK] WiFi shield was found");
    }
    
    //--TODO: work with change in status loop here instead of stupid while with 10 sec delay
    
    //--attempt to connect
    while (status != WL_CONNECTED) {
        Serial.print("wifi status: ");
        Serial.println(this->status);
        Serial.print("attempt to connect to WPA SSID: ");
        Serial.println(this->ssid);
        
        char ssid[this->ssid.length() + 1];
        char pass[this->pass.length() + 1];
        
        this->ssid.toCharArray(ssid, this->ssid.length() + 1);
        this->pass.toCharArray(pass, this->pass.length() + 1);
        
        status = WiFi.begin(ssid, pass);
        delay(10000);
    }
    
    Serial.println("[OK] connected");
    
    printCurrentNet();
    printWifiData();

//    Udp.begin(8888);
}

void WifiShield::loop() {

    //--check status > set led
//    WL_CONNECTED, WL_CONNECT_FAILED, WL_CONNECTION_LOST, WL_DISCONNECTED, WL_IDLE_STATUS, WL_SCAN_COMPLETED etc
}



void WifiShield::printCurrentNet() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    
    // print the MAC address of the router you're attached to:
    byte bssid[6];
    WiFi.BSSID(bssid);
    Serial.print("BSSID: ");
    Serial.print(bssid[5], HEX);
    Serial.print(":");
    Serial.print(bssid[4], HEX);
    Serial.print(":");
    Serial.print(bssid[3], HEX);
    Serial.print(":");
    Serial.print(bssid[2], HEX);
    Serial.print(":");
    Serial.print(bssid[1], HEX);
    Serial.print(":");
    Serial.println(bssid[0], HEX);
    
    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.println(rssi);
    
    // print the encryption type:
    byte encryption = WiFi.encryptionType();
    Serial.print("Encryption Type:");
    Serial.println(encryption, HEX);
}

void WifiShield::printWifiData() {
    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    
    // print your MAC address:
    byte mac[6];
    WiFi.macAddress(mac);
    Serial.print("MAC address: ");
    Serial.print(mac[5], HEX);
    Serial.print(":");
    Serial.print(mac[4], HEX);
    Serial.print(":");
    Serial.print(mac[3], HEX);
    Serial.print(":");
    Serial.print(mac[2], HEX);
    Serial.print(":");
    Serial.print(mac[1], HEX);
    Serial.print(":");
    Serial.println(mac[0], HEX);
}

String WifiShield::getId() {
    byte mac[6];
    WiFi.macAddress(mac);
    this->macaddress = "";
//    this->macaddress += String(mac[5], HEX);
//    this->macaddress += String(mac[4], HEX);
//    this->macaddress += String(mac[3], HEX);
    this->macaddress += String(mac[2], HEX);
    this->macaddress += String(mac[1], HEX);
    this->macaddress += String(mac[0], HEX);
    
    return this->macaddress;
}
