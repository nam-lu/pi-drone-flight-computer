#include "iostream"
#include "./core/PidController/PidController.h"
// #include "pigpio.h"

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

    return 0;
}
