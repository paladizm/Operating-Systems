#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

main() {
   char* mycwd = malloc(MAX_CANON);

   getcwd(mycwd, MAX_CANON);
   printf(":%s:\n", mycwd);

   printf(":%s:\n", getenv("PWD"));

   setenv("PWD", "/home", 1);
   printf(":%s:\n", getenv("PWD"));

   chdir("/home/cps346-01.15/");
   printf(":%s:\n", getenv("PWD"));
}
