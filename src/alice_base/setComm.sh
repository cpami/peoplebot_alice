# This file runs all the necessary commands before running the roslaunch
#	startup on ALICE
# It is important that the file is run using sudo command!
# chmod +x ./setComm.sh 
# sudo bash ./setComm.sh


# Estblishing the broadcasting connection
#export ROS_MASTER_URI=http://192.168.0.3:11311
export ROS_IP=192.168.0.4

sh -c "echo 0 >/proc/sys/net/ipv4/icmp_echo_ignore_broadcasts"

# Set correct serial connections
setserial /dev/ttyS0 irq 4
setserial /dev/ttyS1 irq 3
setserial /dev/ttyS2 irq 10
setserial /dev/ttyS3 irq 5

