#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main () {
	pid_t p = fork();
	if (p != 0) {
		sleep(10);
		kill(p, SIGTERM);
	}
	else if (p == 0) {
		while(1) {
			printf("I'm alive!\n");
			sleep(1);
		}
	}
	else {
		printf("Fork failed\n");
	}
    return(0);
}
