

import subprocess
import datetime
from settings_config import parse_file
from clint.textui import colored, puts
'''
    global record_data
    global times_used
    global file_size
    global keep_time
    global time_limit
'''
record_data = '0'
times_used = '0'
keep_time = '0'
file_size = '0'
time_limit = '0'
hours_elapsed = '0'
last_timeStamp = '0'

'''
Increments hours_elapsed and returns hours_elapsed
'''

def get_timeDelta(current_time, last_time):
    global last_timeStamp
    current_minute = int(current_time[14:16])
    start_minute = int(last_time[14:16])
    
    portion_ofhour = 0
    
    if current_minute >= start_minute:
        portion_ofhour = current_minute - start_minute
        
    else:
        portion_ofhour = (60 - start_minute) + current_minute
        
    portion_ofhour = portion_ofhour/60
    hours_elapsed += portion_ofhour
    last_timeStamp = current_time
    
    return hours_elapsed
    

def get_Data():
    global record_data
    
    if record_data == '1': 
    
        line_count = 0
        
        subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
           
        result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
           
               
        #Specify the file to write to        
        file_toWrite = 'GPS_DataStartup.txt'
          
            
        f = open(file_toWrite, 'r+')
                                
        if keep_time == False:
        
            for line in result.stdout:
                if line_count < file_size:
                    
                    line = "%s" %line
                    
                    if line[0 : 8] == "b\'$GPRMC":
                        
                        f.write("%s\n" %line)
                        line_count += 1
                               
                else:
                        
                    f.close()
                    break
                
        elif keep_time == True:
            f = open(file_toWrite, 'w')
            
            start_time = str(datetime.datetime.now())
            last_timeStamp = start_time
            
            for line in result.stdout:                                        
                if get_timeDelta(str(datetime.datetime.now()), last_timeStamp) <= time_limit:                           
                    line = "%s" %line
                        
                    if line[0 : 8] == "b\'$GPRMC":                        
                        f.write("%s\n" %line)
                        line_count += 1
                                   
                else:                        
                    f.close()
                    break
    elif record_data == '0':
        print('GPS Data Collection on Startup Deactivated')
            
            
def get_settings():
    
    global record_data
    global times_used
    global keep_time
    global numberof_lines
    global time_limit
    
    f = open('settings', 'r')
    
    count = 0
    
    numberof_lines = 100
    
    times_used = 0
    
    keep_time = False
    
    time_limit = 0
    
    for line in f:
        line = line.rstrip('\n')
        line = line.strip()
        
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
            
        elif count == 4:
            record_data = line
            
    
    #parse_file()       
    get_Data()
    
get_settings()
            

            
        
        
        
         
                        