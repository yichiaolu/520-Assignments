#include "integrator.h"

void Integrator::init() {}

void Integrator::start() {
    _integral = 0.0;
}

void Integrator::update() {
    if ( channel("link").nonempty() ) {
        double inputValue = channel("link").latest();
        _integral += inputValue * delta();
    }
}

void Integrator::stop() {}

double Integrator::value() const {
    return _integral;  
}
