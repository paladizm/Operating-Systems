/* author: Perugini */

#include<stdio.h>
#include<string.h>

main() {

   double number1 = 7.3, number2;

   char* ptr = NULL;

   char s1[100], s2[100];

   double* dPtr = NULL;

   dPtr = &number1;
   
   printf ("%f\n", *dPtr);

   number2 = *dPtr;

   printf ("%f\n", number2);

   printf ("%x\n", &number1);
   printf ("%x\n", dPtr);

   strcpy (s1,s2);

   printf ("%d\n", strcmp (s1,s2));
   strcat (s1,s2);
   printf ("%d\n", strlen(s1));
}
