cmake_minimum_required(VERSION 3.0.0)
project(PiDroneFlightComputer VERSION 0.1.0)

include(CTest)
enable_testing()

include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

add_executable(PiDroneFlightComputer ./src/main.cpp ${SOURCES})

include_directories(/usr/include)
include_directories(/usr/local/include)
include_directories(${PROJECT_SOURCE_DIR}/external/pigpio)
include_directories(${PROJECT_SOURCE_DIR}/external/RTIMULib2/RTIMULib)

target_link_libraries(PiDroneFlightComputer pigpio)
target_link_libraries(PiDroneFlightComputer /usr/local/lib/libRTIMULib.so)
