/* author: Perugini */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

// #define DEBUG 

int* intarray;

/* function called at the time main exits to make sure memory is freed */
static void freemem(void) {
   #ifdef DEBUG
      fprintf(stderr, "Totally exiting!\n");
   #endif
   free(intarray);
}

main() {

   int i;

   intarray = (int*) malloc (sizeof (int)*SIZE);

   /* int intarray[10]; */

   if (atexit(freemem)) {
      fprintf(stderr, "Unable to install freemem error handler.\n");
   }

   for (i=0; i < SIZE; i++)
      intarray[i] = i+1;

   for (i=0; i< SIZE; i++)
      printf ("%d\n", intarray[i]);

   /* free (intarray); */
}
