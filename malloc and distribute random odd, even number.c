#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct _number {
    int odd_num;
    int even_num;
} number;

void Do_Malloc_Quiz(char str[], int n)
{
    int i, rand_even, rand_odd;
    number * ary;

    srand(time(NULL));
    ary = (number *)malloc(sizeof(number) * n);

    for (i = 0 ; i < n ; i ++) {
        rand_even = rand() % 51; 
        if (rand_even % 2 == 0) ary[i].even_num = rand_even;
        else ary[i].even_num = rand_even - 1;
    }

    for (i = 0 ; i < n ; i ++) {
        rand_odd = rand() % 51; 
        if (rand_odd % 2 == 1) ary[i].odd_num = rand_odd;
        else ary[i].odd_num = rand_odd + 1;
    }

    printf("%s\n", str);
    printf("Odd Number : ");
    for (i = 0 ; i < n ; i ++) printf("%d ", ary[i].odd_num);
    printf("\nEven number : ");
    for (i = 0 ; i < n ; i ++) printf("%d ", ary[i].even_num);
    
    free(ary);
}   


int main(void)
{
    char str[] = "Quiz";
    int num_ary;

    printf("Enter the number : ");
    scanf("%d", &num_ary);

    Do_Malloc_Quiz(str, num_ary);

    return 0;
}
