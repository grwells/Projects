#!/usr/bin/python3
'''
Created on May 9, 2016

@author: deepg
'''
from clint.textui import colored, puts

record_data = 0
times_used = '0'
file_size = '0'
keep_time = '0'
time_limit = '0'

'''
Pulls user preferences from the settings file, stores them in the global variables
'''
def parse_file():
    global record_data
    global times_used
    global file_size
    global keep_time
    global time_limit
    global exit_config 

    f = open('settings', 'r')  
    count = 0    
      
    for line in f:
        line = line.rstrip('\n')
        line = line.strip()
                    
        if count == 0:
            times_used = line 
            puts(colored.green('Times Used: ') + colored.red(line))     
        
        elif count == 1:
            file_size = line
            puts(colored.green('File Size Limit: ') +  colored.red(line))
            
        elif count == 2:
            keep_time = line
            
            if line == '0':
                keep_thetime = 'No'
                puts(colored.green('Time Data Sample: ') + colored.red(keep_thetime))
            
            elif line == '1':
                keep_thetime = 'Yes'
                puts(colored.green('Time Data Sample: ') + colored.red(keep_thetime))
                
            else:
                puts(colored.red('---ERROR---'))
                puts(colored.red(line))
            
        elif count == 3:
            time_limit = line 
            puts(colored.green('Time Limit(hrs): ') + colored.red(line))
            
        elif count == 4:
            if line == '1':
                puts(colored.green('Record Data on Startup: ') + colored.red('Yes'))
                record_data = '1'
                
            elif line == '0':
                puts(colored.green('Record Data on Startup: ') + colored.red('No'))
                record_data = line
                
            else:
                puts(colored.red('---ERROR---'))
                puts(colored.red('Found: ') + colored.red(line))
        
            
        count += 1
    
    file_isClosed = False
    while file_isClosed == False:
        f.close()
        file_isClosed = f.closed
'''
Writes the contents of the global variables to the settings file, called immediately after the user exits
'''
def update_file():
    global record_data
    global times_used
    global file_size
    global keep_time
    global time_limit
    
    f = open('settings', 'w')  
    
    f.write(str(times_used))
    f.write('\n' + str(file_size))
    f.write('\n' + str(keep_time))
    f.write('\n' + str(time_limit))
    f.write('\n' + str(record_data))
    
    file_isClosed = False
    while file_isClosed == False:
        f.close()
        file_isClosed = f.closed
        
'''
Edits whether or not the data collection process is limited by time or number of lines
'''
def config_time():
    global keep_time
    global time_limit
    
    puts(colored.magenta('Time data collection?(y/n): '))
    response = input()
        
    if response == 'y':
        keep_time = '1'
        puts(colored.magenta('Enter time limit in hours or a fraction of an hour: '))        
        time_limit = input()
        
    elif response == 'n':
        keep_time = '0'   
        
    else:
        puts(colored.red('---ERROR---')) 
        puts(colored.red(response))
        
    
    update_file()
        
'''
Allows the user to reset the number of times that the app has been used
'''
def config_timesused():
    global times_used
    response = input(colored.magenta('Reset times used to zero?(y/n): '))
    if response == 'y':
        times_used = '0'
        
    update_file()

'''
Allows the user to change the number of lines that the raspberry pi will record
'''       
def config_size():
    global file_size
    puts(colored.magenta('Enter number of lines of data to be collected: '))
    response = input()
    file_size = response
    
    update_file()
     
'''
Allows the user to change whether the data is recorded at startup or not
''' 
def config_recordData():
    global record_data
    puts(colored.magenta('Record Data On Startup?(y/n): ')) 
    response = input() 
    
    if response == 'y':
        record_data = '1'
        
    elif response == 'n':
        record_data = '0'
        
    update_file()
    
'''
Handles the arguments passed on by the user 
'''
def parse_command(command):
    if command == 'config time limits':        
        config_time()
        
    elif command == 'config file size':        
        config_size()
    
    elif command == 'config times used':
        config_timesused()
        
    elif command == 'exit':
        exit_config = True
        
    elif command == 'print settings':
        print_currentSettings()
        
    elif command == 'config startup':
        config_recordData()
        
    else: 
        puts(colored.red(command) + colored.cyan(' is not a valid command, please enter a command from the list below') +
             colored.red('\nValid Commands:') + 
             colored.green('\n1. \"config time limits\"') + 
             colored.cyan('\n      allows the user to change how long data is recorded') +
             colored.green('\n2. \"config file size\"') +
             colored.cyan('\n      allows the user to change how many lines of data are recorded') +
             colored.green('\n3. \"config times used\"') +
             colored.cyan('\n      allows the user to reset the count of how many times the settings have been changed') +
             colored.green('\n4. \"print settings"') +
             colored.cyan('\n      allows the user to display the settings that are about to be written into the file') +
             colored.green('\n5. \"config startup\"') +
             colored.cyan('\n      allows the user to choose whether or not data is recorded on startup') +
             colored.green('\n6. \"exit\"') +
             colored.cyan('\n      enter this command to go back to the main menu'))       
             


        
def print_currentSettings():
    global record_data
    global times_used
    global file_size
    global keep_time
    global time_limit
    
    puts(colored.green('Times Used: ') + colored.red(times_used))
    
    if record_data == '1':
        puts(colored.green('Record Data: ') + colored.red('Yes'))
    
    elif record_data == '0':
        puts(colored.green('Record Data: ') + colored.red('No'))
        
    if keep_time == '1':
        puts(colored.green('Time Data Collection: ') + colored.red('Yes'))
        puts(colored.green('Time Limit: ') + colored.red(time_limit))
        
    elif keep_time == '0':
        puts(colored.green('Time Data Collection: ') + colored.red('No'))
        puts(colored.green('File Size Limit: ') + colored.red(file_size))
           
    
    
    
    
        
def get_commands():
    exit_config = False
    
    while exit_config == False:
        puts(colored.green('Enter Command: '))
        command = input()
        
        if command == 'exit':
            puts(colored.magenta('----------Leaving Settings Menu----------'))
            break
        
        else:
            parse_command(command)
    
def start_process():  
    puts(colored.magenta('-------Settings Configuration Menu-------')) 
    parse_file()
    get_commands()
    update_file()   
     

            
        
                        


                    
                    
            
            