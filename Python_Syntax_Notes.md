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

		to retrieve the current date and time => datetime.now() ##can be assigned as a variable
		to retrieve the current year => datetime.year
		month => datetime.month
		day => datetime.day
		hour => datetime.hour
		minute => datetime.minute
		second => datetime.second

##Known Libraries That Can Be Imported:
	
	IMAPclient
	datetime