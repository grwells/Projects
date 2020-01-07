Owner and Author: Garrett Wells

The goal of this project is to create the code for an autonomous greenhouse for I61 ministries. The goal of the project is to make a project that will run as long as possible and feature code that is cross-compatible with raspberry pi and arduino. It will have the following functionality.
	
* Temperature:
	- maintain and record the temperature inside the greenhouse.

* Humidiy:
	- maintain and record the humidity within the greenhouse.

* Barometric Pressure:
	- record the pressure.

* Current:
	- measure the current consumption of the pi, battery, and solar panels.
	
* Voltage:
	- measure the voltage of the battery using an algorithm.

* Data Storage:
	- store the data as a function of time to be recorded in a file.

* Alarm:
	- warn user if system functionality deteriorates.


#### COMPILING WITH WIRINGPI:
In order to compile projects that reference wiringPi the following should be entered.
		
	g++ filename.cpp -o blink -lwiringPi

#### CONFIGURING C++ HEADERS:
In order for the compiler to run, the header files must be stored in /usr/local/include,
/usr/include, or any of the directories listed by "gcc -print-prog-name=cc1plus` -v".
