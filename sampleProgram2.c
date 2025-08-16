/**********************************************************
 *
 * sampleProgram2.c
 * CIS 451 Lab 3
 *
 * !!!NAMES!!!
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main() {
   int fd[2];
   int pipe_creation_result;
   int pid;

   pipe_creation_result = pipe(fd);

   if (pipe_creation_result < 0) {
      perror("Failed pipe creation\n");
      exit(1);
   }

   pid = fork();

   if (pid < 0) {
      // Fork failed
      perror("Fork failed");
      exit(1);
   }

   int output = 3;
   int input;

   if (pid == 0) {
      // Child process
      write(fd[1], &output, sizeof(int));
      printf("Child wrote [%d]\n", output);
   } else {
      read(fd[0], &input, sizeof(int));
      printf("Parent received [%d] from child process\n", input);
   }

   return 0;
}
