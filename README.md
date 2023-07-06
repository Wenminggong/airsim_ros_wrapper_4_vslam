# airsim_ros_pkgs

This repo contains airsim_ros_wrapper, which is modified for visual slam from Microsoft Airsim.

## Modifications

* Synchronize images from binocular cameras using Airsim simGetImages()
* save the ground truth trajectory to txt file through adding a new thread to run ground_truth_save ros Timer
* airsim settings and vslam configs are in */config* 
* add a new ros node (single_agent_airsim_node) for runing single agent airsim_ros_wrapper, you can run multi single_agent_airsim_node to control multi vehicles separately in Airsim. We try to increase the parallelism through running independent ros-process for every agent and adding ros-threads for msgs publishing and subscribing.