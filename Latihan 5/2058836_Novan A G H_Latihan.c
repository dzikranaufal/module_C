#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    Node *head = NULL;
    int pilihan = 1;
    while (pilihan != 0)
    {
        printf("===== Sistem Manajemen Perpustakaan =====\n");
        printf("1. Tambah Buku\n");
        printf("2. Update Buku by ISBN\n");
        printf("3. Hapus Awal\n");
        printf("4. Hapus Akhir\n");
        printf("5. Hapus by ISBN\n");
        printf("6. Tampil Semua Buku\n");
        printf("0. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        char judul[50], pengarang[30];
        int tahun_terbit, target;
        switch (pilihan)
        {
        case 1:
            printf("Input Buku\n");
            printf("Judul : ");
            scanf(" %[^\n]", judul);
            printf("Pengarang : ");
            scanf(" %[^\n]", pengarang);
            printf("Tahun : ");
            scanf("%d", &tahun_terbit);
            tambahBuku(&head, judul, pengarang, tahun_terbit, 0);
            break;
        case 2:
            printf("Target ISBN : ");
            scanf("%d", &target);
            updateBuku(&head, target);
            break;
        case 3:
            hapusAwal(&head);
            break;
        case 4:
            hapusAkhir(&head);
            break;
        case 5:
            printf("Target ISBN : ");
            scanf("%d", &target);
            hapusBy(&head, target);
            break;
        case 6:
            tampilBuku(head);
            break;

        default:
            break;
        }
    }
}