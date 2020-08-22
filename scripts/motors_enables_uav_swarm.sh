cd ~/quadrotor-simulation
rosservice call /uav1/enable_motors "enable: true"
rosservice call /uav2/enable_motors "enable: true"
rosservice call /uav3/enable_motors "enable: true"
rosservice call /uav4/enable_motors "enable: true"
