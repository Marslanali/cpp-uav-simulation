# cpp-uav-simulations
UAV gazebo simualtions


If you don't have ROS workspace yet you can do so by

```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace  # initialize your catkin workspace
$ cd ~/catkin_ws/
$ catkin init
$ cd ~/catkin_ws/src
$ git clone -b RotorS git clone https://github.com/Marslanali/cpp-uav-simulations.git 
```

Build your workspace with python_catkin_tools (therefore you need python_catkin_tools)

```
$ rosdep install --from-paths src -i
$ catkin build
```

Add sourcing to your .bashrc file

```
$ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
```
