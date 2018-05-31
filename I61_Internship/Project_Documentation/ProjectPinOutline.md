# Project Pin Outline
This is an overview of how many and what pins will be used by the battery and water management systems to fulfill the functionality outlined in the project [README](https://github.com/countryBumpkin/Projects/blob/master/I61_Internship/README.md).

## Water Management System:
* Sensors:
  * DS18B20 Water Proof Temperature Sensor (1 gpio pin)
  * HC-SR04 Ultrasonic(distance) Sensor    (2 gpio pins)

* Power Management:
  * Water Pump Relay                       (1 gpio pin)     
  * Release Valve/Pump Relay               (1 gpio pin)     

* Communication:
  * Radio(TBD)                             (2 gpio pins)
  * Cellular(TBD)                          (4 gpio pins)

## Battery Management System:
* Sensors:
  * Tolako5V Hall-Effect Sensor           (1 gpio pin)
  * INA219 Sensor                         (0 gpio pins, i2c device)

* Communication:
  * Radio(TBD)
  * Cellular(TBD)

## Summary:
Overall the system requires 6 gpio pins to cover the basic project functionality and an additional 6 pin for communication purposes.
