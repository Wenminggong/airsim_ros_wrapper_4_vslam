# airsim_ros_pkgs

This repo contains airsim_ros_wrapper, which is modified for visual slam from Microsoft Airsim.

## Modifications

* Synchronize images from binocular cameras using Airsim simGetImages()
* save the ground truth trajectory to txt file through adding a new thread to run ground_truth_save ros Timer
* airsim settings and vslam configs are in */config* 