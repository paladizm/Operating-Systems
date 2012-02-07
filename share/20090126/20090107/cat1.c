/* ref. [CPL] Chapter 7, 7.5, p. 162 */

#include<stdio.h>

/* cat: version 1 */
void filecopy (FILE* ifp, FILE* ofp) {
   char c;

   while ((c = getc (ifp)) != EOF)
      putc (c, ofp);
}

int main (int argc, char** argv) {

   FILE* fp = NULL;

   if (argc == 1)
      filecopy (stdin, stdout);
   else
      while (--argc > 0)
         if ((fp = fopen (*(++argv), "r")) == NULL) {
             printf ("cat: file not found!\n");
             return 1;
         } else {
             filecopy (fp, stdout);
             fclose (fp);
           }

   return 0;
}
