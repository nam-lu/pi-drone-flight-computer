#include "iostream"
#include "PidController.h"

PidController::PidController(PidControllerInput input) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->setpoint = setpoint;
    this->outputLimits = outputLimits;
    std::cout << "Created PidController" << std::endl;
};
