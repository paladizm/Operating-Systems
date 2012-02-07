#include<stdio.h>

main() {
   FILE* fptr = fopen ("/dev/tty", "w");

   fprintf (fptr, "Write me to the terminal.\n");
}
