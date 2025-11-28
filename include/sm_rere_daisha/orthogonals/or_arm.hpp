#pragma once

#include "smacc2/smacc_orthogonal.hpp"
#include "sm_rere_daisha/clients/cl_arm_control.hpp"

namespace sm_rere_daisha
{
class OrArm : public smacc2::Orthogonal<OrArm>
{
public:
void onInitialize() override
{
    auto armClient = this->createClient<cl_arm_control::ClArmControl>();
    (void)armClient;
}
};
}   // namespace sm_rere_daisha