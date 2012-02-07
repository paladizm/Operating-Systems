CC = g++
C_OPTS = -c

all: a.out

a.out: simulator.o CPU.o IO.o Job.o Output.o Semephore.o Functions.o
	$(CC) simulator.o CPU.o IO.o Job.o Output.o Semephore.o Functions.o

simulator.o: simulator.cpp CPU.h Job.h IO.h Output.h Semephore.h Functions.h
	$(CC) $(C_OPTS) simulator.cpp

CPU.o: CPU.cpp CPU.h Functions.h
	$(CC) $(C_OPTS) CPU.cpp

IO.o: IO.cpp IO.h Functions.h
	$(CC) $(C_OPTS) IO.cpp

Job.o: Job.cpp Job.h Functions.h
	$(CC) $(C_OPTS) Job.cpp
	
Output.o: Output.cpp Output.h Functions.h
	$(CC) $(C_OPTS) Output.cpp

Semephore.o: Semephore.cpp Semephore.h Functions.h
	$(CC) $(C_OPTS) Semephore.cpp

Functions.o: Functions.cpp Functions.h
	$(CC) $(C_OPTS) Functions.cpp

clean:
	@-rm *.o a.out
