/* ref. [USP] Chapter 2, Program 2.4, p. 40 */

#include <stdio.h>
#include <string.h>
#define LINE_DELIMITERS "\n"
#define WORD_DELIMITERS " \t"

static int wordcount(char* s) {
   int count = 1;
   char* lasts;

   if (strtok_r(s, WORD_DELIMITERS, &lasts) == NULL)
      return 0;
   while (strtok_r(NULL, WORD_DELIMITERS, &lasts) != NULL)
      count++;
   return count;
}

/* return average size of words in s */
double wordaverage (char* s) {
   char* lasts;
   int lc = 1;
   char* nextline;
   int wc;

   nextline = strtok_r(s, LINE_DELIMITERS, &lasts);
   if (nextline == NULL)
      return 0.0;
   wc = wordcount(nextline);
   while ((nextline = strtok_r(NULL, LINE_DELIMITERS, &lasts)) != NULL) {
      wc += wordcount(nextline);
      lc++;
   }
   fprintf(stderr, "words = %d and lines = %d.\n", wc, lc);
   return (float) wc/lc;
}
