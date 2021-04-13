#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100001

void selectionSort(int * ary, int n);


int main(void)
{
    int i, n = 0;
    int step = 100;
    int ary[MAX_SIZE];
    clock_t start;
    double duration;
    FILE * fp = fopen("ssort.csv", "w");

    fprintf(fp, "%s,%s\n", "n", "time");
    for (i = 0 ; i < MAX_SIZE ; i ++)
        ary[i] = MAX_SIZE - i;

    printf("    n         time\n");
    for (n = 100 ; n < MAX_SIZE ; n += step) {
        start = clock();                    // Start time
        selectionSort(ary, n);
        duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "%d,%f\n", n, duration);
        printf("%d     %f\n", n, duration);
        if (n == 1000) step = 1000;
        if (n == 10000) step = 10000;
    }
    fclose(fp);

}
void selectionSort(int * ary, int n)
{
    int i, j;
    int temp;

    for (i = 0 ;i < n ;i ++) {
        for (j = i + 1; j < n ;j ++) {
            if (ary[i] > ary[j]) {
                temp = ary[j];
                ary[j] = ary[i];
                ary[i] = temp;
            }
        }
    }
}
