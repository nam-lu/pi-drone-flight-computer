#include "RTIMULib.h"

class ImuSensor {
    public:
        ImuSensor();
        void update();
    private:
        RTIMUSettings* sensorSettings;
        RTIMULSM6DS33LIS3MDL* imu;
        void initializeSettings();
};
