#pragma once

#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "smacc2/smacc_client.hpp"

namespace sm_rere_daisha
{
namespace cl_wheel_vel
{
class ClWheelVel : public smacc2::ISmaccClient
{
public:
    using Float64MultiArray = std_msgs::msg::Float64MultiArray;

    ClWheelVel() {}

    void onInitialize() override
    {
        auto node = getNode();
        pub_ = node->create_publisher<Float64MultiArray>("/wheel_vel", rclcpp::QoS(10));
    }

    void publishVelocity(const std::vector<double> & wheels)
    {
        Float64MultiArray msg;
        msg.data = wheels;
        pub_->publish(msg);
    }
private:
    rclcpp::Publisher<Float64MultiArray>::SharedPtr pub_;
};
}   // namespace cl_wheel_vel
}   // namespace sm_rere_daisha