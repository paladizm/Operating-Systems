/* author: Perugini */

#include <stdio.h>
#include <malloc.h>

main (int argc, char** argv) {
   int i;

   int bufsize = atoi (argv[1]);
   char* c = (char*) malloc (bufsize*sizeof (char));

   while ((i = fread (c, 1, bufsize, stdin)) > 0)
     fwrite (c, 1, i, stdout);
}
