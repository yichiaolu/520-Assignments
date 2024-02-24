#include <elma/elma.h> // https://github.com/klavinslab/elma

using namespace elma;

class Integrator : public Process {
    public:
    Integrator(std::string name) : Process(name) {}
    void init() override;
    void start() override;
    void update() override;
    void stop() override;
    double value() const;

    private:
    double _integral = 0.0;  
};
