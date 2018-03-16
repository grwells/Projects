# Internship I61
This repository contains all personal code for the autonomous water management and green house system. Members of the I61 internship team are welcome to use this code as a resource. Each subdirectory contains the source code for a sensor as well as a README.md file that contains a basic synopsis of the sensor's purpose, use, and relevant information from retailers and manufacturers.

## Water Management System
This system's goal is to monitor the water level in a tank or network of water storage devices and either pump or release water when needed. The system will also implement temperature measuring.

### System Outline:
* Water level sensor(HC-SR04)
* Pump on off switch
* Radio or cellular communication capability
* Temperature sensor

## Batery Management System
The BMS system will monitor the charge levels of a battery bank, send alerts when power levels become dangerously low, and manage power consumption of all attached systems.

### System Outline:
* Current sensor between power source and battery
* Current sensor between battery and all other components
* Alert system
* Adaptable firmware power consumption monitor and manager

## Green House System
The GHS controls all systems in a greenhouse autonomously. This includes watering systems, ventilation, and humidity.

### System Outline:
* Humidity/Temperature sensor
* Task scheduler
* Ventilation control system
* Watering system control
