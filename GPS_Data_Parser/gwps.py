from clint.textui import puts, colored

#Imports from Monty!
import subprocess



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
    
    print('Current Time: ' + str(hours) + ' hrs, ' + minutes + ' min, ' + seconds + ' sec, ' + milliseconds  + ' millisec ')
    print(str(hours) + ':' + minutes + ':' + seconds + ':' + milliseconds + ' ' + half_ofDay)
    
def parse_RMC(sentence):
    '''
    Parse the sentence and find the important chucks of data
    '''
    gp_status = sentence[20]
        
    if gp_status == 'A':
        puts(colored.cyan('Status:') + colored.green(' Active'))
        
        #Time
        gmt = sentence[9 : 19] 
        parse_time(gmt)
        
        #Date MM:DD:YYYY
        day = sentence[59 : 61]
        month = sentence[61 : 63]
        year = sentence[63 : 65]
        puts(colored.yellow('Date: ' + month + ', ' + day + ', 20' + year))
        
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
            
        
    
    
def parse_file(file):
    '''
    
    Parse through the data and call different methods depending on first six characters of the NMEA sentence.
    Most Important Sentence: $GPRMC (Global Position Recommended Minimum)
    
    
    
    f = open('GPS_Data.txt', 'r')
    
    n = open('GPS_Log.txt', 'w')
    
    for line in f:
        identify_sentence(line)
    '''
        
'''
b'$GPRMC,194509.000,A,4042.6142,N,07400.4168,W,2.03,221.11,160412,,,A*77 
'''
def identify_sentence(sentence):
    if sentence[0 : 8] == "b\'$GPRMC":
        parse_RMC(sentence)
    
    else:
        print('Not of Interest')
  



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
                identify_sentence("%s" %line)
                line_count += 1
                print('Count is now: ' + str(line_count))
            else:
                print('---Limit Reached---')
                print('---Ending Process---')
                break
    
    
    print('---Process Ended---')







#Introduction

puts(colored.green('-----------------------WELCOME-----------------------'))
puts(colored.green('------------------STARTING GPS Tracker 1.0 2016------------------'))
puts(colored.green('For information on how to run the Ultimate GPS Data Tracker enter "get information". \nTo view data from the GPS enter "startApp".'))


'''
Processes a string and sees if it is a valid command, if successful recognized as a command the command is run
'''
def command_Processer(command):
    
    if command == 'get information':
        get_help()
        
    elif command == 'configure settings':
        configure_application()
        
    elif (command == 'start new process') or (command == 'startApp'):
        start_Process()
    
    else:
        puts(colored.red(command) + colored.cyan(' is not a valid command, please enter a command from the list below:'))
        puts(colored.red('Commands:') + colored.green('\n\"get help\" -- opens the help menu') + colored.green('\n\"configure settings\" -- opens the settings menu') + 
            colored.green('\n\"start new process\" -- starts a new process'))       
    
'''
Start App
'''
def start_Process():
      
    user_reply = input(colored.red('Would you like to save the data from the GPS for a latter date?'))
           
    if user_reply == 'yes':
            
        size = input(colored.red('File Size(number of lines): '))
        write_tofile(int(size), True)
                
    elif user_reply == 'no':
         
        write_tofile(200)
        
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
        print('"help" :   Opens the Help Menu')
        
                
                    
'''
Loops through the commands entered by the user
'''

def task_manager():
    
    reply = input(colored.red('Enter Command to Continue: '))
    
    while reply != 'exit':
        
        command_Processer(reply)
                        
        reply = input(colored.red('Enter Command to Continue: '))
        
        
task_manager()
        
        