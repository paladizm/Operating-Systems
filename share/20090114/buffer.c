/* ref. [USP] Chapter 4, Exercises 4.25 and 4.26, p. 123-124 */

#include<stdio.h>

/* full buffering vs. line buffering vs. no buffering */

/* disk files are fully buffered */
/* terminal I/O is line buffered (newline or full, whichever comes first */
/* standard error, by default, is not bufferred */

/* buffer is flushed with fflush() or close() or scanf() */
/* setvbuf will disable buffering */

main() {

   int i;

   /* stdout is line bufferred (flushed when full or when a newline written) */
   //setvbuf(stdout, NULL, _IONBF, 0);
   fprintf (stdout, "a");
   //fprintf (stdout, "a\n");
   //fflush(stdout);

   //scanf("%d", &i);

   /* stderr is not bufferred */
   fprintf (stderr, "a has been written\n");

   fprintf (stdout, "b");
   //fflush(stdout);
   fprintf (stderr, "b has been written\n");

   //fprintf (stdout, "\n");

   return 0;
}
