#include <stdio.h>
#include <stdbool.h>

bool cekKursi(int kursi[], int nomor_kursi)
{
    return kursi[nomor_kursi - 1] == 0;
}
void pesanKursi(int kursi[], int nomor_kursi)
{
    kursi[nomor_kursi - 1] = 1;
}
int main()
{
    int kursi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int nomor_kursi;
    char pilihan = 'y';
    while (pilihan == 'y')
    {
        printf("Status Kursi [0 = Kosong, 1 = Terisi] :\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", kursi[i]);
        }
        printf("\nMasukkan Nomor Kursi yang ingin dipesan (1-10): ");
        scanf("%d", &nomor_kursi);
        bool status = cekKursi(kursi, nomor_kursi);
        if (status)
        {
            pesanKursi(kursi, nomor_kursi);
            printf(">> Booking Berhasil untuk kursi No %d!\n", nomor_kursi);
        }
        else
        {
            printf("Maaf, kursi nomor %d sudah dipesan.\n", nomor_kursi);
        }
        printf("Ingin memesan lagi? (y/n): ");
        scanf(" %c", &pilihan);
    }
}