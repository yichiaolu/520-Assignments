#include <elma/elma.h> // https://github.com/klavinslab/elma
#include <random>

using namespace elma;

class RandomProcess : public Process {
    public:
    RandomProcess(std::string name) : Process(name) {}
    void init() override;
    void start() override;
    void update() override;
    void stop() override;

    private:
    std::default_random_engine _generator;
    std::uniform_real_distribution<double> _distribution;
};
