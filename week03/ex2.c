#include<stdio.h>

void bubble_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
        }
    }
}

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    bubble_sort(a, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
}
