#pragma once

#include <smacc2/smacc.hpp>
#include "sm_rere_daisha/sm_rere_daisha.hpp"

// タイマー用
#include "sm_rere_daisha/orthogonals/or_timer.hpp"
#include "cl_ros2_timer/client_behaviors/cb_timer_countdown_once.hpp"
#include "sm_rere_daisha/states/st_catch_ball.hpp"

namespace sm_rere_daisha
{
// STATE DECLARATION
struct StInit : smacc2::SmaccState<StInit, SmRereDaisha>
{
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  // ここがポイント：タイマーイベントで StSearchBall に遷移する
  typedef mpl::list<
    Transition<EvTimer<CbTimerCountdownOnce, OrTimer>, StCatchBall, SUCCESS>
  > reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {
    // 1秒（1クライアントtickでもOK）で一回だけ発火するタイマー
    configure_orthogonal<OrTimer, CbTimerCountdownOnce>(10);
  }

  void onEntry()
  {
    RCLCPP_INFO(getLogger(), "[StInit] onEntry");
  }

  void onExit()
  {
    RCLCPP_INFO(getLogger(), "[StInit] onExit");
  }
};
}  // namespace sm_rere_daisha
