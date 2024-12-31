# -*- coding: utf-8 -*-
from __future__ import print_function

import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/melodic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/melodic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in '/home/shili/wlf_catkin_ws/devel_isolated/duoji_node;/home/shili/wlf_catkin_ws/devel_isolated/send_pos_to_px4_node;/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser;/home/shili/wlf_catkin_ws/devel_isolated/first_fly_node;/home/shili/N10_ws/devel_isolated/n10_slam_test;/home/shili/N10_ws/devel_isolated/lsn10;/home/shili/N10_ws/devel;/home/shili/wlf_catkin_ws/devel;/home/shili/px4_learn_ws/devel;/home/shili/oradar_ws/devel;/home/shili/learn_catkin_ws/devel;/home/shili/catkin_ws/devel;/opt/ros/melodic'.split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/shili/wlf_catkin_ws/devel_isolated/first_fly_node/env.sh')

output_filename = '/home/shili/wlf_catkin_ws/build_isolated/first_fly_node/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    # print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
