# Introduction
This software was developed by Studio Arne Boon for a Maplab research project about digital puppeteering. The project aims at integrating sensor technology in a puppet so that the the actor can animate not only the puppet but also the space using sounds and projections.  

# Disclamer
This project is currently under development and not production ready.  

# License
This software is licensed under a Creative Commons Attribution-Noncommercial-ShareAlike 4.0 International License by Studio Arne Boon.  
https://creativecommons.org/licenses/by-nc-sa/4.0/  
https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode  

# IDE
Arduino application 1.6.1: http://www.arduino.cc/en/Main/OldSoftwareReleases  
embedXcode: http://embedxcode.weebly.com/  
Install Arduino in default location and use embedXcode as IDE.    

# Hardware
Board: Arduino Mega 2560  
Shield 1: Arduino Wifi Shield  
Shield 2: Custom Maplab Board  

# Preparation
Upgrade wifi shield to v1.1.0: http://www.arduino.cc/en/Hacking/WiFiShieldFirmwareUpgrading  
More: http://katrinaeg.com/arduino-wifi-firmware-upgrade.html  
```
$ cd wifishield/firmware/scripts  
$ sudo sh ArduinoWifiShield_upgrade_mac.sh -a /Applications/Arduino.app/Contents/Resources/Java -f shield  
```

# Dependencies
The project uses the Arduino native SPI, WiFi and Wire libraries. And depends on ceveral external libraries that needs to be installed in your development environment. Make sure to clone into your sketchbook/libraries folder: 
https://github.com/CNMAT/OSC  
https://code.google.com/p/arduino-new-ping/   
https://github.com/adafruit/Adafruit_Sensor  
https://github.com/adafruit/Adafruit_LSM303DLHC  
https://github.com/adafruit/Adafruit_L3GD20_U  
https://github.com/adafruit/Adafruit_BMP085_Unified  
https://github.com/adafruit/Adafruit_9DOF  
https://github.com/adafruit/Adafruit_10DOF (alternative)  

In the embedXcode Makefile the libraries are linked by these lines:  
```
APP_LIBS_LIST = SPI WiFi Wire
```

```
USER_LIBS_LIST = Adafruit_9DOF Adafruit_L3GD20_U Adafruit_LSM303DLHC Adafruit_Sensor OSC NewPing
```

# OSC port & ip
The WiFi module broadcasts OSC messages using the following port and ip:  
port: 1234 (standard isadora)  
broadcast to local router (routing 255.255.255.255)  

# Maplab board
The software works in conjunction with the custom Maplab sensorkit board that was developed for the lab. It provides an easy infrastructure for connecting sensors using industry standard JST connections. For this particulair project it makes the data of the following sensors accessible over OSC on the local network:  
* Analog Magnetic Field Sensor
* Digital Magnetic Field Sensor
* Sonar Distance Sensor
* Flex bending Sensor
* 9 Degrees of Freedom Sensor
* Momentary Push Buttons

# OSC addresses & value ranges
In the setup() function in .ino file in the root folder the OSC address listing is initiated using the following value ranges:    
* /mc/magnet/analog
 * range -100 - 100
* /mc/magnet/digital
 * range 0, 1
* /mc/button/1
 * range 0, 1
* /mc/button/2
 * range 0, 1
* /mc/button/3
 * range 0, 1
* /mc/button/4
 * range 0, 1
* /mc/distance
 * range 0-400 (centimeters)
* /mc/dof/rphxyz
 * roll: range -100 - 100
 * pitch: range -100 - 100
 * heading: range 0 - 360
 * x: range -100 - 100
 * y: range -100 - 100
 * z: range -100 - 100
* /mc/flex
 * range -100 - 100

# Software Architecture
* Config.h
 * Wifi Credentials: enter you local networks SSID and passphrase
 * Pin Layout: pin mapping of the sensors connected to the Maplab board
 * Settings: specific sensor settings such as maximum distance to read
* puppet_001_ard.ino
 * #includes: include the sensorclasses that extend the SensorBase class
 * initialize: initialize a sensor, for instance SensorDigital myDigitalSensor
 * setup(): setup the new object myDigitalSensor
 * loop(): update the sensor each loop
* SensorBase.h
 * Each sensorclass extends this baseclass that takes care of the common functions.
 * OSC_OUT_IP: the ip address of the receiving machine
 * OSC_OUT_PORT: the osc port on the receiving machine
* Makefile
 * embedXcode settings
* Sketchbook
 * Libraries: links to the libraries in your default Sketchbook/Libraries folder

# Workflow for setting up a sensor
*	Connect the sensor to the Maplab board using JST connectors (Digital, Analog, I2C)
*	Config.h / WifiCredentials: enter your network configuration
```
char ssid[] = "MY_NETWORK_SSID";
char passphrase[] = "MY_NETWORK_PASSWORD";
```
*	Config.h / PinLayout: name your sensor and initialize its pin number
```
namespace PinLayout {
	const int8_t myAnalogSensor = A1;
}
```
* 	*.ino / declaration: declare the object for you new sensor
```
SensorAnalog myAnalogSensor;
```
* 	*.ino / setup(): setup your new sensor with an osc address and pin layout
```
myAnalogSensor.setup("/mc/"+id+"myAnalogSensor", PinLayout::myAnalogSensor, INPUT);
```
*	*.ino / setup(): broadcast your new sensor using OSC
```
myAnalogSensor.broadcast(true);
```
*	*.ino / setup() [optional]: set and map the range for the sensor
```
myAnalogSensor.setRange(0,1024,0,100);
```
*	*.ino / loop(): update the sensor each loop
```
myAnalogSensor.loop();
```
*	Use OSCulator, Isadora, Max or any other OSC receiving program to test if the data is sent

