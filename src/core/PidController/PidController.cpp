#include "PidController.h"

PidController::PidController(PidControllerInput input) {
    this->kp = input.kp;
    this->ki = input.ki;
    this->kd = input.kd;
    this->sampleTime = input.sampleTime;
    this->setpoint = input.setpoint;
    this->outputLimits = input.outputLimits;
    this->integratorLimits = input.integratorLimits;
    this->tau = input.tau;
    this->proportonal = 0;
    this->integrator = 0;
    this->differentiator = 0;
    this->previousError = 0;
    this->previousMeasurement = 0;
    this->output = 0;
};

float PidController::update(float measurment) {
    // Calculate error
    float error = this->setpoint - measurment;

    // Calculate proportional term on error
    this->proportonal = this->kp * error;

    // Calculate intergrator term on error
    this->integrator = this->integrator + (0.5f * this->ki * this->sampleTime * (error + this->previousError));

    // Integrator clamping to prevent anti-windup
    if (this->integrator > this->integratorLimits.max) {
        this->integrator = this->integratorLimits.max;
    } else if (this->integrator < this->integratorLimits.min) {
        this->integrator = this->integratorLimits.min;
    };

    // Calculate differentiator term on measurment
    this->differentiator = -(2.0f * this->kd * (measurment - this->previousMeasurement)
                            + (2.0f * this->tau - this->sampleTime) * this->differentiator) 
                            / (2.0f * this->tau + this->sampleTime);
    
    // Calculate output value
    this->output = this->proportonal + this->integrator + this->differentiator;

    if (this->output > this->outputLimits.max) {
        this->output = this->outputLimits.max;
    } else if (this->output < this->outputLimits.min) {
        this->output = this->outputLimits.min;
    }

    // Keep track on previous values
    this->previousError = error;
    this->previousMeasurement = measurment;

    return this->output;
};
