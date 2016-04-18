Commands For Linux

To run a program as an administrator either right click on the program and select "run as administrator" from the list of options or, 
open the program using the search bar and open by pressing ctrl + shift + enter
 
Change Password For the Pi:
	passwd

File and Folder Commands:

	Create a Folder => mkdir <folderName>
	
	Create or Edit a File => nano <fileName.extensionName>
		Save a File -> ctrl O
		Exit a File -> ctrl X
		Look at a File -> cat <fileName.extensionName>
			You must be in the directory containing the file to look at the file.

	Delete a File or Folder => 
		Folders -> rmdir <folderName>

Directory Navigation Commands:
	
	List Pathway => pwd

	List Folders and Files in Current Directory => ls

	Change Directory => cd <directorynName>
		requires that you are already in the directory that contains your desired destination. Else, you will need to copy down the complete pathway starting at the home directory and going all the way to the destination directory.

	Go Up One Directory => cd .. or cd /

	Go To the Root Directory cd ~

	Garrett's Pi

	VNC Server login password : Garrett1 "HelloG"
	to run type this in SSH terminal: vncserver :1
	Pi login username: pi
		password: raspberry

		vkwells5511
		43dda7daf7e9fa
		ip: 192.168.0.38

		102
		A0F0154D36001AFDB6BBAAD008
		ip: 10.58.42.158 (will probably change next time)

To Connect to WiFi 
	sudo nano /etc/network/interfaces
		change ssid and psk
	sudo dhclient wlan0

GPS Setup:

	1. Disabble the Serial Boot Up
		sudo nano /boot/cmdline.txt
		then remove console=ttyAMAO,115200 and if there kgdboc=ttyAMA0,115200

	2. Run 
		stty -F /dev/ttyAMA0 raw 9600 cs8 clocal -cstopb
		and then
		cat /dev/ttyAMA0

VNC Server Setup and Settings:
	Installation Process:
		1- sudo apt-get install tightvncserver
		2- vncserver :1 //starts server and on first start will activate settings for the passwd
		3- say no to read only password

	Resetting Password:
		1- vncpasswd
		2- type the new pass word


How to Clone a GitHub Repository Into a local Repository:


	When you create a repository on GitHub, it exists as a remote repository. You can create a local clone of your repository on your computer and sync between the two locations.

	This procedure assumes you have already created a repository on GitHub, or have an existing repository owned by someone else you'd like to contribute to.

	1-On GitHub, navigate to the main page of the repository.

	2-Clone URL buttonUnder your repository name, click  to copy the clone URL for the repository.

	3-Open Terminal.

	4-Change the current working directory to the location where you want the cloned directory to be made.

	5-Type git clone, and then paste the URL you copied in Step 2.

		git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
	
	6-Press Enter. Your local clone will be created.

	git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
	Cloning into `Spoon-Knife`...
	remote: Counting objects: 10, done.
	remote: Compressing objects: 100% (8/8), done.
	remove: Total 10 (delta 1), reused 10 (delta 1)
	Unpacking objects: 100% (10/10), done.
