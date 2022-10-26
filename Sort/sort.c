#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
typedef float otherType;
typedef struct
{
    KeyType key;
    otherType otherfields;
} recordType;

/* ham Swap (O1) */
void Swap(recordType *x, recordType *y)
{
    recordType temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Sap xiep chon (On2)*/
void selectionSort(recordType a[], int n)
{
    int i, j, lowindex;
    KeyType lowkey;
    for (i = 0; i < n - 2; i++)
    {
        lowkey = a[i].key;
        lowindex = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (a[j].key < lowkey)
            {
                lowkey = a[j].key;
                lowindex = i;
            }
            Swap(&a[i], &a[lowindex]);
        }
    }
}
/* sap xiep xen */
void insertSort(recordType a[], int n)
{
    int i, j;
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while (j > 0 && (a[j].key < a[j - 1].key))
        {
            Swap(&a[j], &a[j - 1]);
            j--;
        }
    }
}

/* sap xiep noi bot*/
void bubbleSort(recordType a[], int n)
{
    int i, j;
    for (i = 0; i < n - 2; i++)
        for (j = n - 1; j >= i + 1; j--)
            if (a[j].key < a[j - 1].key)
                Swap(&a[j], &a[j - 1]);
}

/* pushdown*/
void pushDown(recordType a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
        if (last == 2 * r + 1)
        {
            if (a[r].key > a[last].key)
                Swap(&a[r], &a[last]);
            r = last;
        }
        else if ((a[r].key > a[2 * r + 1].key) && (a[2 * r + 1].key <= a[2 * r + 2].key))
        {
            Swap(&a[r], &a[2 * r + 1]);
            r = 2 * r + 1;
        }
        else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key))
        {
            Swap(&a[r], &a[2 * r + 2]);
            r = 2 * r + 2;
        }
        else
            r = last;
}

/* heapSort */
void heapSort(recordType a[], int n)
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
        pushDown(a, i, n - 1);
    for (i = n - 1; i >= 2; i--)
    {
        Swap(&a[0], &a[i]);
        pushDown(a, 0, i - 1);
    }
    Swap(&a[0], &a[1]);
    bubbleSort(a, n);
}
/* findPivot */
int findPivot(recordType a[], int i, int j)
{
    KeyType firstkey;
    int k;
    k = i + 1;
    firstkey = a[i].key;
    while ((k <= j) && (a[k].key == firstkey))
        k++;
    if (k > j)
        return -1;
    if (a[k].key > firstkey)
        return k;
    return i;
}
/* findPivot bien the*/
int findPivotBT(recordType a[], int i, int j)
{
    KeyType firstkey;
    int k;
    k = i + 1;
    firstkey = a[i].key;
    while ((k <= j) && (a[k].key == firstkey))
        k++;
    if (k > j)
        return -1;
    if (a[k].key > firstkey)
        return i;
    return k;
}
/* patition */
int Patition(recordType a[], int i, int j, KeyType Pivot)
{
    int L, R;
    L = i;
    R = j;
    while (L <= R)
    {
        while (a[L].key < Pivot)
            L++;
        while (a[R].key >= Pivot)
            R--;
        if (L < R)
            Swap(&a[L], &a[R]);
    }
    return L;
}
/* patition bien the*/
int PatitionBT(recordType a[], int i, int j, KeyType Pivot)
{
    int L, R;
    L = i;
    R = j;
    while (L <= R)
    {
        while (a[L].key <= Pivot)
            L++;
        while (a[R].key > Pivot)
            R--;
        if (L < R)
            Swap(&a[L], &a[R]);
    }
    return L;
}
/* sap xiep nhanh */
void QuickSort(recordType a[], int i, int j)
{
    KeyType Pivot;
    int Pivotindex, k;
    Pivotindex = findPivot(a, i, j);
    if (Pivotindex != -1)
    {
        Pivot = a[Pivotindex].key;
        k = Patition(a, i, j, Pivot);
        QuickSort(a, i, k - 1);
        QuickSort(a, k, j);
    }
}
/* quickSort bien the */
void QuickSortBT(recordType a[], int i, int j)
{
    KeyType Pivot;
    int Pivotindex, k;
    Pivotindex = findPivotBT(a, i, j);
    if (Pivotindex != -1)
    {
        Pivot = a[Pivotindex].key;
        k = PatitionBT(a, i, j, Pivot);
        QuickSortBT(a, i, k - 1);
        QuickSortBT(a, k, j);
    }
}
/*doc file vao mang*/
void docFile(recordType a[], int *n)
{
    FILE *f;
    f = fopen("D:/data.txt", "r"); /*mo de doc file data.txt*/
    int i = 0;
    if (f != NULL)       /* neu file f khong rong */
        while (!feof(f)) /* trong khi chua ket thuc tap tin */
        {
            fscanf(f, "%d%f", &a[i].key, &a[i].otherfields); /* doc tung dong */
            i++;
        }
    else
        printf("Loi mo File!\n");
    fclose(f); /* doc xong dong file lai*/
    *n = i;    /* xac dinh so phan tu cua mang a */
}
/*in mang */
void inMang(recordType a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%3d%5d%8.2f\n", i + 1, a[i].key, a[i].otherfields);
}

int main()
{
    recordType a[100];
    int n;
    docFile(a, &n);
    printf("Du lieu ban dau: \n");
    inMang(a, n);
    /*  selectionSort(a, n); */
    /* insertSort(a, n); */
    /* bubbleSort(a, n); */
    /* heapSort(a, n); */
    /* QuickSort(a, 0, n - 1); */
    QuickSortBT(a, 0, n - 1);
    printf("Ket qua sau khi sap xiep chon: \n");
    inMang(a, n);
    return 0;
}