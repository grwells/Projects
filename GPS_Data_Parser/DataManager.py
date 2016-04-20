'''
Created on Mar 23, 2016

@author: deepg
'''

#Imports from Monty!
import subprocess
import Parser
from clint.textui import puts, colored

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
        puts(colored.cyan('Status:') + colored.green(' Active'))
            
        #Location
        location_north = sentence[22:31]
        location_west = sentence[34:44]
        puts(colored.cyan('Location North: ') + colored.magenta(location_north))
        puts(colored.cyan('Location West: ') + colored.magenta(location_west))
        
        #Speed knots
        speed_knots = sentence[44:48]
        puts(colored.cyan('Velocity(Knots): ') + colored.magenta(speed_knots))
        
        #Angle of Velocity
        angle_ofvelocity = sentence[49:55]
        puts(colored.cyan('Angle of Velocity: ') + colored.magenta(angle_ofvelocity))
            
    
    else:
        
        puts(colored.cyan('Status:') + colored.red(' Inactive'))
        puts(colored.red(gp_status))
        

def write_tofile(fill_limit, save_tofile=False):
    
    puts(colored.green('---Process Starting---'))
    line_count = 0
    subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
    puts(colored.green('---Baud rate set---'))
    
    result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
    puts(colored.green('---PIPE IS OPEN---'))
    
    if save_tofile:
        
        #Specify the file to write to        
        puts(colored.red('Please enter the name of the file that you would like to save the data to in the line below,'))
        file_toWrite = input()
        
        puts(colored.red('--WARNING-- \nIf the file named above is preexisting and contains data, that data will be overwritten with' +
              'the new data from the GPS. Would you like to continue?'))
        
        continue_Writing = input()
        
        if continue_Writing == 'yes':
            
            print('---Opening File---')
            f = open(file_toWrite, 'w')
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
                #print("%s" %line)
                Parser.identify_sentence("%s" %line)
                line_count += 1
                print('Count is now: ' + str(line_count))
            else:
                print('---Limit Reached---')
                print('---Ending Process---')
                break
    
    
    print('---Process Ended---')



