// include/sm_rere_daisha/states/st_catch_ball.hpp
#pragma once

#include <smacc2/smacc.hpp>
#include <boost/mpl/list.hpp>

namespace sm_rere_daisha
{

struct SmRereDaisha;

// ボールをキャッチする状態（今はログだけ）
struct StCatchBall : smacc2::SmaccState<StCatchBall, SmRereDaisha>
{
  using SmaccState::SmaccState;
  using reactions = boost::mpl::list<>;  // まだ遷移はなし

  static void staticConfigure()
  {
    // 後で OrArm / CbArmToPoint をつなぎたいときにここで:
    // configure_orthogonal<OrArm, cb_arm_to_point::CbArmToPoint<StCatchBall, OrArm>>();
  }

  void onEntry()
  {
    RCLCPP_INFO(this->getLogger(), "[StCatchBall] Entry");
  }

  void onExit()
  {
    RCLCPP_INFO(this->getLogger(), "[StCatchBall] Exit");
  }
};

}  // namespace sm_rere_daisha
