#!/usr/bin/python3
#
import RPi.GPIO as GPIO
#
def startLights():
    #
    #Initialize PWM
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)
    GREEN_LED = 18
    RED_LED = 23
    GPIO.setup(GREEN_LED, GPIO.OUT)
    GPIO.setup(RED_LED, GPIO.OUT)
    #
    #
    def loop():
        try:
            print("Press Ctrl-C to quit")
            while True:
                GPIO.output(GREEN_LED, True)
                GPIO.output(RED_LED, False)
                GPIO.output(GREEN_LED, False)
                GPIO.output(RED_LED, True) 
         
        finally:
            print("cleaning up")
            GPIO.cleanup()
#                   
#
startLights()
