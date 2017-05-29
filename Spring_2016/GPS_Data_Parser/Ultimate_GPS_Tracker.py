#!/usr/bin/python3
'''
Created on Mar 23, 2016
:)

@author: deepg
'''
import DataManager
import Parser
import settings_config
from clint.textui import puts, colored

#Introduction

puts(colored.green('-----------------------------WELCOME-----------------------------'))
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
        file = input(colored.cyan('Enter Name of File: '))
        Parser.parse_file(file)
        
    elif command == 'config settings' or command == 'config auto start' or command == 'open settings':
        settings_config.start_process()
        
    
    else:        
        puts(
        colored.red(command) + 
        colored.cyan(' is not a valid command, please enter a command from the list below:')
        )
        
        puts(
            colored.green('Valid Commands:') + 
            colored.green('\n1. \"get help\" or \"help\" or \"get information\"') + 
            colored.cyan('\n      opens the help menu and provides information on the app') +
            colored.green('\n2. \"start new process\" or \"startApp\"') + 
            colored.cyan('\n      displays incoming data from the gps and allows the user to record incoming data') +
            colored.green('\n3. \"config settings\" or \"open settings\" or \"config auto start\"') +
            colored.cyan('\n      allows the user to change whether or not data is recorded automatically when the pi boots up') + 
            colored.green('\n4. \"exit\"') + 
            colored.cyan('\n      exits out of the Ultimate GPS Tracker')  
            )      
    

def start_Process():      
    user_reply = input(colored.yellow('Save data to file? (y/n): '))
           
    if (user_reply == 'yes') or (user_reply == 'y'):
        keep_time = input(colored.yellow('Set Time Limit for Data Collection?(y/n): '))
        
        if keep_time == 'yes' or keep_time == 'Yes' or keep_time == 'y':
            DataManager.write_tofile( 0, True, True)            
                    
        else:
            size = input(colored.yellow('File Size(number of lines): '))
            DataManager.write_tofile(int(size), False, True)
                
    elif user_reply == 'n' or user_reply == 'no':
        keep_time = input(colored.yellow('Set Time Limit for Data Collection?(y/n): '))
        
        if keep_time == 'yes' or keep_time == 'Yes' or keep_time == 'y':
            DataManager.write_tofile( 0, True, False)            
                    
        else:
            size = input(colored.yellow('File Size(number of lines): '))
            DataManager.write_tofile(int(size), False, False)
                         
                
    else:
        puts(colored.red('---Invalid Input---'))
    
    
def get_help():
    '''
    Open Help Menu
    '''
    
    #Print Designer Credits
    puts(colored.magenta('---------------------------Help Menu---------------------------'))
        
    puts(colored.green('The Wells Global Positioning System was designed April 1, 2016 by Garrett Wells as an AP Comp Sci project'))
    
    puts(
        colored.green('Valid Commands:') + 
        colored.green('\n') +
        colored.green('\n1. \"get help\" or \"help\" or \"get information\"') + 
        colored.cyan('\n      opens the help menu and provides information on the app') +
        colored.green('\n2. \"start new process\" or \"startApp\"') + 
        colored.cyan('\n      displays incoming data from the gps and allows the user to record incoming data') +
        colored.green('\n3. \"config settings\" or \"open settings\" or \"config auto start\"') +
        colored.cyan('\n      allows the user to change whether or not data is recorded automatically when the pi boots up') +
        colored.green('\n4. \"exit\"') + 
        colored.cyan('\n      exits out of the Ultimate GPS Tracker')            
        ) 
    
    puts(
        colored.yellow('\nstartApp Functionality:') +
        colored.yellow('\n') +
        colored.yellow('\nstartApp activates the data collection process directly from the main menu. The user can choose to save the collected data, storage location of the ')+
        colored.yellow('\ndata and whether or not the data should be limited by time or number of NMEA sentences.')
        )
    
    puts(
        colored.magenta('\n\nSettings Menu Details:') +
        colored.magenta('\n') +
        colored.magenta('\nThe settings menu can be used to setup the automatic startup process for the WGPS. The user can turn it on or off and can also')+
        colored.magenta('\nchange how much data is collected as well as how the data is recorded.') +
        colored.magenta('\n')
        )
         
    
                    
'''
Loops through the commands entered by the user
'''

def task_manager():
    puts(colored.red('Enter Command to Continue: '))
    
    reply = input().strip()
    
    while reply != 'exit':
        
        command_Processer(reply)
        
        puts(colored.red('Enter Command to Continue: '))               
        reply = input().rstrip()
        
task_manager()
        
        