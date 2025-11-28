#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rere_daisha_msgs/srv/ArmPos.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "smacc2/smacc_client.hpp"

namespace sm_rere_daisha
{
namespace cl_arm_control
{
class ClArmControl : public smacc2::ISmaccCLient
{
public:
    ClArmControl() {}

    void OonInitialize() override
    {
        auto node = getNode();
        client_ = node->create_client<rere_daisha_msgs::srv::ArmPos>("arm_pos");
    }

    rclcpp::Client<geometry_msgs::msg::PointStamped>::SharedFuture sendPos(const geometry_msgs::msg::PointStamped & req)
    {
        auto request = std::make_shared<geometry_msgs::msg::PointStamped>(req);
        return client_->async_send_request(request);
    }

    bool waitForServer(std::chrono::milliseconds timeout = std::chrono::milliseconds(2000))
    {
        return client_->wait_for_service(timeout);
    }
private:
    rclcpp::Client<rere_daisha_msgs::srv::ArmPos>::SharedPtr client_;
};
}   // namespace cl_arm_control
}   // namespace sm_rere_daisha