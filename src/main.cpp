#include <iostream>
#include <pigpio.h>

using namespace std;

int main() {
    cout << "Hello World" << endl;
    gpioInitialise();
    gpioSetMode(1, PI_INPUT);
    return 0;
}
