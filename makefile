main: main.o exponential_random_generator.o simulation.o event.o customer.o
	g++ -std=c++11 -o main main.o exponential_random_generator.o simulation.o event.o customer.o



exponential_random_generator.o: exponential_random_generator.cpp exponential_random_generator.h
	g++ -std=c++11 -c  exponential_random_generator.cpp

customer.o: customer.h customer.cpp
	g++ -std=c++11 -c  customer.cpp

event.o: event.h event.cpp
	g++ -std=c++11 -c  event.cpp

simulation.o: simulation.h simulation.cpp customer.h event.h exponential_random_generator.h
	g++ -std=c++11 -c  simulation.cpp