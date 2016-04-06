'''
Created on Mar 23, 2016

@author: deepg
'''
import DataManager
import Parser

#Introduction
print('-----------------------WELCOME-----------------------')
print('------------------STARTING APPLICATION------------------')
print('For information on how to run the Ultimate GPS Data Tracker \nenter "help". To view data from the GPS enter "startApp".')

'''
Start App
'''
if input() == 'startApp':
    
    DataManager.write_tofile(100)
    Parser.parse_file('GPS_Data.txt')
    
    
'''
Open Help Menu
'''

elif input() == 'help':
    
    
    #Print Designer Credits
    print('-----------------------Help Menu-----------------------')
    
    print('The Ultimate GPS Tracker was designed April 1, 2016 by Garrett Wells with contributions from the following sponsors:')
    print('Garrett Wells')
    print('G Wells')
    print('And last but not least: Yours Truly')
    print('')
    print('For serious information and technical details enter "SHUT UP!!" on the line below.')
    
    #Print Command Options
    if input() == 'SHUT UP!!':
        
        print('Okay! Sheesh, no need to get mad. Here is a list of basic \ncommands accepted by the Ultimate GPS Tracker as well as '
        + 'descriptions of their impact on the functionality of the Ultimate GPS Tracker.')
            
        print('')
            
        print('"stopApp" :     Stops the app')
        print('"help" :   Opens the Help Menu')
        print('"getSpeed"  :   Returns the instantaneous speed of the GPS in knots')
            
        print('To Exit The Help Menu Enter "exit"')
            
        while input() != 'exit':
    
    #Print "Sleeping"         
    else:
        print('Sleeping')
        
'''
Handle Unrecognized Command
'''                            
else:
    print('---Unknown Command, Please Enter A New Command On The Line Below---')
    
        command = input()
    
        #Start the App
    if command == 'startApp':
        
        DataManager.write_tofile(100)
        Parser.parse_file('GPS_Data.txt')
        
        
    elif command == 'help':
        
        print('-----------------------Help Menu-----------------------')
        
        print('The Ultimate GPS Tracker was designed April 1, 2016 by Garrett Wells with contributions from the following sponsors:')
        print('Garrett Wells')
        print('G Wells')
        print('And last but not least: Yours Truly')
        print('')
        print('For serious information and technical details enter "SHUT UP!!" on the line below.')
    
        if input() == 'SHUT UP!!':
        
            print('Okay! Sheesh, no need to get mad. Here is a list of basic \ncommands accepted by the Ultimate GPS Tracker as well as '
                      + 'descriptions of their impact on the functionality of the Ultimate GPS Tracker.')
        
            print('')
        
            print('"stopApp" :     Stops the app')
            print('"help" :   Opens the Help Menu')
            print('"getSpeed"  :   Returns the instantaneous speed of the GPS in knots')
        
            print('To Exit The Help Menu Enter "exit"')
        
            while input() != 'exit':
    
        else:
                
            print('Goodbye!')   
                                         
        
    else:
            print('Goodbye')
            
            
            
            