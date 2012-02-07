#include<stdio.h>
#include<string.h>
#include<errno.h>

main() {

   int errnobakup;

   int fildes;

   if (close(fildes) == -1) {
      errnobakup = errno; 
      perror ("Failed to close the file.");
      fprintf (stderr, "Failed to close file: %s\n", strerror(errno));
      errno = errnobakup;

   }
}
