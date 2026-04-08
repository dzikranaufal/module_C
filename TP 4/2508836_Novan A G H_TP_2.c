#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kopi.h"

int main()
{
    Pelanggan *head = NULL;
    int pilihan = 1;
    int no_antrean;
    char nama[30];
    char pesanan[100];
    int no_target;

    while (pilihan != 0)
    {
        printf("=== Kopi Wesker === \n");
        printf("1. Tambah Antrean Biasa (belakang)\n");
        printf("2. Tambah Antrean VIP (depan)\n");
        printf("3. Sisipkan Sebelum Nomor tertentu\n");
        printf("4. Sisipkan Sesudah Nomor tertentu\n");
        printf("5. Hapus Antrean Spesifik\n");
        printf("6. Update Data Pesanan\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            templateInput(&no_antrean, nama, pesanan);
            tambahPelangganAkhir(&head, no_antrean, nama, pesanan);
            tampilPelanggan(head);
            break;
        case 2:
            templateInput(&no_antrean, nama, pesanan);
            tambahPelangganAwal(&head, no_antrean, nama, pesanan);
            tampilPelanggan(head);
            break;
        case 3:
            printf("Cari Nomor antrian Target :");
            scanf("%d", &no_target);
            templateInput(&no_antrean, nama, pesanan);
            sisipkanPelangganSebelum(&head, no_antrean, nama, pesanan, no_target);
            tampilPelanggan(head);
            break;
        case 4:
            printf("Cari Nomor antrian Target :");
            scanf("%d", &no_target);
            templateInput(&no_antrean, nama, pesanan);
            sisipkanPelangganSetelah(&head, no_antrean, nama, pesanan, no_target);
            tampilPelanggan(head);
            break;
        case 5:
            printf("Cari Nomor antrian Target :");
            scanf("%d", &no_target);
            hapusPelangganByNomor(&head, no_target);
            tampilPelanggan(head);
            break;
        case 6:
            printf("Cari Nomor antrian Target :");
            scanf("%d", &no_target);
            printf("Masukkan Pesanan Baru: ");
            scanf(" %[^\n]", pesanan);
            updateDataPelanggan(head, no_target, pesanan);
            tampilPelanggan(head);
            break;
        default:
            printf("Pilihan tidak valid! Silakan coba lagi.\n");
            break;
        }
    }

    printf("Program Selesai\n");

    return 0;
}