#include "iostream"
#include "./core/PidController/PidController.h"
// #include "pigpio.h"
// #include "RTIMULib.h"
// #include "string"

// #define R2D 57.2957732

int main() {
    PidControllerInput input = {};
    PidController pid = PidController(input);
    std::cout << "Created PidController" << std::endl;

    // if (gpioInitialise() < 0) {
    //     std::cout << "pigpio initialisation failed" << std::endl;
    // } else {
    //     std::cout << "pigpio initialised okay" << std::endl;
    //     gpioTerminate();
    //     std::cout << "pigpio terminated" << std::endl;
    // };

    // RTIMUSettings sensorSettings;
    // RTIMULSM6DS33LIS3MDL imu(&sensorSettings);
    // imu.IMUInit();
    // imu.setSlerpPower(0.02);
    // imu.setAccelEnable(true);
    // imu.setGyroEnable(true);
    // imu.setCompassEnable(true);
    // while (true) {
    //     usleep(imu.IMUGetPollInterval() * 1000);
    //     while(imu.IMURead()) {
    //         RTIMU_DATA imuData = imu.getIMUData();
    //         RTVector3 curr_pose = imuData.fusionPose ;
    //         printf("Roll = %g Pitch = %g Yaw = %g \n", curr_pose.x()*R2D, curr_pose.y()*R2D, curr_pose.z()*R2D );
    //         // std::cout << std::to_string(imuData.accel.x() * 9.80665) + ' ' +  std::to_string(imuData.accel.y() * 9.80665) + ' ' +  std::to_string(imuData.accel.z() * 9.80665)  << std::endl;
    //     }
    // }

    // imu.setAccelEnable(false);
    // imu.setGyroEnable(false);
    // imu.setCompassEnable(false);

    return 0;
}
