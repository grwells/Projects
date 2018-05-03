## -*- Makefile -*-
##
## User: deepg
## Time: May 1, 2018 3:03:05 PM
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_Aquaman=GNU-amd64-Windows


all: $(TARGETDIR_Aquaman)/Aquaman

## Target: Aquaman
CPPFLAGS_Aquaman = \
	-IAquaman.cpp \
	-Iaquaman_main.cpp \
	-Inbproject\private\cpp_standard_headers_indexer.cpp \
	-Inbproject\private\c_standard_headers_indexer.c \
	-I..\Batman\nbproject\private\cpp_standard_headers_indexer.cpp \
	-I..\Batman\nbproject\private\c_standard_headers_indexer.c \
	-I..\Communication_System\CommSys.cpp \
	-I..\Debug_MessagePrinter\MSG_Printer.cpp \
	-I..\DS18B20_TemperatureSensor\DS18B20.cpp \
	-I..\HC-SRO4_Ultrasonic\HC-SR04.cpp \
	-I..\INA219_CurrentSensor\batmanT.cpp \
	-I..\INA219_CurrentSensor\hello.cpp \
	-I..\INA219_CurrentSensor\INA219.cpp \
	-I..\nbproject\private\cpp_standard_headers_indexer.cpp \
	-I..\nbproject\private\c_standard_headers_indexer.c \
	-I..\Power_Controller\PC.cpp \
	-I..\SoilHumidity_Sensor\Hygrometer.cpp \
	-I..\Test\main.cpp \
	-I..\Test\nbproject\private\cpp_standard_headers_indexer.cpp \
	-I..\Test\nbproject\private\c_standard_headers_indexer.c \
	-I..\Tolako5V_CurrentSensor\Tolako5V.cpp \
	-I..\WiringPi_FakeImplementation\wiringPiI2C_fake.cpp \
	-I..\WiringPi_FakeImplementation\wiringPiSPI_fake.cpp \
	-I..\WiringPi_FakeImplementation\wiringPi_fake.cpp \
	-I..\WiringPi_For_Win10\wiPi_test.cpp \
	-I..\WiringPi_For_Win10\wiringPi_fake.c
OBJS_Aquaman =  \
	$(TARGETDIR_Aquaman)/Aquaman.o \
	$(TARGETDIR_Aquaman)/aquaman_main.o
USERLIBS_Aquaman = ..\..\..\..\..\..\..\SysGCC\raspberry\arm-linux-gnueabihf\include\wiringShift.h ..\..\..\..\..\..\..\SysGCC\raspberry\arm-linux-gnueabihf\include\wiringSerial.h ..\..\..\..\..\..\..\SysGCC\raspberry\arm-linux-gnueabihf\include\wiringPiSPI.h ..\..\..\..\..\..\..\SysGCC\raspberry\arm-linux-gnueabihf\include\wiringPiI2C.h ..\..\..\..\..\..\..\SysGCC\raspberry\arm-linux-gnueabihf\include\wiringPi.h $(SYSLIBS_Aquaman) 
DEPLIBS_Aquaman =       
LDLIBS_Aquaman = $(USERLIBS_Aquaman)


# Link or archive
$(TARGETDIR_Aquaman)/Aquaman: $(TARGETDIR_Aquaman) $(OBJS_Aquaman) $(DEPLIBS_Aquaman)
	$(LINK.cc) $(CCFLAGS_Aquaman) $(CPPFLAGS_Aquaman) -o $@ $(OBJS_Aquaman) $(LDLIBS_Aquaman)


# Compile source files into .o files
$(TARGETDIR_Aquaman)/Aquaman.o: $(TARGETDIR_Aquaman) Aquaman.cpp
	$(COMPILE.cc) $(CCFLAGS_Aquaman) $(CPPFLAGS_Aquaman) -o $@ Aquaman.cpp

$(TARGETDIR_Aquaman)/aquaman_main.o: $(TARGETDIR_Aquaman) aquaman_main.cpp
	$(COMPILE.cc) $(CCFLAGS_Aquaman) $(CPPFLAGS_Aquaman) -o $@ aquaman_main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_Aquaman)/Aquaman \
		$(TARGETDIR_Aquaman)/Aquaman.o \
		$(TARGETDIR_Aquaman)/aquaman_main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_Aquaman)


# Create the target directory (if needed)
$(TARGETDIR_Aquaman):
	mkdir -p $(TARGETDIR_Aquaman)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

