cmake_minimum_required(VERSION 3.30)
project(performance_analyer)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(PROFILING_ENABLED)

add_executable(performance_analyer main.cpp
        Timer.cpp
        Timer.h
        Profiler.cpp
        Profiler.h)

