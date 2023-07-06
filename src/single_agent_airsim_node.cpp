#include "ros/ros.h"
#include "single_agent_airsim_ros_wrapper.h"
#include <ros/spinner.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "single_agent_airsim_node");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    std::string host_ip = "localhost";
    nh_private.getParam("host_ip", host_ip);
    AirsimROSWrapper airsim_ros_wrapper(nh, nh_private, host_ip);

    if (airsim_ros_wrapper.is_used_img_timer_cb_queue_) {
        airsim_ros_wrapper.img_async_spinner_.start();
    }

    if (airsim_ros_wrapper.is_used_lidar_timer_cb_queue_) {
        airsim_ros_wrapper.lidar_async_spinner_.start();
    }

    if (airsim_ros_wrapper.is_used_ground_truth_save_queue_) {
        airsim_ros_wrapper.ground_truth_save_spinner_.start();
    }

    if (airsim_ros_wrapper.is_used_depth_img_timer_cb_queue_) {
        airsim_ros_wrapper.depth_img_async_spinner_.start();
    }

    if(airsim_ros_wrapper.is_used_update_command_timer_cb_queue_){
        airsim_ros_wrapper.update_command_async_spinner_.start();
    }

    if(airsim_ros_wrapper.is_used_control_update_timer_cb_queue_){
        airsim_ros_wrapper.control_update_async_spinner_.start();
    }

    if(airsim_ros_wrapper.is_used_imu_timer_cb_queue_){
        airsim_ros_wrapper.imu_async_spinner_.start();
    }

    // ros::spin();
    ros::AsyncSpinner spinner(2); // Use 4 threads
    spinner.start();
    ros::waitForShutdown();


    return 0;
}