#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("%d %d\n", a, sizeof(a));
    printf("%f %d\n", b, sizeof(b));
    printf("%f %d\n", c, sizeof(c));
    return 0;
}
