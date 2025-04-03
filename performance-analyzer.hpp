/*
 * A header include file for the analyzer 
 *
 * Author wba6
 */

#ifndef PERFORMANCE_ANALYZER_HPP
#define PERFORMANCE_ANALYZER_HPP


#include "time.h"
#include "Profiler.h"


#ifdef PROFILING_ENABLED

/*
 * A macro to get the function signature
 */
#if defined(_MSC_VER)
#define FUNCTION_SIGNATURE __FUNCSIG__
#elif defined(__GNUC__) || defined(__clang__)
#define FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#else
#define FUNCTION_SIGNATURE __func__
#endif

/*
 * A macro to create a profile scope
 *
 * @param std::string name : the name of the profile
 */
#define PROFILE_SCOPE(name) Timer timer##__LINE__(name)


/*
 * A macro to insert custom times into the resultant file
 * 
 * @param std::string, a name to use
 * @param double, microsecond time to insert will be inserted right before this line
 */
#define PROFILE_CUSTOM_TIME(name, time) Profiler::Get().InsertCustomTime(name, time) 

/*
 * A macro to create a profile function
 */
#define PROFILE_FUNCTION() PROFILE_SCOPE(FUNCTION_SIGNATURE)

#else

#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#define PROFILE_CUSTOM_TIME(name, time)

#endif

#endif // PROFILE_ANALYZER_HPP
