CC = g++
CFLAGS = -std=c++14
LDFLAGS = -lgtest -lpthread

all: unit_tests

unit_tests: unit_tests.c dynamic_array.c main.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/dynamic_array.o dynamic_array.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/unit_tests.o unit_tests.c
	$(CC) $(CFLAGS) -g -I. -c -o ./build/main.o main.c
	$(CC) $(CFLAGS) -o test ./build/dynamic_array.o ./build/unit_tests.o ./build/main.o dynamic_array.h $(LDFLAGS)
	
clean:
	rm -f unit_tests
