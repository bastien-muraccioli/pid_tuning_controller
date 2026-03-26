#pragma once

#include <mc_control/fsm/Controller.h>
#include <mc_tasks/TorqueJointTask.h>
#include "api.h"

struct PIDTuningController_DLLAPI PIDTuningController : public mc_control::fsm::Controller
{
  PIDTuningController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;

  std::shared_ptr<mc_tasks::TorqueJointTask> torqueJointTask;

private:
  mc_rtc::Configuration config_;
};
