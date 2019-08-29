#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    sscanf(argv[1],"%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n - i; j++){
            printf(" ");
        }
        for (int h = 0; h < i * 2 - 1; h++){
            printf("*");
        }
        printf ("\n");
    }
}
