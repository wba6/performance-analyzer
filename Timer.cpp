/*
 * A source file for a timer to keep track of the time passed
 *
 * Author wba6
 */

#include <iostream>
#include "Timer.h"
#include "Profiler.h"

/*
 * Constructor for the Timer class
 *
 * @param std::string name : the name of the timer
 * @return void
 */
Timer::Timer(std::string name)
            : m_name(name) {
    start();
}

/*
 * Destructor for the Timer class
 *
 * @param None
 * @return void
 */
Timer::~Timer() {
    stop();
}

/*
 * Start the timer
 *
 * @param None
 * @return void
 */
void Timer::start() {
    // Get the start time
    m_startTime = std::chrono::high_resolution_clock::now();
}

/*
 * Stop the timer
 *
 * @param None
 * @return void
 */
void Timer::stop() {
    // Get the end time
    m_endTime = std::chrono::high_resolution_clock::now();

    // Get the start and end time in microseconds
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTime).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endTime).time_since_epoch().count();

    // Calculate the time passed
    auto duration = end - start;

    // Convert to milliseconds
    double ms = duration * 0.001;

    Profiler::Get().WriteProfile({ m_name, start, end, 0 });
}
