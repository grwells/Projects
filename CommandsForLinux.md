Commands For Linux

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

	VNC Server login password : Garrett1
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