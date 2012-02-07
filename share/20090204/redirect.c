/* ref. [USP] Chapter 4, Program 4.18, p. 131 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
//#define CREATE_FLAGS (O_WRONLY | O_CREAT | O_APPEND)
//#define CREATE_FLAGS (O_WRONLY | O_CREAT)
#define CREATE_FLAGS (O_WRONLY | O_CREAT | O_TRUNC)
#define CREATE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main() {
   //int mode = (O_WRONLY | O_CREAT | O_APPEND);

   pid_t childpid = fork();

   int fd = open("testfile.txt", CREATE_FLAGS, CREATE_MODE);
   //fd = open("testfile.txt", CREATE_FLAGS);

   if (fd == -1) {
       perror("Failed to open testfile.txt.");
       return 1;
   }

   if (dup2(fd, STDOUT_FILENO) == -1) {
      perror("Failed to redirect standard output.");
      return 1;
   }

   if (close(fd) == -1) {
      perror("Failed to close the file.");
      return 1;
   } 
    
   if (childpid) {
   //if (write(STDOUT_FILENO, "Write this to stdout.", 21) == -1) {
   if (write(STDOUT_FILENO, "parent", 6) == -1) {
      perror("Failed in writing to file.");
      return 1;
   } 
   } else
   if (write(STDOUT_FILENO, "child", 5) == -1) {
      perror("Failed in writing to file.");
      return 1;
   } 
   return 0;
}
