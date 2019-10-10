#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; i++) {
        int *arr = calloc(10*1024*1024, 1);
        sleep(1);
	free(arr);
    }
    return 0;
}
/*
This exercise was done on the Pavlov Vyacheslav's laptop.

:~/Загрузки$ ./a.out&
[1] 5107
:~/Загрузки$ top -p5107

top - 23:24:27 up  1:28,  1 user,  load average: 1,23, 0,92, 0,69
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
%Cpu(s):  2,1 us,  1,0 sy,  0,0 ni, 95,9 id,  0,7 wa,  0,0 hi,  0,3 si,  0,0 st
КиБ Mem : 16284080 total, 12643960 free,  1828124 used,  1811996 buff/cache
КиБ Swap: 16454652 total, 16454652 free,        0 used. 13663968 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 5107 pavlov    20   0   14744  11300   1192 S   0,0  0,1   0:00.01 a.out
*/
