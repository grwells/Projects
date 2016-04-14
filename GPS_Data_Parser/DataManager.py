'''
Created on Mar 23, 2016

@author: deepg
'''

#Imports from Monty!
import subprocess

def parse_RMC(sentence):
    '''
    Parse the sentence and find the important chucks of data
    '''
    #Time in hours, minutes, seconds, and milliseconds
    gmt = sentence[7 : 16]
    print(gmt)
    
    #Status
    gp_status = sentence[20]
        
    if gp_status == 'A':
        print('Status: Active')
            
        #Location
        location_north = sentence[20:31]
        location_west = sentence[32:44]
        print('Location North: ' + location_north)
        print('Location West: ' + location_west)
        
        #Speed knots
        speed_knots = sentence[44:48]
        print('Velocity(Knots): ' + speed_knots)
        
        #Angle of Velocity
        angle_ofvelocity = sentence[49:55]
        print('Angle of Velocity: ' + angle_ofvelocity)
            
    
    else:
        
        print('Status: Inactive')
        print(gp_status)
        

def write_tofile(fill_limit, save_tofile=False):
    print('---Process Starting---')
    line_count = 0
    subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
    print('-Baud rate set-')
    
    result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
    print('---PIPE IS OPEN---')
    
    if save_tofile:
        
        print('---Opening File---')
        f = open('GPS_Data.txt', 'w')
        print('---File Open---')
        
        for line in result.stdout:
            if line_count < fill_limit:
                f.write("%s\n" %line)
                print("%s" %line)
                line_count += 1
                print('Count is now: ' + str(line_count))
            else:
                print('---Limit Reached---')
                print('---Ending Process---')
                f.close()
                break
            
            
    
        
    else:
       
        for line in result.stdout:
            if line_count < fill_limit:
                #f.write("%s\n" %line)
                print("%s" %line)
                parse_RMC("%s\n" %line)
                line_count += 1
                print('Count is now: ' + str(line_count))
            else:
                print('---Limit Reached---')
                print('---Ending Process---')
                break
    
    
    print('---Process Ended---')



