#include <stdio.h>
#include <string.h>
#include <malloc.h>

// cau truc mot do vat
typedef struct
{
    char TenDV[20];
    float TL, GT, DG; // Trong luong, Gia tri, Don gia
    int Phuong_An;    // So phuong an duoc chon
} DoVat;

DoVat *Read_File(char file_name[], float *W, int *n)
{
    FILE *f;
    f = fopen(file_name, "r");                    // mo file de doc
    fscanf(f, "%f", W);                           // Xac dinh trong luong Ba lo
    DoVat *dsdv = (DoVat *)malloc(sizeof(DoVat)); // khoi tao mot danh sach do vat
    int i = 0;
    while (!feof(f)) // khi con tro con trong file
    {
        fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV); // luu lai trong luong, gia tri, ten do vat
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;                              // don gia = gia tri / trong luong
        dsdv[i].Phuong_An = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1)); // noi tiep 1 do vat moi vao danh sach do vat
    }
    *n = i;
    fclose(f);   // dong file
    return dsdv; // tra ve danh sach do vat
}
// Ham Swap hoan doi cac do vat voi nhau
void Swap(DoVat *x, DoVat *y)
{
    DoVat temp = *x;
    *x = *y;
    *y = temp;
}

// Ham bubbleSort(sap xep noi bot) sap xep do vat co don gia tu cao den thap
void BubbleSort(DoVat *dsdv, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)
        for (j = n - 1; j >= i + 1; j--)
        {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                Swap(&dsdv[j], &dsdv[j - 1]);
        }
}

// Ham in danh sach do vat
void in_dsdv(DoVat *dsdv, int n, float W)
{
    int i;
    float TongTL = 0.0, TongGT = 0.0; // khoi ta tong gia tri va tong trong luong = 0
    printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
    printf("\nTrong luong cua ba lo = %-9.2f\n", W);
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     | T Luong | Gia Tri | Don Gia | Phuong an |\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%2d |%-20s|%9.2f|%9.2f|%9.2f|%6d     |\n",
               i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].Phuong_An);
        TongTL = TongTL + dsdv[i].Phuong_An * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].Phuong_An * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d,", dsdv[i].Phuong_An);
    }
    printf("%d)", dsdv[n - 1].Phuong_An);
    printf("\nTong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}
void greedy(DoVat *dsdv, int n, float W, int s)
{
    for (int i = 0; i < n; i++)
    {
        dsdv[i].Phuong_An = (W / dsdv[i].TL); // phuong an = phan nguyen cua trong luong cua balo / trong luong do vat
        if (dsdv[i].Phuong_An > s)
            dsdv[i].Phuong_An = s;
        W = W - dsdv[i].Phuong_An * dsdv[i].TL; // trong luong con lai cua balo = phuong an * trong luong cua vat.
    }
}
int main()
{
    int n;
    float W;
    DoVat *dsdv;
    int s;
    printf("Nhap vao so luong: ");
    scanf("%d", &s);
    dsdv = Read_File("D:/PTTKTT/Thaman/balo2.txt", &W, &n);
    BubbleSort(dsdv, n);
    greedy(dsdv, n, W, s);
    in_dsdv(dsdv, n, W);
    free(dsdv);
    return 0;
}