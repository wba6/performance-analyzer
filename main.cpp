/*
 * An example of how to use the performance timer
 *
 * Author wba6
 */

#include <iostream>
#include "Timer.h"
int main() {

    {
        Timer timer;
        for (int i = 0; i < 2000; ++i) {
            if(i%2 == 0) {
                i += i%2;
            }
        }
    }

}
