/* author: Perugini */

#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

main (int argc, char **argv) {
   int i;

   int bufsize = atoi (argv[1]);
   char* c = malloc (bufsize*sizeof (char));

   while ((i = read (STDIN_FILENO, c, bufsize)) > 0)
     write (STDOUT_FILENO, c, i);
}
