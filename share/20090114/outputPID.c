/* ref. [USP] Chapter 3, Example 3.1, p. 60 */

#include <stdio.h>
#include <unistd.h>

int main() {
   printf ("I am process %ld.\n", (long) getpid());
   printf ("My parent is %ld.\n", (long) getppid());
   return 0;
}
