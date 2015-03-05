# puppet_001_ard
Maplap research project sensing & tracking.

# IDE
embedXcode  

# Hardware
Board: Arduino Mega 2560  
Shield 1: Arduino Wifi Shield  
Shield 2: Custom protoboard (sensor to pin routing)  

# OSC port & ip
port: 1234 (standard isadora)  
broadcast to local router (routing 255.255.255.255)  

# OSC addresses & value ranges
see setup() function in .ino file in root folder for current address listing  

* /magnet/analog
 * range -512 - 0 - 512
* /magnet/digital
 * range 0, 1
* /button/1
 * range 0, 1
* /button/2
 * range 0, 1
* /button/3
 * range 0, 1
* /button/4
 * range 0, 1
* /distance
 * range 0-400 (centimeters)
* /dof/rph
 * roll: range -180 - 0 - 180
 * pitch: range -180 - 0 - 180
 * heading: range -180 - 0 - 180
* /flex
 * range -512 - 512
