'''
Created on Mar 23, 2016

@author: deepg
'''

#Imports from Monty!
import subprocess

def write_tofile(fill_limit):
    print('---Process Starting---')
    line_count = 0
    subprocess.getoutput('stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb')
    print('-Baud rate set-')
    f = open('GPS_Data.txt', 'w')
    print('-File open-')
    result = subprocess.Popen('cat /dev/ttyAMA0', shell=True, stdout=subprocess.PIPE)
    print('---PIPE IS OPEN---')
    
    for line in result.stdout:
<<<<<<< HEAD
        if line_count < fill_limit:
            f.write("%s\n" %line)
            print("%s" %line)
            line_count += 1
            print('Count is now: ' + line_count)
=======
        if count < int(fill_limit):
            f.write("%s\n" %line)
            print("%s" %line)
            count += 1
            print('Count is now: ' + str(count))
>>>>>>> a773bb31bd33447187751c977db72d24f88724d9
        else:
            print('---Limit Reached---')
            print('---Ending Process---')
            break
    
    print('---Process Ended---')



<<<<<<< HEAD
=======

>>>>>>> a773bb31bd33447187751c977db72d24f88724d9
