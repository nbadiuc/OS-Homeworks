#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

main() {

    char string1[9] = "hello";
    char string2[9] = "";

    int fd[2];  // used to store two ends of pipe; file descriptor
    if (pipe(fd) < 0) {
    	return 1;
    }

    pid_t p = fork();

    if (p > 0) {
        write(fd[1], string1, strlen(string1) + 1);
        close(fd[1]);  // close writing end of pipe
    }
    else if (p == 0) {
        read(fd[0], string2, strlen(string1) + 1);
        close(fd[1]);  // close reading end of pipe
        printf("%s", string2);
    }
    else {
    	printf("fork failed");
    }
    return 0;

}
