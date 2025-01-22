cmake_minimum_required(VERSION 3.30)
project(performance_analyzer)

# Provide an option to build as a library instead of an executable.
option(BUILD_AS_LIBRARY "Build performance_analyzer as a static library" OFF)

set(CMAKE_CXX_STANDARD 17)

if(BUILD_AS_LIBRARY)
    # If building as a library, do *not* define PROFILING_ENABLED
    add_library(performance_analyzer STATIC
            Timer.cpp
            Timer.h
            Profiler.cpp
            Profiler.h
    )
else()
    # If building as an executable, define PROFILING_ENABLED
    add_compile_definitions(PROFILING_ENABLED)

    add_executable(performance_analyzer
            main.cpp
            Timer.cpp
            Timer.h
            Profiler.cpp
            Profiler.h
    )
endif()
