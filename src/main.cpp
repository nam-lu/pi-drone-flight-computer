#include "iostream"
#include "./core/PidController/PidController.h"

int main() {
    PidControllerInput input = {};
    PidController pid = PidController(input);
    return 0;
}
