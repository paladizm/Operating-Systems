/* author: Perugini */

#include<unistd.h>
#define SIZE 1

main() {

   char buf[SIZE];
   int n;

   while ((n = read (STDIN_FILENO, buf, SIZE)) > 0)
      write (STDOUT_FILENO, buf, n);
}
