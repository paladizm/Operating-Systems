#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifndef MAX_CANON
/* #define LINELEN 256 */
#define MAX_CANON 8192
#endif

/* traverse.c */
int main() {

   char line[MAX_CANON+1];
   char* p = NULL;

   /* same as p = &line[0], right? */
   p = line;

   /* notice the parentheses */   
   while ((*p++ = getchar()) != '\n');

   *p = '\0';

   /* why can't we just print p? */
   printf ("%20s\n", line);

   exit (EXIT_SUCCESS);
}
