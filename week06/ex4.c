#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void killhandler();
void stoplhandler();
void usrlhandler();

int main () {
	signal(SIGKILL, killhandler);
	signal(SIGSTOP, stoplhandler);
	signal(SIGUSR1, usrlhandler);
    while(1) {
      printf("Going to sleep for a second\n");
      sleep(1);
    }
    return(0);
}

void killhandler() {
   printf("Caught SIGKILL");
   exit(0);
}

void stoplhandler() {
   printf("Caught SIGSTOP");
   exit(0);
}

void usrlhandler() {
   printf("Caught SIGUSR1");
   exit(0);
}

/*
:~/Загрузки$ gcc ex4.c -o ex4
:~/Загрузки$ ./ex4 &
[1] 17767
:~/Загрузки$ Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
Going to sleep for a second
kill -SIGUSR1 17767
Caught SIGUSR1 :~/Загрузки$

After kill sent a signal, the corresponding signalhandler responded.
*/
