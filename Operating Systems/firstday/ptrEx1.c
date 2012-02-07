#include<stdio.h>

struct part {
    int partNumber;
    char partName[25];
};

typedef struct part Part;

main() {

   Part a;
   struct part b[10];
   struct part* ptr;

   scanf ("%d", &a.partNumber);
   scanf ("%s", &a.partName);

   b[3] = a;

   //printf ("%d", b[3].partNumber);

   //a.partName[0] = 'a';

   b[3].partNumber = a.partNumber;
   //b[3].partName = a.partName;

   ptr = b;

   printf ("%d", (ptr+3)->partNumber);
   printf ("%s", (ptr+3)->partName);
   //printf ("%d", (ptr+(sizeof(Part)*3))->partNumber);
   //printf ("%s", (ptr+(sizeof(Part)*3))->partName);
}
