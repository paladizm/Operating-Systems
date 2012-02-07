/*******************************************************************************
/
/      filename:  wc.c
/
/   description:  This program is to mimic the wc program with the 
/                  -lwc options.
/
/        author:  Paladino, Zac 
/      login id:  cps444-01.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  Homework #2
/
/      assigned:  January 21, 2009
/           due:  January 28, 2009
/
/******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void wordCounts(bool w, bool L, bool b, int words, int ch, int lines, FILE* ifs,
	int *tl, int *tc, int *tw)
{
    char c, p=' ';
    int count = 0;
    while((c=getc(ifs))!=EOF){
       ch++;
	   (*tc)++;
       if(c=='\n'){
          if (p!=' ' && p!='\t' && p!= '\n'){
             words++;
             (*tw)++; 
          }
          lines++;
          (*tl)++;
       }
       else if(c=='\t' && (p!=' ' && p!='\t' && p!= '\n')){
          words++;
          (*tw)++;
       }
       else if(c==' ' && (p!=' ' && p!='\t' && p!='\n')){
          words++;
          (*tw)++;
       }
       p = c;
   }
   if(p!=' ' && p!='\t' && p!='\n'){
      words++;
      (*tw)++;
   }
   if(L){
      fprintf(stdout, "\t%d ", lines );
   }
   if(w){
      fprintf(stdout, "\t%d ", words );
   }
   if(b){
      fprintf(stdout, "\t%d ", ch);
   }
   if(!L && !w && !b){
      fprintf(stdout,"\t %d \t %d \t %d ", lines, words, ch);
   }
}


int main (int argc, char** argv) {
   char c,p=' ';
   int words=0, lines=0;
   int tl=0,tc=0,tw=0;
   int  count = 0,k, j, len, ch = 0;
   bool L=false,w=false,b=false;
   FILE* ifs;
   if(argc>=1){
     for(k = 1;(k< argc); k++){
        len = strlen (argv[k]);
        if(argv[k][0]=='-'){
           for (j = 1; j < len ; j++){
              if(argv[k][j]=='l'){
                 L = true;
              }
              else if(argv[k][j]=='w'){
                 w = true;
              }
              else if(argv[k][j]=='c'){
                 b = true;
              }
              else{
                fprintf(stderr, "wc: invalid option -- %c \n", argv[k][j]);
                fprintf(stderr, "Try 'wc --help' for more information. \n", argv[k][j]);
                return 1;
              }  
            }
        }
        else{
           if(fopen(argv[k],"r")!= NULL){
              ifs = fopen(argv[k],"r");
              wordCounts(w,L,b,words,ch,lines,ifs,&tl,&tc,&tw);
              fprintf(stdout, "%s \n", argv[k]);
              count++;
           }
           else{
              fprintf(stderr, "wc: %s: No Such File or Directory. \n", argv[k]);
              return 1;
           }
        }
     }
     if(count==0){
      wordCounts(w,L,b,words,ch,lines,stdin,&tl,&tc,&tw);
      fprintf(stdout, "\n" );
     }
   }
   else{
      wordCounts(w,L,b,words,ch,lines,stdin,&tl,&tc,&tw);
      fprintf(stdout, "\n" );
   }
   if(count > 1){
     if(L){
        fprintf(stdout, "\t%d ", tl);
     }
     if(w){
        fprintf(stdout, "\t%d ", tw);
     }
     if(b){
        fprintf(stdout, "\t%d ",tc);
     }
     if(!b && !w && !L){
        fprintf(stdout, "\t%d \t%d \t%d ", tl, tw, tc);
     }
     fprintf(stdout, " total \n" );
   }
   return 0;
}
