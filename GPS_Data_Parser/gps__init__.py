#!/usr/bin/python3

import subprocess
import datetime
'''
Variable names used in settings_config
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
hours_elapsed = 0.0
last_timeStamp = '0'


'''
Increments hours_elapsed based on the time elapsed between current_time and last_time which are string versions of the times from the datetime lib
'''
def get_timeDelta(current_time, last_time):
    global hours_elapsed
    global last_timeStamp
    current_minute = int(current_time[14:16])
    start_minute = int(last_time[14:16])
    
    portion_ofhour = 0.0
    
    if current_minute >= start_minute:
        portion_ofhour = current_minute - start_minute
        
    else:
        portion_ofhour = (60 - start_minute) + current_minute
        
    portion_ofhour = portion_ofhour/60
    hours_elapsed += float(portion_ofhour)
    last_timeStamp = current_time
    
        
'''
Record the data that is being collected by the Raspberry Pi
    
    Uses the user settings in the settings file to configure the process 
    Calls get_timeDelta(currentTime, lastTime)
'''
def get_Data():
    global record_data
    global times_used
    global file_size
    global keep_time
    global time_limit
    global hours_elapsed
    global last_timeStamp
    
    if record_data == '1': 
        #print('Starting process')
    
        line_count = 0
        
        subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
           
        result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
           
               
        #Specify the file to write to        
        file_toWrite = 'GPS_DataStartup.txt'
          
            
        f = open(file_toWrite, 'a')
        #print('file open')
        
        #print('Keep Time: ' + keep_time)
                                
        if keep_time == '0':
        
            for line in result.stdout:
                #print('Line Count: ' + str(line_count))
                #print('File Size: ' + str(file_size))
                if line_count < int(file_size):
                    
                    line = "%s" %line
                    
                    if line[0 : 8] == "b\'$GPRMC":
                        
                        f.write("%s\n" %line)
                        line_count += 1
                        #print(str(line_count))
                               
                else:
                    #print('Closing File')                        
                    f.close()
                    #print('File Closed')
                    #break
                
        elif keep_time == '1':
            #print('Getting Start Time')  
            #         
            start_time = str(datetime.datetime.now())
            #
            #print('Start Time: ' + start_time)
            #
            last_timeStamp = start_time
            
            for line in result.stdout: 
                #print('Timing Operation') 
                get_timeDelta(str(datetime.datetime.now()), last_timeStamp)                                      
                if hours_elapsed <= time_limit: 
                    #print('Hours Elapsed Since Start: ' + str(hours_elapsed))                          
                    line = "%s" %line
                        
                    if line[0 : 8] == "b\'$GPRMC":                        
                        f.write("%s\n" %line)
                        line_count += 1
                        #print(str(line_count))
                                   
                else: 
                    #print('Closing File')                       
                    f.close()
                    #print('File Closed')
                    #end_time = str(datetime.datetime.now())
                    #print('End Time: ' + end_time)
                    break
                
    elif record_data == '0':
        #print('GPS Data Collection on Startup Deactivated')
        #print(record_data)
        f.close()
        
    else:
        f.close()
        #print("---ERROR---")
            
'''
Updates the global variables for get_Data() from the settings inputed by the user

    Calls get_Data() once done getting settings
'''            
def get_settings():    
    global record_data
    global times_used
    global keep_time
    global file_size
    global time_limit
    
    f = open('settings', 'r')
    
    count = 0
    
      
    for line in f:
        line = line.rstrip('\n')
        line = line.strip()
        
        if count == 0:            
            times_used = int(line)
                        
            #if times_used < 1:                
                #print('Please configure the settings file to make sure that you are running the correct configuration.')
        
        elif count == 1:                        
            file_size = int(line)
            
        elif count == 2:            
            keep_time = str(line)
                                                    
        elif count == 3:            
            time_limit = float(line)
            
        elif count == 4:
            record_data = line
            #print('Record Data = ' + line)
            
        count += 1
            
    
      
    get_Data()
    
get_settings()
            

            
        
        
        
         
                        