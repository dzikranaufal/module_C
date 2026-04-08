#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "2.h"

int main()
{
    Stack antrian;
    init(&antrian);
    int jumlah;
    printf("Masukkan jumlah pasien : ");
    scanf("%d", &jumlah);
    printf("Masukkan kode prioritas (pisah spasi) : ");
    int input, is_valid = 1;
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &input);
        if ( peek(&antrian) == 0 || input >= peek(&antrian))
        {
            push(&antrian, input);
        }
        else
        {
            is_valid = 0;
            break;
        }
    }
    if (is_valid)
    {
        printf("Urutan antrian Valid - Pasien dengan prioritas tinggi berada di atas");
    }
    else
    {
        printf("Urutan antrian Tidak Valid !! Pasien dengan prioritas tinggi tertumpuk dibawah pasien dengan prioritas lebih rendah.\n");
    }
}