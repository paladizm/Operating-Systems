/* author: Perugini */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

main() {

   int i;
   //int* intarray = (int*) calloc (SIZE, sizeof (int));
   int* intarray = (int*) malloc (SIZE*sizeof (int));

   for (i=0; i < SIZE; i++)
      intarray[i] = i+1;

   for (i=0; i< SIZE; i++)
      fprintf (stderr, "%d\n", intarray[i]);

   fprintf (stderr, "\n");

   realloc (intarray, sizeof (int)*(SIZE+SIZE));

   for (i=SIZE; i < (SIZE+SIZE); i++)
      intarray[i] = i+1;

   for (i=0; i< (SIZE+SIZE); i++)
      fprintf (stderr, "%d\n", intarray[i]);
}
