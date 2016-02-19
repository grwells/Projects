##Developement Journal
#Garrett Wells

##dateofcompletion
Entry explaining what you have been done that week in working on the project. Each journal entry must be at least 150 words written with proper grammar and complete sentences. Your grade for this project will be largely based on this journal, so don't slack on it. Make sure it's stored in a markdown text file and is included in your GitHub repository.

##2/5/16
This week I received the raspberry pi along with all of the parts that I need to begin learning Python and setting up the raspberry pi. At the beginning of the week I watched several tutorials on how to navigate the Linux file system. I took notes on the things I learned (CommandsForLinux.md) and also researched the hardware I would need in order to use the raspberry pi. The pi 2 B+ arrived on Wednesday and I was able to begin work on it immediately. I was working on it from 10:45 am to 4:30pm. I read the step by step setup instructions that I found on Adafruit’s website and was able to first set up the automatic Wi-Fi connection on start up. Then I began finding a way to allow the pi to interface with my laptop so that I would be able to use my laptop's screen in collusion with the raspberry pi's graphics. To accomplish this I had to do two things. Set up a SSH terminal(Secure Shell), and then set up a VNC(Virtual Network Connection).    

##2/12/16
I learned that the raspberry pi B+ is integrated in such a way that Python is the easiest language to program it in. As a result I created a code academy account and have begun learning the Python syntax rules. In addition to learning the extreme basics of Python I began learning about how to create circuits that feature LED lights which I can then light up by running a program in Python. For some unknown reason I have not been successful in getting power to my circuit from the pi but, as a positive, I was able to write a Python program that ran with limited success. It out putted instructions for how to run the program, but did little else, namely not causing the LED's to light up. I have tried completeing one of the basic recommended projects provide by adafruit but with no success. My failure may have been a result of my not activating the SPI interface for the pi. The SPI(Serial Peripheral Interface) provides short range communications between the pi and other connected devices such as my circuit, so perhaps its state of non-activation was the reason my attempts at running a program failed.

##2/19/16
This week I successfully installed the SPI interface on my pi's operating system and also proceeded to continue working on learning python. I learned the syntax for conditionals and began creating a python version of the pig latin translator that we created in comp sci. Midway through the week I began having problems accessing the pi via SSH. I decided to try reinstalling the operating system and starting over again from scratch. However, I began experiencing problems, namely I could not boot from the SDC. I watched all of the tutorials and posted for help on a couple of forums and was eventually successful in reformatting the SDC and installing the operating system. However, when I tried to boot from the SDC again I ran into a string of boot errors. One of the errors mentioned was that the installed operating system was too big for the SDC. This has led me to try to find a smaller OS and install that. This whole process has been slow and extremely frustrating, especially since it has taken hours of debugging to even get on the right track.