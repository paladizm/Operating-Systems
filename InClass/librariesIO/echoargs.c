#include<stdio.h>
#include<stdlib.h>

//int main (int argc, char* argv[]) {
int main (int argc, char** argv) {
   int i = 0;

   printf ("argc is %d\n", argc);

   for (; *argv; argv++)
      printf ("argv[%1d] is %s\n", i++, *argv);

   exit (0);
}
