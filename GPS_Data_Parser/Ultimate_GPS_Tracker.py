'''
Created on Mar 23, 2016
:)

@author: deepg
'''
import DataManager
import Parser
from clint.textui import puts, colored

#Introduction

puts(colored.green('-----------------------WELCOME-----------------------'))
puts(colored.green('------------------STARTING GPS Tracker 1.0 2016------------------'))
puts(colored.green('For information on how to run the Ultimate GPS Data Tracker enter "get information". \nTo view data from the GPS enter "startApp".'))


'''
Processes a string and sees if it is a valid command, if successful recognized as a command the command is run
'''
def command_Processer(command):
    
    if command == 'get information' or command == 'get help' or command == 'help':
        get_help()
        
            
    elif (command == 'start new process') or (command == 'startApp'):
        start_Process()
        
    elif command == 'parse file':
        file = input(colored.red('Enter Name of File: '))
        Parser.parse_file(file)
    
    else:
        puts(colored.red(command) + colored.cyan(' is not a valid command, please enter a command from the list below:'))
        puts(colored.red('Commands:') + colored.green('\n\"get help\" -- opens the help menu') +  
            colored.green('\n\"start new process\" -- starts a new process'))       
    
'''
Start App
'''
def start_Process():
      
    user_reply = input(colored.red('Save data to file? (y/n): '))
           
    if (user_reply == 'yes') or (user_reply == 'y'):
            
        size = input(colored.red('File Size(number of lines): '))
        DataManager.write_tofile(int(size), True)
                
    elif user_reply == 'n' or user_reply == 'no':
         
        DataManager.write_tofile(200)
        
    else:
        puts(colored.green('---Invalid Input---'))
    
def configure_application():
    
    print('Not done yet, get on it Garrett')
    
def get_help():
    '''
    Open Help Menu
    '''
    
    #Print Designer Credits
    puts(colored.green('-----------------------Help Menu-----------------------'))
        
    print('The Ultimate GPS Tracker was designed April 1, 2016 by Garrett Wells')
    print('For serious information and technical details enter "exit" on the line below.')
        
    #Print Command Options
    if input() == 'exit':
            
        print('Okay! Sheesh, no need to get mad. Here is a list of basic \ncommands accepted by the Ultimate GPS Tracker as well as '
        + 'descriptions of their impact on the functionality of the Ultimate GPS Tracker.')
                
        print('')
                
        print('"exit" :     Stops the Application')
        print('"get information" :   Opens the Help Menu')
        
                
                    
'''
Loops through the commands entered by the user
'''

def task_manager():
    
    reply = input(colored.red('Enter Command to Continue: '))
    
    while reply != 'exit':
        
        command_Processer(reply)
                        
        reply = input(colored.red('Enter Command to Continue: '))
        
        
task_manager()
        
        