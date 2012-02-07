/* ref. [USP] Chapter 4, Exercise 4.33, p. 128 */

#include <stdio.h>
#include <unistd.h>

main() {
   printf("Print this.");
   //printf("Print this.\n");
   //fprintf(stderr, "Print this.");
   //fflush(stdout);
   //scanf();
   //close(STDOUT_FILENO);
   fork();
}
