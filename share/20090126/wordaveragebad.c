/* ref. [USP] Chapter 2, Program 2.3, p. 39 */

#include <stdio.h>
#include <string.h>
#define LINE_DELIMITERS "\n"
#define WORD_DELIMITERS " \t" 

static int wordcount(char *s) {
   int count = 1;

   if (strtok(s, WORD_DELIMITERS) == NULL)
      return 0;

   while (strtok(NULL, WORD_DELIMITERS) != NULL)
      count++;
   return count;
}

/* return average size of words in s */
double wordaverage(char *s) {
   int lc = 1;
   char* nextline;
   int wc;

   nextline = strtok(s, LINE_DELIMITERS);
   if (nextline == NULL)
      return 0.0;
   wc = wordcount(nextline);
   while ((nextline = strtok(NULL, LINE_DELIMITERS)) != NULL) {
      wc += wordcount(nextline);
      lc++;
   }
   fprintf(stderr, "words = %d and lines = %d.\n", wc, lc);
   return (double) wc/lc;
}
