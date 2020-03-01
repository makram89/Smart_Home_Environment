cmake_minimum_required(VERSION 3.15)
project(Weather_Station)

set(CMAKE_CXX_STANDARD 14)

set(${CMAKE_PROJECT_NAME}_BOARD nano)
set(${CMAKE_PROJECT_NAME}_PORT COM10)

include_directories(.)
include_directories(lib/DFRobot_BMP388/examlpes/I2CReadPressure)
include_directories(lib/DFRobot_BMP388/examlpes/I2CReadTemperature)
include_directories(lib/DFRobot_BMP388/examlpes/ReadForINT)
include_directories(lib/dht)
include_directories(src)

add_executable(Weather_Station
        baro_demo/baro_demo.ino
        clock_demo/clock_demo.ino
        lib/DFRobot_BMP388/examlpes/I2CReadPressure/I2CReadPressure.ino
        lib/DFRobot_BMP388/examlpes/I2CReadTemperature/I2CReadTemperature.ino
        lib/DFRobot_BMP388/examlpes/ReadForINT/ReadForINT.ino
        lib/DFRobot_BMP388/bmp3_defs.h
        lib/DFRobot_BMP388/DFRobot_BMP388.cpp
        lib/DFRobot_BMP388/DFRobot_BMP388.h
        lib/DFRobot_BMP388/DFRobot_BMP388_I2C.cpp
        lib/DFRobot_BMP388/DFRobot_BMP388_I2C.h
        lib/dht/dht.cpp
        lib/dht/dht.h
        src/src.ino)
