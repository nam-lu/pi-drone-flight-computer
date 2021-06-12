#pragma once

struct OutputLimits {
    signed int low;
    signed int high;
};

class PidController {
    public:
        PidController(
            float kp = 1.0,
            float ki = 0.0,
            float kd = 0.0,
            signed int setpoint = 0,
            OutputLimits outputLimits = {-10000, 10000}
        );
    private:
        float kp;
        float ki;
        float kd;
        signed int setpoint = 0;
        OutputLimits outputLimits;
};
