#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Cau truc Tien
typedef struct
{
    char tenTien[25];
    int menhGia, PA;
} Tien;

// doc file ATM.txt
Tien *ReadFromFile(int *n)
{
    FILE *f = fopen("ATM.TXT", "r");           // doc file ATM.txt
    Tien *dslt = (Tien *)malloc(sizeof(Tien)); // khoi tao 1 danh sach loai tien
    int i = 0;
    while (!feof(f)) // khi con tro con nam trong file
    {
        fscanf(f, "%d", &dslt[i].menhGia);                    // dinh dang nhap menh gia vao danh sach
        fgets(dslt[i].tenTien, 25, f);                        // nhap menh gia vao danh sach
        dslt[i].tenTien[strlen(dslt[i].tenTien) - 1] = '\0';  // cho con tro ket thu dong va xuong hang
        dslt[i].PA = 0;                                       // phan an  = 0
        i++;                                                  // tang i
        dslt = (Tien *)realloc(dslt, sizeof(Tien) * (i + 1)); // khoi tao ds loai tien noi tiep danh sach
    }
    *n = i;      // do dai danh sach
    fclose(f);   // dong file f
    return dslt; // tra ve keet qua
}

// ham swap hoan doi vi tri
void Swap(Tien *x, Tien *y)
{
    Tien Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}
// Sap xep theo thu tu tang cua Don gia
// ham sap xep noi bot
void BubbleSort(Tien *dslt, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)         // i: 0 -> n-2
        for (j = n - 1; j >= i + 1; j--) // j: n-1 -> 0
        {
            if (dslt[j].menhGia > dslt[j - 1].menhGia) // neu menh gia thu j > menh gia thu j
                Swap(&dslt[j], &dslt[j - 1]);          // doi cho hai menh gia
        }
}
// in thu tu va so luong cac to can rut
void InDS(Tien *dslt, int n, int TienCanRut) // ds loai tien, dodai danh sach, so tien can rut
{
    int i;
    int TongTienTra = 0; // so tien tra ra
    printf("|---|-------------------------|---------|---------|----------|\n");
    printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", "     Loai tien   ", "Menh Gia", "So to", "Thanh tien");
    printf("|---|-------------------------|---------|---------|----------|\n");
    for (i = 0; i < n; i++) // i: 0 -> n-1
    {
        printf("|%-3d", i + 1);                                   // in so thu tu
        printf("|%-25s", dslt[i].tenTien);                        // in loai tien
        printf("|%-9d", dslt[i].menhGia);                         // in menh gia
        printf("|%-9d", dslt[i].PA);                              // in so to
        printf("|%-10d|\n", dslt[i].menhGia * dslt[i].PA);        // thanh tien
        TongTienTra = TongTienTra + dslt[i].PA * dslt[i].menhGia; // tong tien tra ra
    }
    printf("|---|-------------------------|---------|---------|----------|\n");
    printf("So tien can rut= %9d\n", TienCanRut); // so tien can rut
    printf("So tien da tra= %9d\n", TongTienTra); // so tien tra ra
}
// ham tham an
void Greedy(Tien *dslt, int n, int TienCanRut) // ds loai tien, dodai danh sach, so tien can rut
{
    int i = 0;
    while (i < n && TienCanRut > 0) // i chua cuoi danh sach va so tien can rut > 0
    {
        dslt[i].PA = TienCanRut / dslt[i].menhGia;              // phan an = so tien can rut / menh gia
        TienCanRut = TienCanRut - dslt[i].PA * dslt[i].menhGia; // tien can rut con lai = tien can rut - phan an * menh gia cuar phan duoc an do.
        i++;                                                    // tang i
    }
}

int main()
{
    int n;
    int TienCanRut;
    printf("Nhap so tien can rut: ");
    scanf("%d", &TienCanRut);
    Tien *dslt;
    dslt = ReadFromFile(&n);
    BubbleSort(dslt, n);
    Greedy(dslt, n, TienCanRut);
    InDS(dslt, n, TienCanRut);
    free(dslt);
    return 0;
}