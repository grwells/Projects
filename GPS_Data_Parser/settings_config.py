'''
Created on May 9, 2016

@author: deepg
'''
from clint.textui import colored, puts

times_used = '0'
file_size = '0'
keep_time = '0'
time_limit = '0'

def parse_file():
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
            print(str(count))
            times_used = line 
            puts(colored.green('Times Used: ') + colored.red(line))     
        
        elif count == 1:
            print(str(count))
            file_size = line
            puts(colored.green('File Size Limit: ') +  colored.red(line))
            
        elif count == 2:
            print(str(count))
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
            print(str(count))
            time_limit = line 
            puts(colored.green('Time Limit(hrs): ') + colored.red(line))
            
        count += 1
    
    file_isClosed = False
    while file_isClosed == False:
        f.close()
        file_isClosed = f.closed

def update_file():
    global times_used
    global file_size
    global keep_time
    global time_limit
    
    f = open('settings', 'w')  
    
    f.write(str(times_used))
    f.write('\n' + str(file_size))
    f.write('\n' + str(keep_time))
    f.write('\n' + str(time_limit))
    
    file_isClosed = False
    while file_isClosed == False:
        f.close()
        file_isClosed = f.closed
            
          

def config_time():
    global keep_time
    global time_limit
    
    puts(colored.green('Time data collection?(y/n): '))
    response = input()
        
    if response == 'y':
        keep_time = '1'
        puts(colored.green('Enter time limit in hours or a fraction of an hour: '))        
        time_limit = input()
        
    elif response == 'n':
        keep_time = '0'   
        
    else:
        puts(colored.red('---ERROR---')) 
        puts(colored.red(response))
        
    
    update_file()    
  
def config_timesused():
    global times_used
    response = input(colored.green('Reset times used to zero?(y/n): '))
    if response == 'y':
        times_used = '0'
        
    update_file()
       
def config_size():
    global file_size
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
        
    elif command == 'print settings':
        print_currentSettings()
        
    else: 
        puts(colored.red(command) + colored.cyan(' is not a valid command, please enter a command from the list below') +
             colored.red('\nCommands:') + 
             colored.green('\n\"config time limits\"') + 
             colored.green('\n\"config file size\"') +
             colored.green('\n\"config times used\"') +
             colored.green('\n\"print settings"') +
             colored.green('\n\"exit\"'))          
             


        
def print_currentSettings():
    print(times_used)
    print(file_size)
    print(keep_time)
    print(time_limit)
        
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
     

            
        
                        


                    
                    
            
            