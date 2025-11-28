#pragma once

#include "smacc2/smacc.hpp"
#include "sm_rere_daisha/sm_rere_daisha.hpp"

#include "sm_rere_daisha/orthogonals/or_arm.hpp"
#include "sm_rere_daisha/client_behaviors/cb_arm_to_point.hpp"

namespace sm_rere_daisha
{
namespace st_catch_ball
{
struct StCatchBall : smacc2::SmaccState<StCatchBall, SmRereDaisha>
{
    using SmaccState::SmaccState;

    using reactions = mpl::list<>;

    static void staticConfigure()
    {
        configure_orthogonal<OrArm, cb_arm_to_point::CbArmToPoint<StCatchBall, OrArm>();
    }

    void onEntry()
    {
        RCLCPP_INFO(getLogger(), "[StSearchBall] Entry");
    }

    void onExit()
    {
        RCLCPP_INFO(getLogger(), "[StSearchBall] Exit");
    }
};

}   // namespace st_catch_ball
}   // namespace sm_rere_daisha