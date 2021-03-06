cmake_minimum_required(VERSION 3.8)
project(Vliegveld)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)


include_directories(gtest/include)
link_directories(gtest/lib)

set(RELEASE_SOURCE_FILES Airplane.cpp
        Airplane.h
        Airport.cpp
        Airport.h
        main.cpp
        Runway.cpp
        Runway.h
        tinystr.cpp
        tinystr.h
        tinyxml.cpp
        tinyxml.h
        tinyxmlerror.cpp
        tinyxmlparser.cpp
        Simulation.cpp
        Simulation.h
        parser.cpp
        parser.h
        output.cpp
        output.h
        Time.cpp
        Time.h)

set(DEBUG_SOURCE_FILES Airplane.cpp
        Airplane.h
        Airport.cpp
        Airport.h
        Runway.cpp
        Runway.h
        tinystr.cpp
        tinystr.h
        tinyxml.cpp
        tinyxml.h
        tinyxmlerror.cpp
        tinyxmlparser.cpp
        mainTest.cpp
        Simulation.cpp
        Simulation.h
        parser.cpp
        parser.h
        output.cpp
        output.h
        Time.cpp
        Time.h
        AirplaneTest.cpp
        AirportTest.cpp outputTest.cpp RunwayTest.cpp parserTest.cpp TimeTest.cpp SimulationTest.cpp)

add_executable(Vliegveld ${RELEASE_SOURCE_FILES})
add_executable(Vliegveld_debug ${DEBUG_SOURCE_FILES})
target_link_libraries(Vliegveld_debug gtest)