#include <stdio.h>

#define MAX_SIZE 64

int main(void) 
{
    int numOfPat, numOfStr;
    int i, n = 0;
    int start, endmatch;
    int count = 0;
    char pat[MAX_SIZE], str[MAX_SIZE];

    printf("Enter the number of pattern. (MAX SIZE = 30, MIN SIZE = 2) : ");
    scanf("%d", &numOfPat);

    printf("Enter the number of string. (MAX SIZE = 30, MIN SIZE = 2) : ");
    scanf("%d", &numOfStr);

    printf("Enter the pattern string. (Size : %d) : ", numOfPat - 1);
    scanf("%s", pat);
    pat[numOfPat] = '\0';

    printf("Enter the string string. (Size : %d) : ", numOfStr - 1);
    scanf("%s", str);
    str[numOfStr] = '\0';

    start = 0;
    endmatch = numOfPat - 1;

    while (endmatch != numOfStr) {
        for (i = start ; i < endmatch ; i ++) {
            if (str[i] == pat[n ++])
                count ++;
        }
        if (count == numOfPat - 1) printf("str[%2d] ~ str[%2d] : Collect. \n", start, endmatch - 1);
        else printf("str[%2d] ~ str[%2d] : Uncollect. \n", start, endmatch - 1);

        start ++; endmatch ++;
        count = 0; n = 0;
    }

    printf("*********** Finish *********** \n");

    return 0;
}
