/*******************************************************************************
/
/      filename:  utils.c
/
/   description:  Impliments all of the IO and exec for myshell.
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

void stripIO(char** line,char*** toklin, char** newl, char** opf, char** ipf,int* numtok);
void RedIO(char*** toklin, char** opf, char** ipf,int* REDSI,int* REDSO, int* numtok,
               int* fd, int* fdi, int* fdr, int* EXIT);
void execproc(char*** newargv, char** line, int* REDSO, int* REDSI, int* fdr, void** x,FILE** input);
