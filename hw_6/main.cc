#include <iostream>
#include <chrono>
#include <thread>
#include "stopwatch.h"

#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(1500))

int main() {
    Stopwatch w;

    std::cout << "Starting the stopwatch.\n";
    w.start();
    SLEEP;
    w.stop();
    std::cout << "Elapsed time in seconds: " << w.get_seconds() << "\n";

    SLEEP;
    std::cout << "Elapsed time in seconds (no change): " << w.get_seconds() << "\n";

    w.start();
    SLEEP;
    w.stop();
    std::cout << "Total elapsed time in seconds: " << w.get_seconds() << "\n";

    w.reset();
    std::cout << "Elapsed time after reset in seconds: " << w.get_seconds() << "\n";

    return 0;
}
