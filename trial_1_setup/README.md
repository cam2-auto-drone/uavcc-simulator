This contains the Gazebo setup for Trial 1 of the competition.

Step 1: Build the plugin
```mkdir build
cd build
cmake ../
make
```
Step 2: Make sure Gazebo can load the plugins. Run this command from the build directory.

```export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH```

Step 3: Run the world using Gazebo

```cd ~/trial_1_setup
gazebo animated_box.world
```
Video: trial_1_setup.mp4

