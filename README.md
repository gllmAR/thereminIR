thereminIR
========

Arduino based infrared «theremin» MIDI controller.

Create a MIDI controller using infrared proximity sensors and arduino.

#### Material

* Arduino (tested with Leonardo ethernet)
* USB cable
* 3 x infrared range finder
	* Sharp [GP2Y0A21YK0F](http://www.robotshop.com/ca/en/sharp-gp2y0a21yk0f-ir-range-sensor.html) IR Range Sensor - 10 cm to 80 cm
	* 3 x [sensors wires](http://www.robotshop.com/ca/en/sirc-01-sharp-gp2-ir-sensor-cable-8.html)
* Headers (.1 inch pitch)
* Soldering iron



####  Wiring schematic

![schematic/thereminIR_bb.png](schematic/thereminIR_bb.png)  

#### XLR 5 pin out

* 1 : gnd
* 2 : a0
* 3 : v++
* 4 : a1
* 5 : a2

#### Arduino IDE
* Download and install the latest version of the arduino IDE compatible with your board.  
	* Arduino .ORG http://www.arduino.org
	* Arduino/Genuino .CC https://www.arduino.cc
* Download and install arcore from https://github.com/rkistner/arcore
	* Follow the installation method


#### Code structure
coded/tested with arduino Leonardo ethernet with IDE  1.7.8 from arduino.org
* Arduino / Serial Midi:
	* Basic example to get raw data over serial bus
* Arduino / Native Midi :
	* Example using native MIDI over USB with Arcore
* Max : patch to see the data from the sensors (tested with max 7)
* Pd : patch to hear the data from sensors  (work with PD vanilla v 0.47)
* schematic : fritzing schematic

#### References

##### Infrared theremin on the internet  
* http://people.ece.cornell.edu/land/courses/ece4760/FinalProjects/f2013/sjm298_ar568/sjm298_ar568/sjm298_ar568/index.html
* http://www.pyroelectro.com/projects/mini_ir_theremin/
* http://bondoukousoftware.com/InfraredTheremin.html
* http://atmega32-avr.com/infrared-theremin-using-atmega1284/

##### MIDI
* http://www.instructables.com/id/DIY-Arduino-Based-MIDI-Foot-Controller/?ALLSTEPS

##### alternative to arcore
* https://github.com/adafruit/TeeOnArdu

##### Audio on arduino
* http://playground.arduino.cc/Main/ArduinoSynth
* http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/


##### Laser harp
* http://harpelaserarduino.blogspot.ca
