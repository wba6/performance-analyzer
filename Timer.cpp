/*
 * A source file for a timer to keep track of the time passed
 *
 * Author wba6
 */

#include <iostream>
#include "Timer.h"

/*
 * Constructor for the Timer class
 *
 * @param None
 * @return void
 */
Timer::Timer() {
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
    m_timeSpan = end - start;

    // Convert to milliseconds
    m_timeSpan *= 0.001;

    std::cout << "Time passed: " << m_timeSpan << " seconds" << std::endl;
}
