#include <stdio.h>
#include <string.h>
//arr la menh gia, sl la so luong cua menh gia
int arr[100];
typedef struct
{
    char arr1[40];
} Chuoi;

void thamAn(int tra1[], int SoTien, int index)
{
    int temp;
    printf("kslgajlka");
    while (SoTien > 999)
    {
        temp = SoTien / arr[index];
        if (temp > 0)
        {
            tra1[index] = temp;
            SoTien -= arr[index] * temp;
        }
        index--;
    }
}
int main()
{
    int index;
    Chuoi chuoi[40];
    FILE *f = freopen("d.inp", "r", stdin);
    while (!feof(f))
    {
        scanf("%d", &arr[index]);
        gets(chuoi[index].arr1);
        index++;
    }
    // for (int i = 0; i < index; i++)
    // {
    //     printf("%d", arr[i]);
    //     for (int j = 0; j < strlen(chuoi[i].arr1); j++)
    //     {
    //         printf("%c", chuoi[i].arr1[j]);
    //     }
    //     printf("\n");
    // }
    printf("Nhap so tien can rut: \n");
    int n;
    int tra[6];
    scanf("%d", &n);
    thamAn(tra, n, index - 1);
    // for (int i = 0; i < index; i++)
    // {
    //     printf("%d %d", tra[i], arr[i]);
    // }
}