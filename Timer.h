/*
 * A header file for a timer to keep track of the time passed
 *
 * Author wba6
 */

#ifndef PERFORMANCE_ANALYER_TIMER_H
#define PERFORMANCE_ANALYER_TIMER_H

/*
 * A timer class to keep track of the time passed between two events
 */
class Timer {
public:

    /*
     * Constructor for the Timer class
     *
     * @param None
     * @return void
     */
    Timer();

    /*
     * Destructor for the Timer class
     *
     * @param None
     * @return void
     */
    ~Timer();

    /*
     * Start the timer
     *
     * @param None
     * @return void
     */
    void start();

    /*
     * Stop the timer
     *
     * @param None
     * @return void
     */
    void stop();
private:

};


#endif //PERFORMANCE_ANALYER_TIMER_H
