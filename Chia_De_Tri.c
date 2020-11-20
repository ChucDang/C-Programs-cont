#include <stdio.h>
#define keytype int
#define othertype float
// ------------------------Note----------------
// Thuat toan nhan 2 mang:
//     -- for n -> 1 neu a[]*b[]+k> 10 thi c[]= kq%10 va k = 1
//         neu khong lon hon 10 thi k =0;
typedef struct
{
    keytype key;
    othertype other;
} recordtype;
void nhan(recordtype a[], recordtype b[], int n, recordtype c[])
{
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[i].key * b[i].key + k;
        if (temp >= 10)
        {
            c[i].key = temp % 10;
            k = temp / 10;
        }
        else
        {
            k = 0;
            c[i].key = temp;
        }
    }
}
void cong(recordtype a[], recordtype b[], int n, recordtype c[])
{
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[i].key + b[i].key + k;
        if (temp >= 10)
        {
            c[i].key = temp % 10;
            k = temp / 10;
        }
        else
        {
            k = 0;
            c[i].key = temp;
        }
    }
    return c[n];
}
int main()
{
    int n;
    freopen("d.inp", "r", stdin);
    scanf("%d", &n);
    recordtype A[n];
    recordtype B[n];
    recordtype C[n];
    recordtype D[n];
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%d", &A[i].key);
    }
    for (int i = n / 2; i < n; i++)
    {
        scanf("%d", &B[i].key);
    }
    for (int i = 0; i < n / 2; i++)
    {
        scanf("%d", &C[i].key);
    }
    for (int i = n / 2; i < n; i++)
    {
        scanf("%d", &D[i].key);
    }
    recordtype AC[n];
    nhan(A, C, n, AC);
    recordtype AD[n];
    nhan(A, D, n, AD);
    recordtype BC[n];
    nhan(B, C, n, BC);
    recordtype BD[n];
    nhan(B, D, n, BD);
    recordtype AD_BC[n];
    cong(AD, BC, n, AD_BC);
    recordtype temp[n];
    cong(AC, AD_BC, n, temp);
    recordtype kq[n];
    cong(temp, BD, n, kq);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", kq[i].key);
    }
}