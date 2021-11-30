# uavcc-simulator
## Installations
The simulator uses ROS Melodic and Gazebo 9. For instructions on installing all necessary dependencies, please follow the readme in the PX4 Avoidance repository.
https://github.com/PX4/PX4-Avoidance
Complete the instructions until you reach the step to run local planner with the following command.
```
roslaunch local_planner local_planner_depth-camera.launch
```
Once you reach this step, if you are able to see an RViz window show up displaying the drone and its pointcloud, you have successfully installed all necessary technologies.



## Trial 1 Simulator
### Build and Run
This contains the Gazebo setup for Trial 1 of the competition.

Step 1: Build the plugin
```mkdir build
cd build
cmake ../
cd ..
make
```
Step 2: Make sure Gazebo can load the plugins. Run this command from the build directory.

```export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH```

Step 3: Run the world using Gazebo

```cd ~/trial_1_setup
gazebo animated_box.world
```
Video: trial_1_setup.mp4
