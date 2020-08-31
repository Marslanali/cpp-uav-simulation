# cpp-uav-simulations

After git clone `https://github.com/Marslanali/cpp-uav-simulations.git`. Please checkout to individual branches or clone individual branch.

* For **<a href="https://github.com/Marslanali/cpp-uav-simulations/tree/RotorS-develop">RotorS</a>** `git clone  -b RotorS https://github.com/Marslanali/cpp-uav-simulations.git`.

    * The `README.md` for this branch can be seen <a href="https://github.com/Marslanali/cpp-uav-simulations/tree/RotorS">here</a>. Please visit <a href="https://github.com/ethz-asl/rotors_simulator">here</a> for more information & original package.


* For **<a href="https://github.com/Marslanali/cpp-uav-simulations/tree/hector_quadrotor-develop">hector_quadrotor</a>** `git clone  -b hector_quadrotor https://github.com/Marslanali/cpp-uav-simulations.git`.

    * The `README.md` for this branch can be seen <a href="https://github.com/Marslanali/cpp-uav-simulations/tree/hector_quadrotor-develop">here</a>. Please visit  here <a href="http://wiki.ros.org/hector_quadrotor">hector_quadrotor </a> for more information & original package.


* For **<a href="https://github.com/Marslanali/cpp-uav-simulations/tree/hector_quadrotor">CrazyS</a>** `git clone  -b CrazyS https://github.com/Marslanali/cpp-uav-simulations.git`.

    * The `README.md` for this branch can be seen <a href="https://github.com/Marslanali/cpp-uav-simulations/tree/hector_quadrotor">here</a>. Please visit the <a href="https://github.com/gsilano/CrazyS">here</a> for more information & original package.


* For **<a href="https://github.com/Marslanali/cpp-uav-simulations/tree/hector_quadrotor">Parrot Bebop 2</a>** `git clone -b Parrot-bebop2 https://github.com/Marslanali/cpp-uav-simulations.git `

    * The `README.md` for this branch can be seen  <a href="https://github.com/Marslanali/cpp-uav-simulations/tree/Parrot-bebop2">here</a>. Please visit the <a href="https://github.com/gsilano/BebopS">here</a> for more information & original package.


## RotorS gazebo OctoMap simulations

If you don't have ROS workspace yet you can do so by

```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace  # initialize your catkin workspace
$ cd ~/catkin_ws/
$ catkin init
$ cd ~/catkin_ws/src
$ git clone -b RotorS-octomap https://github.com/Marslanali/cpp-uav-simulations.git

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

## Install the OctoMap library:

The OctoMap library is an open source library for generating volumetric 3D environment models from sensor data. This model data can then be used by a drone for navigation and obstacle avoidance.

```
sudo apt-get install ros-indigo-octomap ros-indigo-octomap-mapping
rosdep install octomap_mapping
rosmake octomap_mapping
```

Now, open `~/catkin_ws/src/rotors_simulator/rotors_gazebo/CMakeLists.txt` and add the following lines to the bottom of the file

```
find_package(octomap REQUIRED)
include_directories(${OCTOMAP_INCLUDE_DIRS})
link_libraries(${OCTOMAP_LIBRARIES})
```

Open `~/catkin_ws/src/rotors_simulator/rotors_gazebo/package.xml` and add the following lines

```
<build_depend>octomap</build_depend>
<run_depend>octomap</run_depend>
```

Open `rosed octomap_server octomap_tracking_server.launch`

and change the two following lines:

```
<param name="frame_id" type="string" value="map" />
...
<!--remap from="cloud_in" to="/rgbdslam/batch_clouds" /-->
```

to:

```
<param name="frame_id" type="string" value="world" />
...
<remap from="cloud_in" to="/firefly/vi_sensor/camera_depth/depth/points" />
```

## Running the simulation

Run the following three lines in separate terminal windows. This opens up Gazebo, Rviz and an octomap server.

```
roslaunch rotors_gazebo mav_hovering_example_with_vi_sensor.launch  mav_name:=firefly
roslaunch octomap_server octomap_tracking_server.launch
```

In Rviz, change the field `'Fixed Frame'` from `'map'` to `'world'` in the top left of the window. Now click the add button in the bottom left and select `MarkerArray`. Then double click the MarkerArray and change `'Marker Topic'` from `'/free_cells_vis_array'` to `'/occupied_cells_vis_array'`.

Now you should see a part of the floor.

In the Gazebo window, insert a cube in front of the red rotors and you should see it in Rviz.
