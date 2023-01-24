Second assignment
================================

This is a possible implementation of the second assignment of Reaserch Track 1 couse. 

The goal of this assignment is to familiarize with **ROS** by developing 3 (splitted into 4) nodes for specific 3D **Gazebo** and **Rviz** simulations.

Installing
----------------------

To run this assignment it is necessary to have **ROS noetic** version installed. The simplest way is to have the [**Docker**](https://docs.docker.com/get-docker/) and then follow this [**ROS guide**](http://wiki.ros.org/ROS/Installation).

To launch the 4 nodes, it is necessary to install **xterm** terminal using the command ```apt-get install xterm```.

It is also necessary to create a workspace and named it `/my_ros`. You can find how to create a workspace on [wiki.ros.org](http://wiki.ros.org/catkin/Tutorials/create_a_workspace).

How to run
----------------------

To launch the assignment is necessary to clone the GitHub repository using:

```bash
git clone command https://github.com/VeronicaG24/follow_goal.git
```

and move all the content into the folder `/my_ros/src`.
Then from the workspace, compile using:

```bash
catkin_make
```

Now, open two different terminal windows and move into `/my_ros` workspace.
In the first terminal, launch **Gazebo** and **Rviz** simulations using  the following command:

```bash
launch assignment_2_2022 assignment1.launch
```

Two windows of **Gazebo** and **Rviz** will be spawed:

<table><tr>
  <td> <img src="./Gazebo.png" alt="Drawing" style="width: 600px;"/> </td>
  <td> <img src="./Rviz.png" alt="Drawing" style="width: 600px;"/> </td>
</tr>
<tr>
   <td>Gazebo window</td>
   <td>Rviz window</td>
  </tr>
</table>

And then, from the other terminal, launch all the nodes:

```bash
launch follow_goal follow_goal.launch
```

Requirements
----------------------

The code is designed to respect the following requirements:

* Develop four nodes:
    1. A setting node: allows the user to set a goal position (x, y) or to delete it
    2. A publisher node: publishes the current robot position (x, y) and velocities (vel_x, vel_y);
    3. A service node: prints the number of goals reached and deleted
    4. A subscriber node: prints the euclidian distance from the target, and the average speed of the robot
* Create a **launch file**, to start the whole program, and pass the rate parameter for printing the information of the subscriber node

Description of the code
----------------------

As described before, four nodes have been developed in cpp language:
1. `goal_set`: to set goal coordinates
2. `publisher`: to publish position and velocity of the robot
3. `goal_count`: prints the number of goal reached and deleted
4. `subscriber`: prints euclidian distance and average velocity






