CC = g++ -Wall -std=c++14 -g -O0 -pedantic-errors
PQD = PriorityQueueDr.cpp
PQ = PriorityQueue.cpp
PQH = PriorityQueue.h

all: BankSimulation

BankSimulation: PriorityQueue.o BankSimulation.o Customer.o QueType.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o BankSimulation PriorityQueue.o BankSimulation.o
PriorityQueue.o: PriorityQueue.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c PriorityQueue.cpp
BankSimulation.o: BankSimulation.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c BankSimulation.cpp
Customer.o: Customer.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Customer.cpp
QueType.o: QueType.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c QueType.cpp
clean: 
	rm -f BankSimulation
	rm -f BankSimulation.o
	rm -f PriorityQueue.o
	rm -f PriorityQueueDr.o
	rm -f Customer.o
	rm -f QueType.o