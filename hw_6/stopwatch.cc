#include "stopwatch.h"

Stopwatch::Stopwatch() : _is_running(false), _elapsed_time(0) {}

void Stopwatch::start() {
    if (!_is_running) {
        _start_time = std::chrono::high_resolution_clock::now();
        _is_running = true;
    }
}

void Stopwatch::stop() {
    if (_is_running) {
        _end_time = std::chrono::high_resolution_clock::now();
        _elapsed_time += std::chrono::duration_cast<std::chrono::nanoseconds>(_end_time - _start_time).count();
        _is_running = false;
    }
}

void Stopwatch::reset() {
    _is_running = false;
    _elapsed_time = 0;
}

double Stopwatch::get_minutes() const {
    return get_seconds() / 60.0;
}

double Stopwatch::get_seconds() const {
    return get_milliseconds() / 1000.0;
}

double Stopwatch::get_milliseconds() const {
    return get_nanoseconds() / 1e6;
}

double Stopwatch::get_nanoseconds() const {
    if (_is_running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        auto additional_time = std::chrono::duration_cast<std::chrono::nanoseconds>(current_time - _start_time).count();
        return _elapsed_time + additional_time;
    } else {
        return _elapsed_time;
    }
}
