/* ref. [USP] Chapter 3, Program 3.4, p. 79 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   pid_t childpid;

   childpid = fork();
   if (childpid == -1)  {
       perror("Failed to fork");
       return 1; 
   }
   if (childpid == 0) {                            /* child code */
       execv("/bin/ls", "ls", "-l", NULL);
       perror("Child failed to exec ls");
       return 1; 
   }
   if (childpid != wait(NULL)) {                  /* parent code */
       perror("Parent failed to wait due to signal or error");
       return 1;
   } else {
        fprintf(stderr, "Parent just finished.\n");
     }
   return 0; 
}
