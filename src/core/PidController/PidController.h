#pragma once

struct OutputLimits {
    signed int low, high;
};

class PidController {
    public:
        PidController(
            float kp = 1,
            float ki = 0,
            float kd = 0,
            signed int setpoint = 0,
            OutputLimits outputLimits = {-1000000, 1000000}
        );
    private:
        float kp;
        float ki;
        float kd;
        signed int setpoint = 0;
        OutputLimits outputLimits;
};
