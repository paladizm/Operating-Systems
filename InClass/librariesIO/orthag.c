#include <stdio.h>
#include <string.h>

void main() {

   char *x, *y, *p, *q;

   x = "Hello";
   y = "Si";

   printf ("\nx: [%s] of length %d\n", x, strlen(x));
   printf ("y: [%s] of length %d\n", y, strlen(y));

   p = x;
   q = y;

   while ( *p++ = *q++ );

   printf ("new x: [%s] of length %d\n", x, strlen(x));
   printf ("new y: [%s] of length %d\n", y, strlen(y));
}
