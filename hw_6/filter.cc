#include "filter.h"

void Filter::init() {}

void Filter::start() {
    _values.clear();
    _running_average = 0.0;
}

void Filter::update() {
    if ( channel("link").nonempty() ) {
        double newValue = channel("link").latest();
        _values.push_back(newValue);

        if (_values.size() > 10) {
            _values.pop_front();
        }
        _running_average = std::accumulate(_values.begin(), _values.end(), 0.0) / _values.size();
    }
}

void Filter::stop() {}

double Filter::value() const {
    return _running_average;
}
