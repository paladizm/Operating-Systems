#include<stdio.h>

/* full buffering vs. line buffering vs. no buffering */

/* disk files are fully buffered */
/* terminal I/O is line buffered (newline or full, whichever comes first */
/* standard error, by default, is not bufferred */

/* buffer is flushed with fflush() or close() or scanf() */
/* setvbuf will disable buffering */

int main() {

   setvbuf(stdout, NULL, _IONBF, 0);
   fprintf (stdout, "a");
   fprintf (stderr, "a has been written\n");
   fprintf (stdout, "b");
   fprintf (stderr, "b has been written\n");
//   fprintf (stdout, "\n");
   return 0;
}
