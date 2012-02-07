/* ref. [USP] Chapter 2, Example 2.23, p. 50 */

#include<stdio.h>
#include<stdlib.h>

#define MAILDEFAULT "/var/mail"

/* POSIX standard specifies that shell should use MAIL if MAILPATH not set */

main() {
   char* mailp = NULL;

   if ((mailp = getenv ("MAILPATH")) == NULL)
      if ((mailp = getenv ("MAIL")) == NULL)
         mailp = MAILDEFAULT;

   printf("%s\n", mailp);
}
