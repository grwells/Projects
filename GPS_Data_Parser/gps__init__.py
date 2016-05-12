'''
Created on May 9, 2016

@author: deepg
'''
import subprocess
import time

global times_used
global keep_time
global numberof_lines
global time_limit

def get_Data():
    
    line_count = 0
    
    subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
       
    result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
       
           
    #Specify the file to write to        
    file_toWrite = 'GPS_Data.txt'
      
        
    f = open(file_toWrite, 'w')
                            
    if keep_time == False:
    
        for line in result.stdout:
            if line_count < numberof_lines:
                
                line = "%s" %line
                
                if line[0 : 8] == "b\'$GPRMC":
                    
                    f.write("%s\n" %line)
                    line_count += 1
                           
            else:
                    
                f.close()
                break
            
    elif keep_time == True:
        
        '''
        Use timer to manage time
        '''
        
def get_settings():
    
    f = open('settings', 'r')
    
    count = 0
    
    numberof_lines = 100
    
    times_used = 0
    
    keep_time = False
    
    time_limit = 0
    
    for line in f:
        
        if count == 0:
            
            times_used = int(line)
            
            if times_used < 1:
                
                print('Please configure the settings file to make sure that you are running the correct configuration.')
        
        elif count == 1:
                        
            numberof_lines = int(line)
            
        elif count == 2:
            
            keep_time = str(line)
            
            if keep_time == '1':
                
                keep_time = True
                            
        elif count == 3:
            
            time_limit = int(line)
            
            
    get_Data()
            

            
        
        
        
         
                        