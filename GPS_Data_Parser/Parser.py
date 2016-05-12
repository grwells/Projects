'''
Created on Apr 4, 2016

@author: deepg
'''

from clint.textui import puts, colored
sentence = ''


def parse_location(gmt):
    '''
    Parse the time data in the sentence and convert it to a readable format
    '''
    hours = gmt[0 : 2]
    minutes = gmt[2 : 4]
    seconds = gmt[4 : 6]
    milliseconds = gmt[6 : 8]
    
    print('Current Time: ' + hours + ' hrs, ' + minutes + ' min, ' + seconds + ' sec, ' + milliseconds  + ' millisec ')
    

def parse_time(gmt):
    '''
    Parse the time data in the sentence and convert it to a readable format
    '''
    hours = gmt[0 : 2]
    
    if int(hours) >= 12:
        half_ofDay = 'PM'
        hours = int(hours) - 12
    
    else:
        half_ofDay = 'AM'
    
    minutes = gmt[2 : 4]
    seconds = gmt[4 : 6]
    milliseconds = gmt[7 : 10]
    
    puts(colored.yellow(str(hours) + ':' + minutes + ':' + seconds + ':' + milliseconds + ' ' + half_ofDay))
    
def parse_RMC(sentence):
    '''
    Parse the sentence and find the important chucks of data
    '''
    gp_status = sentence[20]
        
    if gp_status == 'A':
        puts(colored.cyan('Status:') + colored.green(' Active'))
        
        #Date MM:DD:YYYY
        day = sentence[59 : 61]
        month = sentence[61 : 63]
        year = sentence[63 : 65]
        puts(colored.yellow('Date: ' + month + ', ' + day + ', 20' + year))
        
        
        #Time
        gmt = sentence[9 : 19] 
        parse_time(gmt)
        
        
        #Location
        location_north = sentence[22:31]
        location_west = sentence[34:44]
        puts(colored.cyan('Location North: ') + colored.magenta(location_north))
        puts(colored.cyan('Location West: ') + colored.magenta(location_west))
        
        #Speed knots
        speed_knots = sentence[47:51]
        puts(colored.cyan('Velocity(Knots): ') + colored.magenta(speed_knots))
        
        #Angle of Velocity
        angle_ofvelocity = sentence[52:58]
        puts(colored.cyan('Angle of Velocity: ') + colored.magenta(angle_ofvelocity))
                    
    
    else:
        
        puts(colored.cyan('Status:') + colored.red(' Inactive'))
        puts(colored.red(gp_status))
            
        
'''
b'$GPRMC,194509.000,A,4042.6142,N,07400.4168,W,2.03,221.11,160412,,,A*77 
'''
def identify_sentence(sentence):
    if sentence[0 : 8] == "b\'$GPRMC":
        parse_RMC(sentence)
        return True
    else:
        return False
    
     
def parse_file(file):
    '''
    
    Parse through the data and call different methods depending on first six characters of the NMEA sentence.
    Most Important Sentence: $GPRMC (Global Position Recommended Minimum)
    
    '''
     
    try:
        f = open(file, 'r')
        for line in f:
            identify_sentence(line)
           
    except IOError:
        puts(colored.red('Could not open: ' +  file))
        try_again = input(colored.red('Try Again? (y/n): '))
            
        if (try_again == 'y') or (try_again == 'yes'):
            file = input(colored.red('Enter Name of File: '))
            parse_file(file)
