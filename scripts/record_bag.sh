cd ~/quadrotor-simulation/bagfiles
rosbag record -O subset  /ground_truth_to_tf/pose
rostopic echo   /ground_truth_to_tf/pose -b subset.bag -p >position_data.csv
