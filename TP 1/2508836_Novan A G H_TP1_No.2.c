#include <stdio.h>

void inputBuku(int jenis_buku, int harga_buku[], int jumlah_terjual[])
{
    for (int i = 0; i < jenis_buku; i++)
    {
        printf("Masukkan harga buku ke-%d : ", i + 1);
        scanf("%d", &harga_buku[i]);
        printf("Masukkan jumlah buku terjual ke-%d : ", i + 1);
        scanf("%d", &jumlah_terjual[i]);
    }
}
void hitungTotal(int jenis_buku, int harga_buku[], int jumlah_terjual[], int *total)
{
    for (int i = 0; i < jenis_buku; i++)
    {
        *total += harga_buku[i] * jumlah_terjual[i];
    }
}

void tampilkanLaporan(int jenis_buku, int harga_buku[], int jumlah_terjual[], int *total)
{
    int rata_rata = 0;
    for (int i = 0; i < jenis_buku; i++)
    {
        rata_rata += harga_buku[i];
    }
    rata_rata /= jenis_buku;

    printf("===== Laporan Penjualan =====\n");
    printf("Total Penjualan : %d\n", *total);
    printf("Rata-rata Harga Buku : %d\n", rata_rata);
}

int main()
{
    int jenis_buku;
    printf("Masukkan jumlah jenis buku : ");
    scanf("%d", &jenis_buku);
    int harga_buku[jenis_buku];
    int jumlah_terjual[jenis_buku];
    int total_harga = 0;
    inputBuku(jenis_buku, harga_buku, jumlah_terjual);
    hitungTotal(jenis_buku, harga_buku, jumlah_terjual, &total_harga);
    tampilkanLaporan(jenis_buku, harga_buku, jumlah_terjual, &total_harga);
}