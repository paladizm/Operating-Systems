/*******************************************************************************
/
/      filename:  builtins.c
/
/   description:  Implements Unix builtin commands environ, cd, pause, and echo.
/
/        author:  Paladino, Zac
/      login id:  cps346-n1.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  PJ #1 
/
/      assigned:  January 28, 2009
/           due:  February 20, 2009
/
/******************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

extern char** environ;

void cd(char*** newargv) {
   if((chdir((*newargv)[1]))!= -1){
     setenv("PWD", (*newargv)[1], 1);
   }
   else{
     perror("Not a Directory");
   }
}
void env(){
   int i;
   printf ("The environment list follows:\n");
   for (i=0; environ[i] != NULL; i++){
      printf ("environ[%d]: %s\n", i, environ[i]);
   }
}
void Echo(char*** newargv, int* numtokens){
   int i;
   for(i = 1; i<(*numtokens); i++){
      fprintf(stdout, "%s ", (*newargv)[i]);
   }
   fprintf(stdout, "\n");
}
void Pause(){
   char p;
   printf("System Paused \n");
   while(getchar()!='\n');
}
