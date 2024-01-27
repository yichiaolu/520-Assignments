CC = g++
CFLAGS = -std=c++14
LDFLAGS = -lgtest -lpthread

all: unit_tests

unit_tests: unit_tests.c solutions.c main.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/solutions.o solutions.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/unit_tests.o unit_tests.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/main.o main.c
	$(CC) $(CFLAGS) -o test ./build/solutions.o ./build/unit_tests.o ./build/main.o solutions.h $(LDFLAGS)
	
clean:
	rm -f unit_tests
