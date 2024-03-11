TARGET := bin/enviro

all: main
	$(MAKE) -C src all

main: main.cc
	g++ -o main main.cc -std=c++11


clean:
	$(MAKE) -C src clean

