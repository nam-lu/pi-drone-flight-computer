#include "iostream"
#include "PidController.h"

PidController::PidController(float kp, float ki, float kd, signed int setpoint, OutputLimits outputLimits) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->setpoint = setpoint;
    this->outputLimits = outputLimits;
    std::cout << "Created PidController" << std::endl;
};
