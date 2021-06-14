#include "iostream"
#include "./core/PidController/PidController.h"

int main() {
    PidControllerInput input = {};
    PidController pid = PidController(input);
    std::cout << "Created PidController" << std::endl;
    return 0;
}
