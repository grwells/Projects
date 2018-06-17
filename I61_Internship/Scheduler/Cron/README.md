# How Use Crontab
Crontab is a scheduling tool for the OS. Tasks can be scheduled by hour, week, or month. To use crontab the user must create a crontab file that contains the scheduled tasks. Crontab files with scheduled tasks are denoted by the file postfix .cronf(crontab file). Corresponding task scripts are use a .taskf postfix.

# Crontab File Syntax
The crontab file can contain as many tasks as needed. The tasks are typically links to bash scripts that can be run at the scheduled time. Crontab files use the file extension .crt while bash scripts are denoted by the .sh file extension.

> //Minute | Hour | Month | Year | Task
> * * * * usr(like pi/root) /bash/script/location

Each bash script must be executable and bash shell readable. To make that possible execute the following command:

> chmod +rx /bash/script/location

Scripts must also contain a shebang line at the top of the file.

> #!/bin/sh

# How to Use With Aquaman
In crontab daily directory: 
* call water measurement sensor and send data to the user
* interpret the data and move on, calling all other necessary functions

	
