#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rere_daisha_msgs/srv/arm_pos.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "smacc2/smacc_client.hpp"

namespace sm_rere_daisha
{
namespace cl_arm_control
{
class ClArmControl : public smacc2::ISmaccClient
{
public:
    using ArmPos = rere_daisha_msgs::srv::ArmPos;
    ClArmControl() {}

    void OnInitialize() override
    {
        auto node = getNode();
        client_ = node->create_client<ArmPos>("arm_pos");
    }

    rclcpp::Client<ArmPos>::SharedFuture sendPos(const ArmPos::Request & req)
    {
        auto request = std::make_shared<ArmPos::Request>(req);
        return client_->async_send_request(request);
    }

    bool waitForServer(std::chrono::milliseconds timeout = std::chrono::milliseconds(2000))
    {
        return client_->wait_for_service(timeout);
    }
private:
    rclcpp::Client<ArmPos>::SharedPtr client_;
};
}   // namespace cl_arm_control
}   // namespace sm_rere_daisha