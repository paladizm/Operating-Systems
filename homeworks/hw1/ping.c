//Zac Paladino
//Assignment 1
//01/20/2009
//CPS 346
//ping.c
#include <stdio.h>
#include <unistd.h>

int main(void) {
   int i;
   for (i = 0; i < 10; i++) {
     if (fork() == 0) {
	fprintf(stderr, "PPID: %ld, PID: %ld, ping.\n", (long)getppid(),
           (long)getpid());
       break;
     }
     else{
        fprintf(stderr, "PPID: %ld, PID: %ld, pong.\n", (long)getppid(),
	   (long)getpid());
    } 
   }
   return (0);
}
