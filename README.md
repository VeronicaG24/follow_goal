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

**goal_set** node
----------------------

Global variables are defined at the start of the code:

* `reached`: integer for number of goals reached
* `deleted`: integer for number of goals deleted
* `x_pos`: float for x-coordinate of the goal
* `y_pos`: float for y-coordinate of the goal
* `client`: instance for client
* `srv`: instance for service

The code is divided into separate functions:

* `main(int argc, char **argv)`: manages ROS init, NodeHandle, action client, and the option choosed from the menu.

```python
define varible for choosed option
define varible for number of succeed goals reached
define variable to state if a goal is set, set to 0

call ROS init function with arguments argc, argv, "goal_set";
define NodeHandle;
Create action client;
get state from action client;
call waitForService method

while ROS is working:
    call input_menu function
    get the state of the action client
    set state for setting goal as the comparison between "SUCCEEDED" and  the state of the action client

    if the state of the action client is not 0 and the comparison returns 0:
        decrease variable to state if the goal is set

    switch in base of values of varible for choosed option:
        case when = 1:
            get the state from getState method;
            compare "SUCCEEDED" and object state; 

            if the comparison return 1 and a goal is set:
                ask to delate the goal before setting a new one
            
            if the comparison return 0 and a goal is set
                decrease variable to state if the goal is set;
            else
                call ask_goal() function;
                set x coordinate of the goal;
                set y coordinate of the goal;
                send the goal to the action client;
                increase variable to state if the goal is set;

            wait 1 second;
        case when = 2:
            get the state from getState method;
            compare "SUCCEEDED" and object state; 
            
            if the comparison return 1 and a goal is set:
                cancel goal;
                decrease variable to state if the goal is set;
            else
                ask to set a goal;

            wait 1 second;
        case when = 3:
            get the number of delated and reached goal;
            call get_number_goals() function;
            wait 1 second;
        case when = 4: 
            if a goal is set:
                cancel goal;
            exit the program;
        default case:
            wait 1 second;

```



