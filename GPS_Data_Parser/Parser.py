'''
Created on Apr 4, 2016

@author: deepg
'''
sentence = ''
gmt = sentence[7 : 16] 

def parse_location(gmt):
    '''
    Parse the time data in the sentence and convert it to a readable format
    '''
    hours = gmt[0 : 2]
    minutes = gmt[2 : 4]
    seconds = gmt[4 : 6]
    milliseconds = gmt[6 : 8]
    
    print('Current Time: ' + hours + ' hrs, ' + minutes + ' min, ' + seconds + ' sec,' + milliseconds  + ' millisec ')
    

def parse_time(gmt):
    '''
    Parse the time data in the sentence and convert it to a readable format
    '''
    hours = gmt[0 : 2]
    minutes = gmt[2 : 4]
    seconds = gmt[4 : 6]
    milliseconds = gmt[6 : 8]
    
    print('Current Time: ' + hours + ' hrs, ' + minutes + ' min, ' + seconds + ' sec,' + milliseconds  + ' millisec ')
    
    
def parse_RMC(sentence):
    '''
    Parse the sentence and find the important chucks of data
    '''
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
        
    #Time in hours, minutes, seconds, and milliseconds
    gmt = sentence[7 : 16]
    print('Time:' + gmt)
    
    #Status
    gp_status = sentence[18]
    
    if gp_status == 'A':
        parse_location(sentence)
    
    else:
        current_status = sentence[18]
        print(current_status)
        print('---No Fix---')
    
def parse_file(file):
    '''
    
    Parse through the data and call different methods depending on first six characters of the NMEA sentence.
    Most Important Sentence: $GPRMC (Global Position Recommended Minimum)
    
    '''
    
    f = open('GPS_Data.txt', 'r')
    
    n = open('GPS_Log.txt', 'w')
    
    for line in f:
        if line[0:5] == 'b\'$GPRMC':
            parse_RMC(line)
        
 
  
parse_file('GPS_Data.txt')