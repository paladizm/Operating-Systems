/* author: Perugini */

#include <stdio.h>
#define SIZE 1

main() {

   char c[SIZE];

   while ((fread (c, 1, SIZE, stdin)) > 0)
      fwrite (c, 1, SIZE, stdout);
}
