cmake_minimum_required(VERSION 3.0.0)
project(PiDroneFlightComputer VERSION 0.1.0)

include(CTest)
enable_testing()

include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(PiDroneFlightComputer ./src/main.cpp)

# find_package(pigpio REQUIRED)
add_subdirectory(external/pigpio)
target_include_directories(PiDroneFlightComputer INTERFACE pigpio)
target_link_libraries(PiDroneFlightComputer pigpio)
