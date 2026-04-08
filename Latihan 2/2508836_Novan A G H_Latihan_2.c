#include <stdio.h>

typedef struct
{
    char nama[50];
    float UTS, UAS, nilaiAkhir;
} Nilai;

float NilaiAkhir(Nilai *n)
{
    n->nilaiAkhir = (n->UTS*0.4) + (n->UAS*0.6);
    return n->nilaiAkhir;
}

int main()
{
        int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    Nilai nilai[n];
    for (int i = 0; i < n; i++)
    {
        printf("Mahasiswa ke-%d\n", i + 1);
        printf("Nama  : ");
        scanf(" %[^\n]", nilai[i].nama);
        printf("Nilai UTS  : ");
        scanf("%f", &nilai[i].UTS);
        printf("Nilai UAS  : ");
        scanf("%f", &nilai[i].UAS);
        NilaiAkhir(&nilai[i]);
    }
    printf("========= Nilai Mahasiswa ==========\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n\nNama \t: %s\n", nilai[i].nama);
        printf("UTS \t: %.1f\n", nilai[i].UTS);
        printf("UAS \t: %.1f\n", nilai[i].UAS);
        printf("Nilai Akhir \t: %.1f\n", nilai[i].nilaiAkhir);
    }

    return 0;
}
