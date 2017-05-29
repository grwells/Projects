#! /bin/sh
### BEGIN INIT INFO
# Provides:          gps__init__.py
# Required-Start:    $all
# Required-Stop:     
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: GPS Stuff
### END INIT INFO

PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/bin

. /lib/init/vars.sh
. /lib/lsb/init-functions

case "$1" in
  start)
    log_begin_msg "Starting GPS Service"
python3 /home/pi/Repository/GPS_Data_Parser/gps__init__.py
    log_end_msg $?
    exit 0
    ;;
  stop)
    log_begin_msg "Stopping GPS Service"

    # do something to kill the service or cleanup or nothing

    log_end_msg $?
    exit 0
    ;;
  *)
    echo "Usage: /etc/init.d//home/pi/Repository/GPS_Data_Parser/gps__init__.py {start|stop}"
    exit 1
    ;;
esac