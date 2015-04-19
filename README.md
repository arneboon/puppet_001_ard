# puppet_001_ard
Maplab research project sensing & tracking.  

# Disclamer
This project is currently under development and not production ready.  

# IDE
Arduino application 1.6.1: http://www.arduino.cc/en/Main/OldSoftwareReleases  
embedXcode: http://embedxcode.weebly.com/  
(Install Arduino in default location)  

# Hardware
Board: Arduino Mega 2560  
Shield 1: Arduino Wifi Shield  
Shield 2: Custom Maplab Board  

# Preparation
Upgrade wifi shield to v1.1.0: http://www.arduino.cc/en/Hacking/WiFiShieldFirmwareUpgrading  
More: http://katrinaeg.com/arduino-wifi-firmware-upgrade.html  
$ cd wifishield/firmware/scripts  
$ sudo sh ArduinoWifiShield_upgrade_mac.sh -a /Applications/Arduino.app/Contents/Resources/Java -f shield  

# Dependencies
Make sure to clone into your sketchbook/libraries folder:  
https://github.com/adafruit/Adafruit_Sensor  
https://github.com/adafruit/Adafruit_LSM303DLHC  
https://github.com/adafruit/Adafruit_L3GD20_U  
https://github.com/adafruit/Adafruit_BMP085_Unified  
https://github.com/adafruit/Adafruit_9DOF  
https://github.com/adafruit/Adafruit_10DOF  

# OSC port & ip
port: 1234 (standard isadora)  
broadcast to local router (routing 255.255.255.255)  

# OSC addresses & value ranges
see setup() function in .ino file in root folder for current address listing  

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
