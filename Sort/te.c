
#include <stdio.h>

int main()
{
    int n, i, j;

    n = 6;

    printf("Ve tam giac sao vuong can:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            printf("  ");

        for (j = i; j < n; j++)
            printf(" %d", j);

        printf("\n");
    }

    return 0;
}