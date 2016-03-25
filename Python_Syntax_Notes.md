##Python Notes:
	
	No declaration types before variables required.

	#Strings ->
		
		length of string my_string => len(my_string)
		convert string to upper case => .upper
		convert to lower => .lower
		convert non-string to string => str(variable_name)
		to fill in variables in strings => "Bunch of %s meaningless words" % ("stupid") = "Bunch of stupid meaningless words"
		mark index to be replaced by variable => %s
		replace (%s)'s with variables => "string with a %s and another %s" % (variable1, variable2) = "string with a variable1 and another variable2"

	#Integers ->
	
		multiply numbers => *
		this_number to the (x) power => this_number ** x

	#Date Time Library Commands ->

		to retrieve the current date and time => datetime.now() #can be assigned as a variable
		to retrieve the current year => datetime.year
		month => datetime.month
		day => datetime.day
		hour => datetime.hour
		minute => datetime.minute
		second => datetime.second
		to retrieve old date as well as set the new date => date

##Importing Modules:
	
	How to Import Modules:
		>>>import module_name
		or, to import a specific submodule from a module
		>>>from module_name import submodule_name

	Known Modules that Are Helpful:

	IMAPclient
	datetime # Provides date and time functions
	time # Provides timers and sleep() functions
	math # Higher math functions
	tkinter (Python 3 only) # Basic GUI's and graphical methods
	os # System commands a spawning new processes
	subprocess # System commands and spawning new child processes

##Running Command Line Arguments from Python
	Python has had multiple ways of running commands via the command line. One relied upon the "os" module while the other uses the "subprocess" module. The "os" module was used in Python2 and "subprocess" came along in Python3 to replace "os".

	subprocess Method:
	>>>import subprocess
	>>>subprocess.Popen(args, bufsize=-1, executable=None, stdin=None, stdout=None, stderr=None, preexec_fn=None, close_fds=True, shell=False, cwd=None, env=None, universal_newlines=False, startupinfo=None, creationflags=0, restore_signals=True, start_new_session=False, pass_fds=())

	os Method:
	>>>import os
	>>>os.system("command_here")

##Running Python Scripts Directly From the Command Line in Linux
	Scripts are files of Python statements that can be run together.
	If you simply write a script in a text editor and then want to run it from the command line you can do so by entering the following line of code:

			pi@raspberrypi ~$ python3 directory_name/program_name

	It is possible to write a file and run it from the command line as Python script without entering ">>>python3 file_name". To do so, add this line of code at the beginning of the script:

			#!usr/bin/python3 # The "#!" at the beginning of the sentence is called a "shebang".

	You will also need to make the file executable by running the following arguments on the command line:

			pi@raspberrypi ~$ chmod u+x file_name

	Now, all you need to do to run the file as a python script from the command line is run the following command:

			pi@raspberrypi ~$ ./file_name

	Whoohoo!!!
	

##Tkinter
	A form of interface that is commonly used among many programming languages including Python. Simplistic and easy to use, does not have outstanding visual affects. The library "tkinter" must be imported every time in order to be used.


##Basic Functions
Functions:
	def function_name(function_parameters):
		return function_parameters

If, elif, and else Statements:
	if boolean_statement == True:
		return True

	elif !boolean_statement == False:
		return True

	else:
		return False

Finding What Type of Object is Stored in a Variable Name:
	type(variable_name) # Will return -> string, int, or float depending on what is held in the variable name.

Lists of Items:
	Create a New List:
		list_name = [item_one, item_two, etc]

	Add an element to the List:
		list_name.append(element_name) # Adds the new element to the end of the list.


	Create a new list that contains the specific elements of another list:
		new_list_name = old_list_name[first_element_index: last_element_index_plus_one] 
		'''
		retrieves the elements between the first and last element index. If first_element_index's place is left empty then the index starts at 0
		'''

	Insert an Item into a List at a Certain Point:
		list_name.insert(index, item) # Old element that was there is shifted down.

	Find the Index of an Item In the List:
		list_name.index(item_name) # Finds the index of an element in a list.

For Loops:
	for int_name in list_name:
		# Goes through each element in list and performs whatever operations are in the body of the for loop.

