#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler();

int main () {
   signal(SIGINT, sighandler);

   while(1) {
      printf("Going to sleep for a second\n");
      sleep(1);
   }
   return(0);
}

void sighandler() {
   printf("Caught signal");
   exit(0);
}
