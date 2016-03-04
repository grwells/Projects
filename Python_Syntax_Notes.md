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
	
	#How to Import Libraries
		import module_name
		or
		from module_name import submodule_name
	
	IMAPclient
	datetime
	math

##Basic Functions
	def function_name(function_parameters):
		return function_parameters

		if boolean_statement == true:
			return true

		else:
			return false:
	type(variable_name) will return -> string, int, or float

	Create a List of Items:
		list_name = [item_one, item_two, etc]

	Add an element to a list:
		list_name.append(element_name)


	Create a list that contains the specific elements of another list:
		new_list_name = old_list_name[first_element_index: last_element_index_plus_one] ## retrieves the elements between the first and last element index. If first_element_index's place is left empty then the index starts at 0

	Insert an Item into a List at a Certain Point:
		list_name.insert(index, item)

	Find the Index of an Item:
		list_name.index(item)

	For Loops:
		for int_name in list_name:
			##do stuff

