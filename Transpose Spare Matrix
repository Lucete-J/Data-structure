// Transpose Sparse Matrix

#include <stdio.h>

#define MAX_SIZE 11

typedef struct {
    int row;
    int col;
    int value;
} term;

void smTranspose(term a[], term b[]);

int main(void)
{
    int i, j;
    term A[MAX_SIZE] = {
        {8, 7, 10}, {0, 2, 2}, {0, 6, 12}, {1, 4, 7}, 
        {2, 0, 23}, {3, 3, 31}, {4, 1, 14}, {4, 5, 25}, 
        {5, 6, 6}, {6, 0, 52}, {7, 4, 11}
        };
    term B[MAX_SIZE];

    smTranspose(A, B);

    printf("Transpose Matrix Of A. \n");
    printf("Row : %d, Columm : %d, Nonzero : %d\n", A[0].row, A[0].col, A[0].value);  
    for (i = 0 ; i < MAX_SIZE ; i ++)
        printf("Row : %d, Columm : %d, Value : %d\n", A[i].row, A[i].col, A[i].value);
    printf("\n\n");

    smTranspose(A, B);

    printf("Transpose processing has been finished. \n");
    printf("\n\n");

    printf("Transpose Matrix Of B. \n");
    printf("Row : %d, Columm : %d, Nonezeor : %d\n", B[0].row, B[0].col, B[0].value);
    for (i = 1 ; i < MAX_SIZE ; i ++)
        printf("Row : %d, Columm : %d, Value : %d\n", B[i].row, B[i].col, B[i].value);
    printf("\n\n");

    return 0;
}

void smTranspose(term a[], term b[])
{
    int i, j, currentb;

    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    if (a[0].value > 0) {
        currentb = 1;
        for (i = 0 ; i < a[0].col ; i ++)
            for (j = 1 ; j <= a[0].value ; j ++)
                if(a[j].col == i) {
                        b[currentb].row = a[j].col;
                        b[currentb].col = a[j].row;
                        b[currentb].value = a[j].value;
                        currentb ++;
                }
    }
}
