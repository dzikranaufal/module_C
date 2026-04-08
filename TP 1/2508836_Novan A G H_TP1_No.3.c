#include <stdio.h>

int hitungLele(int lele)
{
    lele = lele * 3;
    return lele;
}
int hitungNila(int nila, int lele)
{
    nila = (nila - 10) + (lele / 2);
    return nila;
}
int hitungGurame(int gurame, int nila)
{
    gurame = gurame + (nila / 3);
    return gurame;
}

int main()
{
    int lele, nila, gurame;
    printf("Masukkan jumlah populasi awal :\n");
    scanf("%d %d %d", &lele, &nila, &gurame);
    printf("Bulan ke-1\n");
    printf("Lele : %d\n", lele);
    printf("Nila : %d\n", nila);
    printf("Gurame : %d\n", gurame);
    int hasil_lele = hitungLele(lele);
    int hasil_nila = hitungNila(nila, lele);
    int hasil_gurame = hitungGurame(gurame, hasil_nila);
    printf("Bulan ke-2\n");
    printf("Lele : %d\n", hasil_lele);
    printf("Nila : %d\n", hasil_nila);
    printf("Gurame : %d\n", hasil_gurame);
}