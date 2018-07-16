# FONA Cellular Module
The FONA cellular breakout board can be used with raspberry pi or arduino to connect to 2G cellular networks and scan FM radio broadcasts.

## Datasheets:
* [Adafruit](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-fona-800-shield.pdf)
* [Raspberry Pi and Beagle Bone Black](https://learn.adafruit.com/fona-tethering-to-raspberry-pi-or-beaglebone-black/setup)
* [Adafruit Tutorial](https://learn.adafruit.com/adafruit-fona-mini-gsm-gprs-cellular-phone-module?view=all#wiring-to-usb)
* [Command Manual](https://cdn-shop.adafruit.com/product-files/1946/SIM800+Series_AT+Command+Manual_V1.09.pdf)

## FONA Usage:
The Adafruit FONA board can be accessed in several different ways. It can be communicated with using PPP(Point-to-Point Protocol) and usb serial connection through Putty(Windows).

## Setup GPRS:
> sudo pon fona
> //List commands run by ppp
> cat /var/log/syslog | grep pppd
> //If all is successful, the new ppp interface network should show with the following command
> ifconfig // or ip -a?

###### GPRS Usage:
The FONA unit can be tethered to a raspberry pi or beagle bone black using serial communication. Instructions on how to do so can be found below.

1. Install serial pin control script
> sudo wget https:/raw.github.com/lurch/rpi-serial-console/master/rpi-serial-console -0 /usr/bin/rpi-serial-console && sudo chmod +x /usr/bin/rpi-serial-console

1. Disable pi debug messages over serial pins. This makes sure that the kernel will not print boot debug messages over the serial console.
> sudo rpi-serial-console disable	

1. Install PPP(Point-to-Point Protocol) for communication
> sudo apt-get update
> sudo apt-get install ppp screen elinks
> screen /dev/ttyAMA0 115200 //this opens a serial port to the FONA, press Ctrl-A, type :quit, and press enter
> //Once the port is open, type 'AT'. FONA will reply with 'OK' if all is working right

1. Configure PPP
> sudo -i
> cd /etc/ppp/peers/
> //Download example config file 
> wget https://raw.githubusercontent.com/adafruit/FONA_PPP/master/fona
> //Edit the fona file
> sudo vim fona

Change the APN value to: connect "/usr/sbin/chat -v -f /etc/chatscripts/gprs -T internet"
Also, if using raspberry pi(assumed), uncomment the line with "/dev/tty/AMA0"



