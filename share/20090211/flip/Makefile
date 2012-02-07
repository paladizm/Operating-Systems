all: flip.o getopt.o flip.man
	gcc  -o flip.o getopt.o


flip.man: flip.1
	nroff -man flip.1 > flip.man


flip.o: flip.c flip.h
	gcc -DBSD -DNDEBUG -O -c flip.c


getopt.o: getopt.c flip.h
	gcc -DBSD -DNDEBUG -O -c getopt.c

clean:
	rm *.o flip
