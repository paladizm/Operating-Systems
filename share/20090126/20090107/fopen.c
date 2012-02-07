/* author: Perugini */

#include<stdio.h>

main() {

   FILE* ifp = NULL;
   FILE* ofp = NULL;

   int x = 0;

   ifp = fopen ("in.dat", "r");
   ofp = fopen ("out.dat", "w");

   fscanf(ifp, "%d", &x);
   fprintf(ofp, "%d", x);
}
