/*
 * A source file for the profiler
 *
 * Author wba6
 */

#include "Profiler.h"
#include <ratio>

/*
 * Begin a session which will be written to a file upon ending
 *
 * @param std::string name : the name of the session
 * @param std::string filepath : the file path to write the session to
 *
 * @return void
 */
void Profiler::BeginSession(const std::string &name, const std::string &filepath) {
        m_OutputStream.open(filepath);
        WriteHeader();
        m_CurrentSession = new ProfilerSession{ name };
}

/*
 * End the current session and write the results to the file
 *
 * @return void
 */
void Profiler::EndSession() {
    WriteFooter();
    m_OutputStream.close();
    delete m_CurrentSession;
    m_CurrentSession = nullptr;
    m_ProfileCount = 0;
}

/*
 * Write a profile result to the file
 *
 * @param ProfileResult result : the profile result to write
 *
 * @return void
 */
void Profiler::WriteProfile(const ProfileResult &result) {
    if (m_ProfileCount++ > 0)
        m_OutputStream << ",";

    std::string name = result.Name;
    std::replace(name.begin(), name.end(), '"', '\'');

    m_OutputStream << "{";
    m_OutputStream << R"("cat":"function",)";
    m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
    m_OutputStream << R"("name":")" << name << "\",";
    m_OutputStream << R"("ph":"X",)";
    m_OutputStream << "\"pid\":0,";
    m_OutputStream << "\"tid\":" << result.ThreadID << ",";
    m_OutputStream << "\"ts\":" << result.Start;
    m_OutputStream << "}";

    m_OutputStream.flush();
}

/*
 * Write the header of the file
 *
 * @return void
 */
void Profiler::WriteHeader() {
    m_OutputStream << R"({"otherData": {},"traceEvents":[)";
    m_OutputStream.flush();
}

/*
 * Write the footer of the file
 *
 * @return void
 */
void Profiler::WriteFooter() {
    m_OutputStream << "]}";
    m_OutputStream.flush();
}

/*
 * Insert a custom time into the file
 *
 * @param name the name of the custom time
 * @param duration the length in ns of time to put in the output
 * @return void
 */
void Profiler::InsertCustomTime(std::string name, double duration) {
    // Get the end time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto time_length = std::chrono::duration<double, std::micro>(duration);

    auto startTime = endTime - time_length;

    // Get the start and end time in microseconds
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

    WriteProfile({ name, start, end, 0 });
}

/*
 * Get the profiler instance
 *
 * @return Profiler& : the profiler instance
 */
Profiler &Profiler::Get() {
    static Profiler instance;
    return instance;
}

/*
 * Constructor for the profiler
 */
Profiler::Profiler()
    : m_CurrentSession(nullptr), m_ProfileCount(0){}



