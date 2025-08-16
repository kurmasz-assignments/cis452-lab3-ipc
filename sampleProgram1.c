/**********************************************************
 *
 * sampleProgram1.c
 * CIS 451 Lab 3
 *
 * !!!NAMES!!!
 *************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void sigHandler(int);

int main() {
   signal(SIGINT, sigHandler);
   printf("waiting...\n");
   int pause_val = pause();
   printf("pause() returned %d\n", pause_val);
   return 0;
}

void sigHandler(int sig_num) {
   printf(" received an interrupt.\n");
   // this is where shutdown code would be inserted
   sleep(1);
   printf("time to exit\n");
   exit(0);
}
