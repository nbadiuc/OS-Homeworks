#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
