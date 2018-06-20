#!/bin/sh
#The path to the directory of gps__init__.py
export PATH=$PATH:/home/pi/Repository/GPS_Data_Parser/
#The path to Python3
export PYTHONPATH=/usr/local/Python3
#Executes the script which is already executable
exec gps__init__.py