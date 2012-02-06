#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

main (int argc, char** argv) {
   printf("%s\n", argv[1]);
   /* does a fork, wait, exec in the parent */
   system(argv[1]);
}
