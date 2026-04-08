#include <stdio.h>
#include <stdbool.h>
int hitungTotalDenda(int dataHari[])
{
    int total_denda = 0;
    for (int i = 0; i < 5; i++)
    {
        if (dataHari[i] > 0)
        {
            total_denda += dataHari[i] * 1000;
        }
    }
    return total_denda;
}
void bayarDenda(int dataHari[])
{
    printf("----- Pembayaran Denda -----\n");
    printf("Data Keterlambatan : [ ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dataHari[i]);
    }
    printf("] \n");
    int index;
    printf("Masukkan Index Mahasiswa yang ingin membayar denda (0-4): ");
    scanf("%d", &index);
    dataHari[index] = 0;
    printf(">> [SUKSES] Mahasiswa index ke-%d telah lunas.", index);
}
void tampilData(int dataHari[])
{
    printf("----- Laporan Data -----\n");
    printf("Data Keterlambatan : [ ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dataHari[i]);
    }
    printf("] \n");
    printf("Total Potensi Denda : Rp%d\n", hitungTotalDenda(dataHari));
}

int main()
{
    int dataHari[5];
    printf("Silahkan input hari keterlambatan untuk 5 Mahasiswa :\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Siswa ke-%d : ", i + 1);
        scanf("%d", &dataHari[i]);
    }
    printf("Data Berhasil disimpan!\n");
    while (true)
    {
        printf("\n\n------------------------------------\n");
        printf("\tMenu Utama\n");
        printf("------------------------------------\n");
        printf("1. Lihat Data & Total Potensi Denda\n");
        printf("2. Bayar Denda\n");
        printf("3. Keluar Aplikasi\n");
        int pilihan;
        printf("Masukkan pilihan Anda (1-3): ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            tampilData(dataHari);
            break;
        case 2:
            bayarDenda(dataHari);
            break;
        case 3:
            printf("Terima kasih telah menggunakan aplikasi ini. Sampai jumpa!\n");
            return 0;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
            break;
        }
    }
    return 0;
}