#include "random_process.h"
#include <iostream>
void RandomProcess::init() {
   
    _distribution = std::uniform_real_distribution<double>(0.0, 1.0);
}

void RandomProcess::start() {}

void RandomProcess::update() {
   
    double randomNumber = _distribution(_generator);

    channel("link").send(randomNumber);

    std::cout << "RandomProcess sent: " << randomNumber << std::endl; // 
}

void RandomProcess::stop() {}

