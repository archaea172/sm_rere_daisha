#pragma once

#include "smacc2/smacc_client_behavior.hpp"
#include "sm_rere_daisha/clients/cl_arm_control.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"

namespace sm_rere_daisha
{
namespace cb_arm_to_point
{
template <typename TSource, typename TOrthogonal>
class CbArmToPoint : public smacc2::SmaccClientBehavior
{
public:
    CbArmToPoint(const geometry_msgs::msg::PointStamped & target)
    : target_(target)
    {
    }

    void onEntry() override
    {
        auto cl = this->requiresClient<cl_arm_control::ClArmControl>();

        if (!cl->waitForServer(std::chrono::milliseconds(2000)))
        {
            RCLCPP_WARN(getLogger(), "[CbArmToPoint] /arm_control not available");
            // ここで失敗イベントを投げてもOK
            // this->postEvent<EvArmFailure>();
            return;
        }

        RCLCPP_INFO(getLogger(), "[CbArmToPoint] Sending arm_target (%.2f, %.2f, %.2f)",
                    target_.point.x, target_.point.y, target_.point.z);

        auto future = cl->sendGoal(target_);
        (void)future;
    }
private:
};
}
}