#include<stdio.h>
#include<string.h>

int main (int argc, char **argv) {

   int i, j, len;

   printf ("argc is %d\n", argc);

   for (i = 0; i < argc; i++)  {
      len = strlen (argv[i]);
      for (j = 0; j < len ; j++) 
         printf ("argv[%d][%d] is %c\n", i, j, argv[i][j]);
   }

   exit (0);
}
