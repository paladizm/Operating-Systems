#include<stdio.h>

/* bufferout.c */

main() {

   int i;

   /* stdout is line bufferred (flushed when full or when a newline written) */
   fprintf (stdout, "a");
   fflush(stdout);

   //scanf("%d", &i);

   /* stderr is not bufferred */
   fprintf (stderr, "a has been written\n");

   fprintf (stdout, "b");
   //fflush(stdout);
   fprintf (stderr, "b has been written\n");

   //fprintf (stdout, "\n");

   return 0;
}
