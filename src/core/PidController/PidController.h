#pragma once
#include "limits"

struct RangeLimits {
    float min, max;
};

struct PidControllerInput {
    float
        kp = 1,
        ki = 0,
        kd = 0,
        sampleTime = 0.01,
        tau = 0;
    RangeLimits 
        outputLimits = {std::numeric_limits<float>::min(), std::numeric_limits<float>::max()},
        integratorLimits = {std::numeric_limits<float>::min(), std::numeric_limits<float>::max()};
};

class PidController {
    public:
        PidController(PidControllerInput input);
        float update(float setpoint, float measurment);
    private:
        float 
            kp,
            ki,
            kd,
            sampleTime,
            tau,
            proportonal,
            integrator,
            differentiator,
            previousError,
            previousMeasurement,
            output;
        RangeLimits
            outputLimits, 
            integratorLimits;
};
