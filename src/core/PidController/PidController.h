#pragma once

struct OutputLimits {
    signed int low, high;
};

struct PidControllerInput {
    float kp = 1, ki = 0, kd = 0;
    signed int setpoint = 0;
    OutputLimits outputLimits = {-1000000, 1000000};
};

class PidController {
    public:
        PidController(PidControllerInput input);
    private:
        float kp;
        float ki;
        float kd;
        signed int setpoint = 0;
        OutputLimits outputLimits;
};
