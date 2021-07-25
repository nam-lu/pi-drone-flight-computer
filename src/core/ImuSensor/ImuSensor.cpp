#include "ImuSensor.h"
#include "string"

#define RAD_TO_DEG 57.2957732

ImuSensor::ImuSensor() {
    this->sensorSettings = &RTIMUSettings();
    this->initializeSettings();
    this->imu = &RTIMULSM6DS33LIS3MDL(this->sensorSettings);
    RTIMULSM6DS33LIS3MDL imu = *this->imu;
    imu.IMUInit();
    imu.setAccelEnable(true);
    imu.setGyroEnable(true);
    imu.setCompassEnable(true);
    while (true) {
        usleep(imu.IMUGetPollInterval() * 1000);
        while(imu.IMURead()) {
            RTIMU_DATA imuData = imu.getIMUData();
            RTVector3 curr_pose = imuData.fusionPose ;
            printf("Roll = %g Pitch = %g Yaw = %g \n", curr_pose.x()*RAD_TO_DEG, curr_pose.y()*RAD_TO_DEG, curr_pose.z()*RAD_TO_DEG );
            // std::cout << std::to_string(imuData.accel.x() * 9.80665) + ' ' +  std::to_string(imuData.accel.y() * 9.80665) + ' ' +  std::to_string(imuData.accel.z() * 9.80665)  << std::endl;
        }
    }
};

void ImuSensor::initializeSettings() {
    this->sensorSettings->loadSettings();
    this->sensorSettings->m_axisRotation = RTIMU_XNORTH_YWEST;
}

void ImuSensor::update() {}

ImuSensor::~ImuSensor() {
    RTIMULSM6DS33LIS3MDL imu = *this->imu;
    imu.setAccelEnable(false);
    imu.setGyroEnable(false);
    imu.setCompassEnable(false);
};
