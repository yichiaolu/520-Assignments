#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    Stopwatch();

    void start();
    void stop();
    void reset();

    double get_minutes() const;
    double get_seconds() const;
    double get_milliseconds() const;
    double get_nanoseconds() const;

private:
    std::chrono::high_resolution_clock::time_point _start_time;
    std::chrono::high_resolution_clock::time_point _end_time;
    bool _is_running;
    long long _elapsed_time; // Accumulated time in nanoseconds
};

#endif // STOPWATCH_H
