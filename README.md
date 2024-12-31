# 基本介绍
  本仓库内的所有项目均为本科阶段参加所有比赛的工程文件，以下是对各个工程文件的介绍
# Aircraft in test
  此项目为实验室成员所有，主要实现对无人机的PID参数进行在线调参和基于esp32的飞控代码编写，以及遥控器部分的代码编写。解决了需要不断手动更新PID参数的麻烦，主要为通过WiFi模块实现，在网页端实现在线调参，目前此项目还处于测试前阶段，还有需要可供完善的部分，并不是最终版
# Electronics Design Contset in 2023
  此项目为参加2023年全国大学生电子设计竞赛无人机G题机载电脑端代码，控制开发板部分可以自己移植，本项目主要用的开发板为TI开发板。主要功能包括利用二维激光雷达建图，激光测距数据作为定高数据，但经过实验试飞证明，此建图只适合室内，室外大范围建图效果不好，且存在大部分点云数据会丢失，主要激光雷达扫描数据存在局限性。谨慎使用
# Electronics Design Contest in 2024(Game of chance)
  此项目为参加2024年全国大学生电子设计竞赛机器与人进行对弈的功能实现，主要采用博弈算法，采用树莓派作为机器人角色，stm32作为开发板，利用视觉进行功能实现。此项目较为简单，不过多赘述。
# SiChuan Aircraft competition(2023)
  此项目为参加2023年四川省第三届未来飞行器挑战赛实践类赛道，主要功能为室外GPS定位实现无人机利用opencv识别二维码从而控制舵机投掷对应识别到的二维码的小球数量，同时在规划区域内进行路径规划，识别完成二维码之后从A区域进行转向，从而到达B区域，执行投掷小球的任务处理，最终返回原点。定位方式采用GPS，机载电脑为树莓派Ubuntu18.04，开发板为飞控pixhawk2.4.8.视觉采用opencv识别。舵机采用50HZ，所有任务处理均采用ROS框架进行开发。
# SiChuan Aircraft competition(2024)
  此项目为参加2024年四川省第四届未来飞行器挑战赛实践类赛道实机飞行项目，主要功能为室内激光雷达定位，利用雷达点云数据处理实现穿框识别二维码，识别对应的柱子。机载电脑为树莓派Ubuntu18.04，视觉采用opencv，开发板为pixhawk2.4.8，

  ## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
