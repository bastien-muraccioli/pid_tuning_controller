#include "PIDTuningController_Initial.h"

#include "../PIDTuningController.h"

void PIDTuningController_Initial::configure(const mc_rtc::Configuration & config) {}

void PIDTuningController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PIDTuningController &>(ctl_);
  // Enable feedback from external forces estimator
  if (!ctl.datastore().call<bool>("EF_Estimator::isActive")) {
    ctl.datastore().call("EF_Estimator::toggleActive");
  }
}

bool PIDTuningController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PIDTuningController &>(ctl_);
  return false;
}

void PIDTuningController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PIDTuningController &>(ctl_);
}

EXPORT_SINGLE_STATE("PIDTuningController_Initial", PIDTuningController_Initial)
