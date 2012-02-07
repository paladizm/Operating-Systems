#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

main() {

   int i;
   int* intarray = (int*) calloc (SIZE, sizeof (int));

   for (i=0; i < SIZE; i++)
      intarray[i] = i+1;

   for (i=0; i< SIZE; i++)
      printf ("%d\n", intarray[i]);

   printf ("\n");

   realloc (intarray, sizeof (int)*(SIZE+SIZE));

   for (i=SIZE; i < (SIZE+SIZE); i++)
      intarray[i] = i+1;

   for (i=0; i< (SIZE+SIZE); i++)
      printf ("%d\n", intarray[i]);
}
