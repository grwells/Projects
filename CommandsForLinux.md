# Commands For Linux

## Pi Commands:
	--------------------------
	| Change Password | passwd
	--------------------------

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
			* change ssid and psk
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


## File and Folder Commands:

### File Operations
--------------------------------------
| Create a Folder | mkdir <folderName>
--------------------------------------
| Create or Edit a File | nano <fileName.extensionName>
--------------------------------------
| Look at a File | cat <fileName.extensionName>
--------------------------------------

* Note: You must be in the directory containing the file to look at the file.
--------------------------------------
| Delete a File or Folder | rmdir <folderName>
--------------------------------------

## Directory Navigation Commands:
--------------------------------------
| List Pathway | pwd
--------------------------------------
| List Folders and Files in Current Directory | ls
--------------------------------------
| Change Directory | cd <directorynName>
--------------------------------------
| Go Up One Directory | cd .. or cd /
--------------------------------------
| Go To the Root Directory | cd ~
--------------------------------------

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


Running A Script On Startup:

	If you need a script to run automatically at startup in linux without user login or after the automatic boot to the windowing environment, without being able to view the output, there are two ways to go.

	1. Add a command to /etc/rc.local
		- This causes the command to run every time the raspberry pi is booted or rebooted.

		"Putting something into /etc/rc.local adds it to the boot sequence. The word "sequence" is important, if your code gets stuck then the boot sequence cannot proceed. The same with ~/.bashrc, if you put a faulty command in here you may not be able to login."

		How:

			1. raspberrypi ~$ nano /etc/rc.local

			2. Add this line of code to /etc/rc.local,

					python scriptname.py &

					or

					sleep 10;python scriptname.py &

						- The "sleep 10" is there to make sure that a gap is in place between the commands so that other portions of the boot prpcess can proceed.

					or 

					(sleep 10;python scriptname.py)&

						- The parenthesis are there to make sure that the commands within the parenthesis run in the background.

					or

					/yourpath/bin/yourscript.sh &

						- This runs the script below at the end of the path above.

						Then in yourscript.sh:

							#!/bin/sh

							sleep 10

							sudo python scriptname.py



	2. Add a command to ~/.bashrc
		- Do this only if the script should run whenever a specific user logs in to the pi.

		Implementation for this is the same as for the /etc/rc.local as far as I know.


	Definitions & Explanations:

		.bash_profile vs .bashrc:

				- .bashrc is for use with non-login shells and .bash_profile is for login shells.

		Non-login shells vs Login Shells:

			Login shells are shells such as SSH and can be logged out of whereas non-login shells can not be logged out of and instead of being identified as "-bash" they are identified as just "bash".

			For example, when the command "echo $0" is run in SSH it returns "-bash", signifying that it is a login shell. However when the command is run in LX Terminal on the raspberry pi it returns "/bin/bash", signifying that it is  a non-login shell.