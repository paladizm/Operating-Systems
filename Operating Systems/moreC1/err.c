#include<errno.h>
#include<stdio.h>

main() {

   FILE* in = NULL;

   if (fopen ("newfile", "r") == NULL)
      /* errno */
      /* equivalent to, but simplier than
         fprintf (stderr, "%s: %s\n", s, "error message") 
       */
      perror ("not found");
}

