# uavcc-simulator
## Installations and running Avoidance
The simulator uses ROS Melodic and Gazebo 9. For instructions on installing all necessary dependencies, please follow the readme in the PX4 Avoidance repository.
https://github.com/PX4/PX4-Avoidance \\
Complete the instructions until you reach the step to run local planner with the following command.
```
roslaunch local_planner local_planner_depth-camera.launch
```
Upon execution, if you are able to see an RViz window display the drone and its pointcloud, you have successfully installed all necessary technologies. \\

## Sample Control System
We have provided a sample control system that will follow the rover in the first simulated trial. To run this solution, follow these steps. \\

Step 1: Build the caktin workspace \\
From the catkin workspace, run ```catkin build```.
Step 2: Sourcing \\
Next, source the environment. \\
```source devel/setup.bash```
Step 3: Run Avoidance \\
Run the avoidance.sh script in the catkin-ws directory. \\
Step 4: Run the autonomous drone package


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
