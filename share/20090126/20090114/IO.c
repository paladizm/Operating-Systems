#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define SIZE 120

main() {

  FILE* myfp;

  int myfiledes;

  char* buf[SIZE];

  if ((myfp = fopen("my.dat", "w")) == NULL)
     perror ("Failed to open my.dat");
  else {
     fprintf (myfp, "Put this in the buffer.");
     fclose(myfp);
  }

  myfiledes = open ("my.dat", O_RDONLY);

  read(myfiledes, buf, 23);

  write(1, buf, 23);
}
