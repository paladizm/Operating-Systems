#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main() {

   char* s1 = malloc(25);
   char* substr = NULL;

   s1 = "This is our search string.";

   printf("%s\n", s1);

   substr = strstr (s1, "our");
   printf("%s\n", substr);

   substr = strchr (s1, 'r');
   printf("%s\n", substr);
}
