'''
Created on Mar 23, 2016

@author: deepg
'''

import DataManager
import Parser

#Introduction
print('-----------------------WELCOME-----------------------')
print('------------------STARTING APPLICATION------------------')
<<<<<<< HEAD
print('For information on how to run the Ultimate GPS Data Tracker enter "help". To view data from the GPS enter "startApp".')
=======
print(w'For information on how to run the Ultimate GPS Data Tracker \nenter "help". To view data from the GPS enter "startApp".')
>>>>>>> a773bb31bd33447187751c977db72d24f88724d9

'''
Start App
'''
<<<<<<< HEAD
def start_Process():
    
    DataManager.write_tofile(100)
    Parser.parse_file('GPS_Data.txt')


def get_help():
    '''
    Open Help Menu
    '''
    
=======
if input() == 'startApp':
    print('Enter Line Limit For File: ')
    limit = input()
    DataManager.write_tofile(limit)
    print('Would you like to parse the data now?')
    answer = input()
    if answer == 'yes':
        Parser.parse_file('GPS_Data.txt')
        print('-----------------------PARSING DATA-----------------------')
        
'''
Open Help Menu
'''

if (input() == 'help'):


>>>>>>> a773bb31bd33447187751c977db72d24f88724d9
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
<<<<<<< HEAD
                
        print('')
                
        print('"stopApp" :     Stops the app')
        print('"help" :   Opens the Help Menu')
        print('"getSpeed"  :   Returns the instantaneous speed of the GPS in knots')
                
        print('To Exit The Help Menu Enter "exit"') 
            
            
while input() != 'exit':
    
    if input() == 'help':
        
        get_help()       
        
    elif input() == 'startApp':
        
        start_Process()
=======
                    
        print('')
                    
        print('"stopApp" :     Stops the app')
        print('"help" :   Opens the Help Menu')
        print('"getSpeed"  :   Returns the instantaneous speed of the GPS in knots')
                    
        print('To Exit The Help Menu Enter "exit"')
                    
        
>>>>>>> a773bb31bd33447187751c977db72d24f88724d9
