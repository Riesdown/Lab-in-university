#!/bin/bash

xterm -e " roslaunch test simul_2D.launch & rosrun test origin"  &
sleep 1


xterm -e " roslaunch  test  vary_debug.launch"  &

xterm -e " rosrun test state"  &

xterm -e "roslaunch  test  vary_other.launch"  &

xterm -e "roslaunch  test  vary_work.launch"  &

# xterm -e "rosrun  test  avoid3"  &
# xterm -e "rosrun  test  avoid2"  &