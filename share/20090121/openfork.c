/* ref. [USP] Chapter 4, Example 4.27, p. 124 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
   char c = 'X';
   int myfd;

   if (fork() == -1) {
      perror("Failed to fork");
      return 1;
   }

   if ((myfd = open("input.txt", O_RDONLY)) == -1) {
      perror("Failed to open file");
      return 1;
   }

   read(myfd, &c, 1);
   printf("Process %ld got %c.\n", (long) getpid(), c);
   return 0;
}
