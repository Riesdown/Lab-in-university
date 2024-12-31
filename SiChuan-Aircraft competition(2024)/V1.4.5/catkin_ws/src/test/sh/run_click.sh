#!/bin/bash




gnome-terminal -- roslaunch test click_other.launch &
sleep 10

gnome-terminal -- roslaunch test click_debug.launch &
gnome-terminal -- roslaunch test init.launch &
# gnome-terminal -- rosrun test state &

gnome-terminal -- roslaunch test click_work.launch &

# gnome-terminal -- rosrun test aruco.py &
# gnome-terminal -- rosrun test circle_node.py &
gnome-terminal -- rosrun test all.py &


# gnome-terminal -- rosrun test avoid3 &
# gnome-terminal -- rosrun test avoid2 &
