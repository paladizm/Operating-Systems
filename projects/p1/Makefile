CC = gcc
C_OPTS = -c

all: a.out

a.out: myshell.o utils.o builtin.o makeargv.o 
	$(CC) myshell.o utils.o builtin.o makeargv.o 

myshell.o: myshell.c utils.h builtin.h makeargv.h 
	$(CC) $(C_OPTS) myshell.c

utils.o: utils.c utils.h makeargv.h 
	$(CC) $(C_OPTS) utils.c

builtin.o: builtin.c builtin.h
	$(CC) $(C_OPTS) builtin.c

makeargv.o: makeargv.c makeargv.h
	$(CC) $(C_OPTS) makeargv.c

clean:
	@-rm *.o a.out

