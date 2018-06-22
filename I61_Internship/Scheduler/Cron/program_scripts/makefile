sendmessage: sendmessage.cpp commsys 	
	g++ -std=c++0x -o sendmsg sendmessage.cpp commsys -lwiringPi

readH2O: readH2O.cpp hcsr04  
	g++ -std=c++0x -o readH2O readH2O.cpp hcsr04 -lwiringPi

hcsr04: /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.cpp /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.h msg_printer
	g++ -c -o hcsr04 /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.cpp msg_printer -lwiringPi

msg_printer: /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Debug_MessagePrinter/MSG_Printer.cpp /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Debug_MessagePrinter/MSG_Printer.h 
	g++ -c -o msg_printer /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Debug_MessagePrinter/MSG_Printer.cpp 

commsys: /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/CommSys.cpp fona
	g++ -c /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/CommSys.cpp fona -lwiringPi


fona: /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/FONA/FONA.cpp
	g++ -c /home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/FONA/FONA.cpp -lwiringPi

clean:
	rm 
