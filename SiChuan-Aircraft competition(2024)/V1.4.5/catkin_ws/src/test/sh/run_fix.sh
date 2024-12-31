#!/bin/bash

xterm -e " roslaunch test simul_2D.launch & rosrun test origin"  &
sleep 1


xterm -e " roslaunch  test  fix_debug.launch"  &

xterm -e "roslaunch  test  fix_other.launch"  &

xterm -e "roslaunch  test  fix_work.launch"  &

# xterm -e "rosrun  test  avoid3"  &
# xterm -e "rosrun  test  avoid2"  &