/* ref. [USP] Chapter 3, Example 3.5, p. 65 */

#include <stdio.h>
#include <unistd.h>

int main() {
   int x;

   x = 0;
   fork();
   x = 1;
   fprintf (stderr, "I am process %ld and my parent is %ld.\n", (long) getpid(),
           (long)getppid());
   return 0;
}
