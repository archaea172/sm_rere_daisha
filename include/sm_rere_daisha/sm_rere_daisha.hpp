// Copyright 2021 MyName/MyCompany Inc.
// Copyright 2021 RobosoftAI Inc. (template)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <memory>
#include <string>

#include "smacc2/smacc.hpp"

// ORTHOGONALS
#include "sm_rere_daisha/orthogonals/or_timer.hpp"

namespace sm_rere_daisha
{
// SMACC2 clases
using sm_rere_daisha::OrTimer;  // This is example variable - feel free to delete it.

//STATES
struct State1;
struct State2;

//--------------------------------------------------------------------
//STATE_MACHINE
struct SmRereDaisha
: public smacc2::SmaccStateMachineBase<SmRereDaisha, State1>
{
  using SmaccStateMachineBase::SmaccStateMachineBase;

  void onInitialize() override
  {
    // START: Example code - change or delete as needed
    this->createOrthogonal<OrTimer>();
    // Use Blackboard to store global state-machine data - example - feel free to delete it.
    setGlobalSMData(
      "output_message_note", std::string("{I am very cool smacc2 SM called 'sm_rere_daisha'}"));
    // END: Example code - change or delete as needed
  }
};

}  // namespace sm_rere_daisha

//STATES
#include "states/st_state_1.hpp"
#include "states/st_state_2.hpp"
