/*******************************************************************************
/
/      filename:  builtins.h
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

void cd(char*** newargv);
void env();
void Echo(char*** newargv, int* numtokens);
void Pause();

