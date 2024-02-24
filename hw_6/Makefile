CXX = g++ -std=c++14
CXXFLAGS = -g -Wall
LDFLAGS = -pthread
ELMA_PATH = /path/to/elma
GTEST_PATH = /path/to/gtest
ELMA_LIB = -L$(ELMA_PATH)/lib -lelma
GTEST_LIB = -L$(GTEST_PATH)/lib -lgtest -lgtest_main

# For building the main program
main: main.o stopwatch.o filter.o integrator.o random_process.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(ELMA_LIB)

# For building and running the unit tests
test: unit_tests.o stopwatch.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(GTEST_LIB)
	./test

%.o: %.cc
	$(CXX) $(CXXFLAGS) -I$(ELMA_PATH)/include -I$(GTEST_PATH)/include -c $<

clean:
	rm -f *.o main test
