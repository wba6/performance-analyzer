/*
 * An example of how to use the performance timer
 *
 * Author wba6
 */

#include <iostream>
#include "Timer.h"
#include "Profiler.h"

/*
 * A function to show an example of how to use the performance timer
 *
 * @param None
 * @return void
 */
void function() {
    PROFILE_FUNCTION();
    for (int i = 0; i < 2000000000; ++i) {
        if(i%2 == 0) {
            i += i%2;
        }
    }
}

/*
 * A function to show an example of how to use the performance timer
 *
 * @param None
 * @return void
 */
void functitgsgson2() {
    PROFILE_FUNCTION();
    for (int i = 0; i < 2000000; ++i) {
        std::cout << i << std::endl;
    }
}


/*
 * Main function
 *
 * @param None
 * @return 0
 */
int main() {
    Profiler::Get().BeginSession("Profile", "results.json");
    function();
    functitgsgson2();
    Profiler::Get().EndSession();
    return 0;
}
