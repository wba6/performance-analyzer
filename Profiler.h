/*
 * A header file for the profiler
 *
 * Author wba6
 */

#ifndef PERFORMANCE_ANALYER_PROFILER_H
#define PERFORMANCE_ANALYER_PROFILER_H

#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <thread>
#include "Timer.h"




/*
 * A struct to hold the profile result
 *
 * @param std::string Name : the name of the profile
 * @param long long Start : the start time of the profile
 * @param long long End : the end time of the profile
 * @param uint32_t ThreadID : the thread id of the profile
 */
struct ProfileResult
{
    std::string Name;
    long long Start, End;
    uint32_t ThreadID;
};

/*
 * A struct to hold the profiler session
 *
 * @param std::string Name : the name of the session
 */
struct ProfilerSession
{
    std::string Name;
};

/*
 * A class to hold the profiler
 */
class Profiler {
private:
    // the current session
    ProfilerSession* m_CurrentSession;

    // the output stream
    std::ofstream m_OutputStream;

    // the profile count
    int m_ProfileCount;
public:

    /*
     * Constructor for the profiler
     */
    Profiler();


    /*
     * Begin a session which will be written to a file upon ending
     *
     * @param std::string name : the name of the session
     * @param std::string filepath : the file path to write the session to
     *
     * @return void
     */
    void BeginSession(const std::string& name, const std::string& filepath = "results.json");


    /*
     * End the current session and write the results to the file
     *
     * @return void
     */
    void EndSession();

    /*
     * Write a profile result to the file
     *
     * @param ProfileResult result : the profile result to write
     *
     * @return void
     */
    void WriteProfile(const ProfileResult& result);


    /*
     * Write the header of the file
     *
     * @return void
     */
    void WriteHeader();

    /*
     * Write the footer of the file
     *
     * @return void
     */
    void WriteFooter();

    /*
     * Insert a custom time into the file
     *
     * @param name the name of the custom time
     * @param duration the length in ms of time to put in the output
     * @return void
     */
    void InsertCustomTime(std::string name, double duration);

    /*
     * Get the profiler instance
     *
     * @return Profiler& : the profiler instance
     */
    static Profiler& Get();
};


#endif //PERFORMANCE_ANALYER_PROFILER_H
