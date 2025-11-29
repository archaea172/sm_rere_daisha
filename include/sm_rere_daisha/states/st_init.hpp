// include/sm_rere_daisha/states/st_init.hpp
#pragma once

#include <smacc2/smacc.hpp>
#include <boost/mpl/list.hpp>

#include "sm_rere_daisha/states/st_catch_ball.hpp"
#include "sm_rere_daisha/orthogonals/or_timer.hpp"
#include "cl_ros2_timer/client_behaviors/cb_timer_countdown_once.hpp"

namespace sm_rere_daisha
{

struct SmRereDaisha;

// 初期状態
struct StInit : smacc2::SmaccState<StInit, SmRereDaisha>
{
  using SmaccState::SmaccState;

  // タイマーイベントで StCatchBall に遷移
  using reactions = boost::mpl::list<
    smacc2::Transition<
      cl_ros2_timer::EvTimer<cl_ros2_timer::CbTimerCountdownOnce, OrTimer>,
      StCatchBall,
      smacc2::SUCCESS
    >
  >;

  static void staticConfigure()
  {
    // 10 は cl_ros2_timer 側の仕様に従って秒などに解釈される
    configure_orthogonal<OrTimer, cl_ros2_timer::CbTimerCountdownOnce>(10);
  }

  void onEntry()
  {
    RCLCPP_INFO(this->getLogger(), "[StInit] onEntry");
  }

  void onExit()
  {
    RCLCPP_INFO(this->getLogger(), "[StInit] onExit");
  }
};

}  // namespace sm_rere_daisha
