#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

main() {

   int i;

   int* intarray = (int*) malloc (sizeof (int)*SIZE);

//   int intarray[10];

   for (i=0; i < SIZE; i++)
      intarray[i] = i+1;

   for (i=0; i< SIZE; i++)
      printf ("%d\n", intarray[i]);

   intarray = NULL;

   sleep(20);
}
