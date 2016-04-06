'''
Created on Apr 4, 2016

@author: deepg
'''

def parse_location(sentence):
    '''
    Parse the location data in the sentence
    '''
        
    
def parse_RMC(sentence):
    '''
    Parse the sentence and find the important chucks of data
    '''
    #Location
    location_north = sentence[20:31]
    location_west = sentence[32:44]
    
    #Speed knots
    speed_knots = sentence[44:48]
    
    #Angle of Velocity
    angle_ofvelocity = sentence[49:55]
    
    #Time in hours, minutes, seconds, and milliseconds
    gmt = sentence[7 : 16]
    
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
        if line[0:5] == '$GPRMC':
            parse_RMC(line)
        
 
  
parse_file('GPS_Data.txt')