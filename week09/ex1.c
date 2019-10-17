#include <stdio.h>

int main() {
    int n; //number of page frames
    scanf("%d", &n);
    int pages[n][2]; //pair: page number, counter
    for (int i = 0; i < n; i++) {
        pages[i][0] = 0;
        pages[i][1] = -1;
    }

    FILE *file;
    file = fopen("ex3.txt", "r");
    int page_num;
    int hits = 0, misses = 0;
    int k;
    while ((k = fscanf(file, "%d", &page_num)) == 1) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (pages[i][0] == page_num) {
                hits++;
                x = 1;
                pages[i][1] += 256;
            }
        }
        if (x == 0) {
            misses++;
            // in case of miss we're searching for the page to throw out
            int min = pages[0][1];
            int min_ind = 0;
            for (int i = 1; i < n; i++) {
                if (pages[i][1] < min) {
                    min = pages[i][1];
                    min_ind = i;
                }
            }
            pages[min_ind][0] = page_num;
            pages[min_ind][1] = 256;
        }
        for (int i = 0; i < n; i++) {
            if (pages[i][1] != -1) {
                pages[i][1] /= 2;
            }
        }
    }
    printf("\n%d\n%d\n%f", hits, misses, (double)hits/misses);
    return 0;
}

/*
if number of page frames is equal to 10, the output is:
hits: 10
misses: 990
hits/misses: 0.010101

if number of page frames is equal to 50, the output is:
hits: 51
misses: 949
hits/misses: 0.053741

if number of page frames is equal to 100, the output is:
hits: 93
misses: 907
hits/misses: 0.102536
*/
