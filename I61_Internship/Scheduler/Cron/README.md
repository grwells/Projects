# How Use Crontab
Crontab is a scheduling tool for the OS. Tasks can be scheduled by hour, week, or month. To use crontab the user must create a crontab file that contains the scheduled tasks. Crontab files with scheduled tasks are denoted by the file postfix .cronf(crontab file). Corresponding task scripts are use a .taskf postfix.

# Crontab File Syntax
The file can contain as many tasks as needed. Each script must be executable and bash shell readable. To make that possible execute the following command:

> chmod +rx /bash/script/location

The script must also contain a shebang line at the top of the file.

 #!/bin/sh

Minute | Hour | Month | Year | Task
  * * * * usr(like pi/root) /bash/script/location

# How to Use With Aquaman
In crontab daily directory: 
* call water measurement sensor and send data to the user
* interpret the data and move on, calling all other necessary functions

	
