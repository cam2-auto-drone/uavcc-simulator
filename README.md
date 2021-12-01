# uavcc-simulator
## Installations and running Avoidance
The simulator uses ROS Melodic and Gazebo 9. For instructions on installing all necessary dependencies, please follow the readme in the PX4 Avoidance repository.
https://github.com/PX4/PX4-Avoidance \
Complete the instructions until you reach the step to run local planner with the following command.
```
roslaunch local_planner local_planner_depth-camera.launch
```
Upon execution, if you are able to see an RViz window display the drone and its pointcloud, you have successfully installed all necessary dependencies.
<!--
## Sample Control System
We have provided a sample control system that will follow the rover in the first simulated trial. To run this solution, follow these steps. \

Step 1: Build the caktin workspace \
From the catkin workspace, run ```catkin build```.
Step 2: Sourcing \
Next, source the environment. \
```source devel/setup.bash```
Step 3: Run Avoidance \
Run the avoidance.sh script in the catkin-ws directory. \
Step 4: Run the autonomous drone package
-->

## Trial 1 and 2 Simulators
### Build and Run
This repository contains the Trial 1 and Trial 2 worlds that solutions will be tested in. 

Begin by cloning this repository onto your machine. Once it is downloaded, follow these steps to begin the simulation: 

Step 1: Build the plugin
```mkdir build
cd build
cmake ../
cd ..
make
```
Step 2: Update the Gazebo plugin path so that the current path is included. Run this command from the build directory.

```export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH```

Step 3: Run the world using Gazebo

```cd ~uavcc-simulator/trial_1_setup
gazebo trial_1.world
```
To run the Trial 2 world, follow the same instructions for Trial 1 with the trial_2_setup directory.
## System Information
This simuator was tested on Ubuntu 18.04 with ROS Melodic.
## Frequently Asked Questions
### The Trial 1 world loads in Gazebo, but the object does not move.
This occurs when the GAZEBO_PLUGIN_PATH is incorrect. Ensure step 2 is run each time you run the program in a new terminal. The line in step 2 may be added to ```~/.bashrc``` to be run automatically each time a new terminal is opened.
