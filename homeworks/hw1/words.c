//Zac Paladino
//Assignment 1
//01/20/2009
//CPS 346
//words.c
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv) {
   char c,p=' ';
   float words=0, lines=0;
   float wpl;
   int count = 0;
  
   while((c=getchar())!=EOF){
	if(c=='\t' || c==' ' || c=='\n') {
          if(c=='\n' && (p!= '\n' && p!= '\t' && p!=' ') && count > 0){
            words++;
	    lines++;
           }
          else if(c=='\t' && (p!=' ' && p!='\t' && p!= '\n') && count > 0){
	    words++; 	  
          }
          else if(c==' ' && (p!=' ' && p!='\t' && p!='\n') && count > 0){
            words++;
	  }
        }
       p = c;
       count++;
   }

   if(p!='\t' && p!=' ' && p!='\n') {
     words++;
     lines++;
   } 
   wpl = words/lines;
   printf("%.0f %.2f \n", words, wpl);
   return 0;
}



