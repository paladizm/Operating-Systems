#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv) {

   printf ("argc is %d\n", argc);

   for (; *argv; argv++) 
      printf ("Next argument is %s\n", *argv);

   exit (0);
}
