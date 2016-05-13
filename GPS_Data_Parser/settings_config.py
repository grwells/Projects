'''
Created on May 9, 2016

@author: deepg
'''
from clint.textui import colored, puts

global times_used
global file_size
global keep_time
global time_limit
global exit_config 


f = open('settings', 'r+')

def update_file():
    
    count = 0
    
    for line in f:
            
        if count == 0:
            f.write(times_used)      
        
        elif count == 1:
            f.write(file_size)
            
        elif count == 2:
            f.write(keep_time)
            
        elif count == 3:
            f.write(time_limit) 
            
        count += 1
            
        

def config_time():
    response = input(puts(colored.green('Time data collection?(y/n) ')))
    
    if response == 'y':
        keep_time = '1'        
        time_limit = input(puts(colored.green('Enter time limit in hours or a fraction of an hour: ')))
        
    elif response == 'n':
        keep_time = '0'    
        
    
    update_file()    
  
def config_timesused():
    response = input(colored.green('Reset times used to zero?(y/n): '))
    if response == 'y':
        times_used = '0'
        
    update_file()
       
def config_size():
    response = input(colored.green('Enter number of lines of data to be collected: '))
    file_size = response
    
    update_file()    

def parse_command(command):
    if command == 'config time limits':        
        config_time()
        
    elif command == 'config file size':        
        config_size()
    
    elif command == 'config times used':
        config_timesused()
        
    elif command == 'exit':
        exit_config = True
        
    else: 
        puts(colored.red(command) + colored.cyan(' is not a valid command, please enter a command from the list below') +
             colored.red('\nCommands:') + 
             colored.green('\n\"config time limits\"') + 
             colored.green('\n\"config file size\"') +
             colored.green('\n\"config times used\"') +
             colored.green('\n\"exit\"'))          
             

def parse_file():
    count = 0    
      
    for line in f:
            
        if count == 0:
            times_used = line      
        
        elif count == 1:
            file_size = line
            
        elif count == 2:
            keep_time = line
            
        elif count == 3:
            time_limit = line 
            
        count += 1
        
def print_currentSettings():
    parse_file()
    
    puts(colored.green('------Current Settings Configuration------'))
    limit_exists = ''
    
    if keep_time == '0':
        limit_exists = 'No'
        
    else:
        limit_exists = 'Yes'
    
    puts(colored.green('Time Data Collection: ') + colored.red(limit_exists))
    
    puts(colored.green('Number of Lines To Be Collected: ') + colored.red(file_size))
    
    puts(colored.green('Current Time Limit To Be Used: ') +  colored.red(time_limit))
        
def get_commands():
    exit_config = False
    
    while exit_config == False:
        puts(colored.green('Enter Command: '))
        command = input()
        
        if command == 'exit':
            puts(colored.red('----------Leaving Settings Menu----------'))
            break
        
        else:
            parse_command(command)
    
def start_process():  
    puts(colored.green('-------Settings Configuration Menu-------'))   
    parse_file()
    get_commands()
    update_file()    

            
        
                        


                    
                    
            
            