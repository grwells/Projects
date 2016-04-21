'''
Created on Mar 23, 2016

@author: deepg
'''

#Imports from Monty!
import subprocess
import Parser
from clint.textui import puts, colored

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
                    Parser.identify_sentence("%s" %line)
                    f.write("%s\n" %line)
                    #print("%s" %line)
                    line_count += 1
                    #print('Count is now: ' + str(line_count))
                else:
                    puts(colored.green('---Limit Reached---'))
                    puts(colored.green('---Ending Process---'))
                    f.close()
                    break
        
         
                        
    
        
    else:
       
        for line in result.stdout:
            if line_count < fill_limit:
                Parser.identify_sentence("%s" %line)
                line_count += 1
                
            else:
                puts(colored.green('---Limit Reached---'))
                puts(colored.green('---Ending Process---'))
                break
    
    
    puts(colored.green('---Process Ended---'))



