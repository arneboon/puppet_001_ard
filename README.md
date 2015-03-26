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
* /mc/dof/rph
 * roll: range -100 - 100
 * pitch: range -100 - 100
 * heading: range 0 - 360
* /mc/dof/accelleration/xyz
 * x: range -100 - 100
 * y: range -100 - 100
 * z: range -100 - 100
* /mc/flex
 * range -100 - 100
