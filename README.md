# cpp-uav-simulations
<<<<<<< HEAD

## Rotors UAV gazebo simualtions


<<<<<<< HEAD
=======
=======
UAV gazebo simualtions


If you don't have ROS workspace yet you can do so by

>>>>>>> RotorS
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace  # initialize your catkin workspace
$ cd ~/catkin_ws/
$ catkin init
$ cd ~/catkin_ws/src
<<<<<<< HEAD
$ git clone -b RotorS https://github.com/Marslanali/cpp-uav-simulations.git 
```

=======
$ git clone -b med18 https://github.com/marslanali/rotors_simulator.git
$ git clone -b med18 https://github.com/marslanali/mav_comm.git
```


>>>>>>> RotorS
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
<<<<<<< HEAD
>>>>>>> fa758e29eb0f182072442a7a923753a4b747238d
=======
>>>>>>> RotorS
