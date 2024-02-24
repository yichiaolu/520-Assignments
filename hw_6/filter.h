#include <elma/elma.h> // https://github.com/klavinslab/elma
#include <deque>

using namespace elma;

class Filter : public Process {
    public:
    Filter(std::string name) : Process(name) {}
    void init() override;
    void start() override;
    void update() override;
    void stop() override;
    double value() const;

    private:
    std::deque<double> _values; 
    double _running_average = 0.0;
};
