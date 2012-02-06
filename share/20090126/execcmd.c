/* ref. [USP] Chapter 3, Example 3.5, p. 81 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
   pid_t childpid;

   if (argc < 2){      /* check for valid number of command-line arguments */
      fprintf (stderr, "Usage: %s command arg1 arg2 ...\n", argv[0]);
      return 1;
   }
   childpid = fork();
   if (childpid == -1) {
      perror("Failed to fork");
      return 1;
   }
   if (childpid == 0) {                                      /* child code */
      if (setsid() == -1)
         perror("Child failed to become a session leader");

      execvp(argv[1], &argv[1]);
fprintf(stderr, "exec just returned\n");
      perror("Child failed to execvp the command");
      return 1;
   }
   // if (childpid != wait(NULL)) {                          /* parent code */
   //   perror("Parent failed to wait");
    //  return 1;
  // }
   return 0;    
}
