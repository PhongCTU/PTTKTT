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

/*doc file vao mang*/
void docFile(recordType a[], int *n)
{
    FILE *f;
    f = fopen("data.txt", "r"); /*mo de doc file data.txt*/
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
    {
        printf("%3d%5f%8.2f\n", i + 1, a[i].key, a[i].otherfields);
    }
}

int main()
{
    recordType a[100];
    int n;
    docFile(a, &n);
    printf("Du lieu ban dau: \n");
    inMang(a, n);
    /* selectionSort(a, n);
    printf("Ket qua sau khi sap xiep chon: ");
    inMang(a, n);
    return 0; */
}