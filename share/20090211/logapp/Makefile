CC = gcc
C_OPTS = -c

all: a.out

printings: logapp.pdf loggerlib.pdf logapplib.pdf

logapp.pdf: logapp.ps
	ps2pdf logapp.ps

logapp.ps: logapp.c
	a2ps -o logapp.ps logapp.c

a.out: logapp.o loggerlib.o logapplib.o
	$(CC) logapp.o loggerlib.o logapplib.o

logapp.o: logapp.c
	$(CC) $(C_OPTS) logapp.c

logapplib.o: logapplib.c loggerlib.h
	$(CC) $(C_OPTS) logapplib.c

loggerlib.o: loggerlib.c loggerlib.h
	$(CC) $(C_OPTS) loggerlib.c

clean:
	rm *.o a.out
