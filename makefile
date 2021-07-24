main: main.o exponential_random_generator.o
	g++ -std=c++11 -o main main.o exponential_random_generator.o

exponential_random_generator.o: exponential_random_generator.cpp exponential_random_generator.h
	g++ -std=c++11 -c  exponential_random_generator.cpp