#!/usr/bin/python3
'''
Created on Mar 23, 2016

@author: deepg
'''

#Imports from Monty!
import subprocess
import time
import Parser
import datetime
from clint.textui import puts, colored


'''
Increments hours_elapsed based on the time elapsed between current_time and last_time which are string versions of the times from the datetime lib
'''
def get_timeDelta(current_time, last_time):
    global hours_elapsed
    global last_timeStamp
    current_minute = int(current_time[14:16])
    start_minute = int(last_time[14:16])
    
    portion_ofhour = 0.0
    
    if current_minute >= start_minute:
        portion_ofhour = current_minute - start_minute
        
    else:
        portion_ofhour = (60 - start_minute) + current_minute
        
    portion_ofhour = portion_ofhour/60
    hours_elapsed += float(portion_ofhour)
    last_timeStamp = current_time
    
    

def write_tofile(fill_limit, keep_time=False,  save_tofile=False):
    
    puts(colored.green('---Process Starting---'))
    line_count = 0
    subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
    puts(colored.green('---Baud Rate Set---'))
    
    result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
    puts(colored.green('-----Pipe Is Open-----'))
    
    if save_tofile:
        
        #Specify the file to write to        
        puts(colored.red('Please enter the name of the file that you would like to save the data to in the line below: '))
        file_toWrite = input()
                
        #puts(colored.red('--WARNING-- \nIf the file named above is preexisting and contains data, that data will be overwritten with' +
            #'the new data from the GPS. Would you like to continue?'))
        
        continue_Writing = input(colored.magenta('If the selected file already exists would you like to overwrite the information, if there is any, that is stored in it?(y/n): '))
        
                
        if continue_Writing == 'yes' or continue_Writing == 'y' or continue_Writing == 'Yes':                
            puts(colored.cyan('---Opening File---'))
            f = open(file_toWrite, 'w')
            puts(colored.cyan('---File Open---'))
                
        elif continue_Writing == 'n' or continue_Writing == 'no' or continue_Writing == 'No':
            print('---Opening File---')
            f = open(file_toWrite, 'a')
            print('---File Open---')
        
        
        if keep_time == True:
            time_limit = input(colored.green('Enter time limit in hours or a fraction of an hour: '))
            #
            time_limit = float(time_limit)
            #         
            start_time = str(datetime.datetime.now())
            #
            puts(colored.green('Starting Data Collection At: ' + start_time))
            #
            last_timeStamp = start_time
            #
            for line in result.stdout: 
                get_timeDelta(str(datetime.datetime.now()), last_timeStamp)                                      
                if hours_elapsed <= time_limit: 
                    Parser.identify_sentence("%s" %line)
                    line = "%s" %line                        
                    if line[0 : 8] == "b\'$GPRMC":                        
                        f.write("%s\n" %line)
                        line_count += 1
                                                           
                else: 
                    puts(colored.green('---Closing File---'))                       
                    f.close()
                    puts(colored.green('---File Closed---'))
                    end_time = str(datetime.datetime.now())
                    puts(colored.green('Stopped Data Collection At: ' + end_time))
                    break
                
            
        else: 
            for line in result.stdout:
                if line_count < fill_limit:
                    Parser.identify_sentence("%s" %line)
                    f.write("%s\n" %line)
                    #print("%s" %line)
                    line_count += 1
                    #print('Count is now: ' + str(line_count))
                else:
                    puts(colored.green('---Limit Reached---'))
                    puts(colored.green('---Ending Process---'))
                    puts(colored.green('---Closing File---'))                       
                    f.close()
                    puts(colored.green('---File Closed---'))
                    break
                    
            
                
        
         
                        
    
    #Print data into the user interface    
    else:  
        puts(colored.red('Press Ctrl + C to Terminate Program', bold=True))
        time.sleep(5)        
        for line in result.stdout:
            if line_count < fill_limit:
                Parser.identify_sentence("%s" %line)
                line_count += 1
                 
            else:
                puts(colored.green('---Limit Reached---'))
                puts(colored.green('---Ending Process---'))
                break
    
    
    puts(colored.green('---Process Ended---'))



