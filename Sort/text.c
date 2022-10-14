#include <stdio.h>
/**
 * Ham Swap (Sap Xiep)
 * Ham SelectionSort (Sap Xiep Chon)
 * Ham InsertSort (Sap Xiep Chen)
 * Ham  BubbleSort (Sap Xiep Noi Bot)
 */

/* Swap */
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void XuatMang(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            printf("   ");

        for (j = i; j < n; j++)
            printf("%d ", a[j]);

        printf("\n");
    }
}
/* SelectionSort */
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int index = i;
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] < a[index])
            {
                index = j;
            }
        }
        if (i == 0)
        {

            for (int j = i - 1; j < n; j++)
            {
                if (j == -1)
                {
                    printf("");
                }
                else
                {
                    printf("%-d      ", a[j]);
                }
            }
        }
        else if (i == 1)
        {

            for (int j = i - 1; j < n; j++)
            {

                printf("%-d      ", a[j]);
            }
        }
        else
        {
            for (int j = 0; j <= i - 2; j++)
                printf("        ");
            for (int j = i - 1; j < n; j++)
            {

                printf("%d      ", a[j]);
            }
        }

        if (index != i)
        {
            Swap(&a[i], &a[index]);
        }

        printf("\n");
    }
    printf("----------------\n\n");
    printf("Ket qua:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

/* InsertSort */
void InsertSort(int a[], int n)
{
    printf("       ");
    for (int i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
        for (j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                printf("         %d", a[0]);
            }
            else
                printf(" %d ", a[j]);
        }
        printf("\n");
    }
    printf("Ket qua:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}
/* BubbleSort */
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
            }
        }
    }
    printf("Ket qua:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

int main()
{
    int arr[] = {50, 143, 0, 10, 10, 120, 90, 10, 90, 140, 20, 30};
    char a[] = "SelectionSort";
    char b[] = "InsertionSort";
    char c[] = "BubbleSort";
    int n = sizeof(arr) / sizeof(arr[0]);
    /* FILE *f = fopen("data.txt", "w");
    fprintf(f, "Mang ban dau = { ");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d ", arr[i]);
    }
    fprintf(f, "}\n");
    fprintf(f, "%s \n", a);
    fprintf(f, "%s\n", b);
    fprintf(f, "%s\n", c);
    fclose(f); */
    /* SelectionSort(arr, n);
    printf("\n----------------------------\n"); */
    /*\\ InsertSort(arr, n); */
    BubbleSort(arr, n);
    /* xuatmang(a, n); */

    return 0;
}