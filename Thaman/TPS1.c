#include <stdio.h>
#define size 30 // toi da la 30 thanh pho
// cau  truc canh
typedef struct
{
    float dodai;   // do dai cua canh
    int dau, cuoi; // diem dau va cuoi
} canh;

// ham doc file TPS1.txt
void Read_file(char file_name[], canh a[], int *n) // lay du lieu tu file name bo vao mang canh a co n phan tu
{
    int i, j, t;
    float temp;
    FILE *f = fopen(file_name, "r"); // mo tap tin file name
    if (f == NULL)
    {
        printf("Loi mo file!\n");
        return;
    }
    fscanf(f, "%d", n); // doc so dau tien vao n
    int k = 0;
    for (i = 0; i < *n; i++)
        for (j = i; j < *n; j++)
            if (i == j)                     /// duong cheo chinh
                for (t = 0; t <= j; t++)    // lap cac phan tu nam duoi duong cheo chinh
                    fscanf(f, "%f", &temp); // bo vao bien tam ko quan tam toi
            else                            // luu cac so lieu phia tren duong cheo chinh
            {
                fscanf(f, "%f", &a[k].dodai); // luu do dai
                a[k].dau = i;                 // dau
                a[k].cuoi = j;                // cuoi
                k++;
            }
    fclose(f);
}
// ham in danh sach canh
void inDSCanh(canh a[], int m, int la_PA) // mang canh, do dai mang, la phuong an
{
    int i;
    float tong = 0.0;
    for (i = 0; i < m; i++)
    {
        printf("%3d %c%c = %8.2f\n", i + 1, a[i].dau + 65, a[i].cuoi + 65, a[i].dodai); // cong 65 ra chu cai in hoa
        if (la_PA)
            tong += a[i].dodai;
    }
    if (la_PA)
        printf("Tong do dai canh = %8.2f\n", tong);
}

// ham hoan doi swap
void Swap(canh *x, canh *y)
{
    canh temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// ham sap xep noi bot
void bubbleSort(canh a[], int n)
{
    for (int i = 0; i < n - 2; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j].dodai < a[j - 1].dodai)
                Swap(&a[j], &a[j - 1]);
}

int dinhCap_3(canh PA[], int k, canh moi)
{
    int i = 0, dem = 1;
    while (i < k && dem < 3)
    {
        if (moi.dau == PA[i].dau || moi.dau == PA[i].cuoi)
            dem++;
        i++;
    }
    if (dem == 3)
        return 1;
    i = 0;
    dem = 1;
    while (i < k && dem < 3)
    {
        if (moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi)
            dem++;
        i++;
    }
    return dem == 3;
}
void init_forest(int parent[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        parent[i] = i;
}

int find_root(int parent[], int u)
{
    while (u != parent[u])
        u = parent[u];
    return u;
}

int chu_trinh(int r_dau, int r_cuoi)
{
    return r_dau == r_cuoi;
}

void update_forest(int parent[], int r1, int r2)
{
    parent[r2] = r1;
}

void greedy(canh ds_canh[], int n, canh PA[])
{
    int i, j;
    int parent[n];
    init_forest(parent, n);
    int r_dau, r_cuoi;
    j = 0;
    for (i = 0; i < n * (n - 1) / 2 && j < n; i++)
    {
        r_dau = find_root(parent, ds_canh[i].dau);
        r_cuoi = find_root(parent, ds_canh[i].cuoi);
        if (!dinhCap_3(PA, j, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi))
        {
            PA[j] = ds_canh[i];
            j++;
            update_forest(parent, r_dau, r_cuoi);
        }
    }

    for (; i < n * (n - 1) / 2; i++)
    {
        r_dau = find_root(parent, ds_canh[i].dau);
        r_cuoi = find_root(parent, ds_canh[i].cuoi);
        if (!dinhCap_3(PA, n - 1, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi))
        {
            PA[n - 1] = ds_canh[i];
            break;
        }
    }
}

int main()
{
    canh ds_canh[size];
    int n;
    Read_file("TPS1.txt", ds_canh, &n);
    printf("Danh sach cac canh cua do thi:\n");
    inDSCanh(ds_canh, n * (n - 1) / 2, 0);
    bubbleSort(ds_canh, n * (n - 1) / 2);
    printf("Danh sch canh cua do thi da sap xep: \n");
    inDSCanh(ds_canh, n * (n - 1) / 2, 0);
    canh PA[n];
    greedy(ds_canh, n, PA);
    printf("Phuong an: \n");
    inDSCanh(PA, n, 1);
    return 0;
}