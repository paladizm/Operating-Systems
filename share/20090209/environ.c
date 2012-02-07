/* ref. [USP] Chapter 2, Example 2.22, p. 49 */

/* outputs the contents of its environment list */
#include<stdio.h>

extern char** environ;

int main() {

   int i;

   printf ("The environment list follows:\n");

   for (i=0; environ[i] != NULL; i++)
      printf ("environ[%d]: %s\n", i, environ[i]);

   return 0;
}
