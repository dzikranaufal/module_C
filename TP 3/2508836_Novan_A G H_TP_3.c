#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"

int main()
{
    Pengunjung *head = NULL;
    int pilihan;
    do
    {
        printf("\n=== Sistem Pendataan Wahana Roler Coaster ===\n");
        printf("1. Tambah Pengunjung\n");
        printf("2. Tampilkan Daftar Pengunjung\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            char nama[30], status[10];
            int tiket;
            printf("Masukkan Nama: ");
            scanf("%s", nama);
            printf("Masukkan Kategori (VIP/Reguler): ");
            scanf("%s", status);
            printf("Masukkan Nomor Tiket: ");
            scanf("%d", &tiket);

            if (strcmp(status, "VIP") == 0)
            {
                int cekAwal = 0;
                Pengunjung *temp = head;
                while (temp != NULL)
                {
                    if (strcmp(temp->status, "VIP") == 0)
                    {
                        cekAwal = 1;
                        break;
                    }
                    temp = temp->nextAlamat;
                }
                if (cekAwal == 1)
                {
                    int pilih, target;

                    printf("1. Tambah Tengah Sebelum Nomor Tiket\n");
                    printf("2. Tambah Tengah Setelah Nomor Tiket\n");
                    printf("Pilih posisi: ");
                    scanf("%d", &pilih);

                    printf("Masukkan nomor tiket target: ");
                    scanf("%d", &target);

                    if (pilih == 1)
                    {
                        tambahSebelum(&head, nama, tiket, status, target);
                    }
                    else
                    {
                        tambahSetelah(&head, nama, tiket, status, target);
                    }

                    printf("Pengunjung %s berhasil ditambahkan!\n", nama);
                }
                else
                {
                    tambahAwal(&head, nama, tiket, status);
                    printf("Pengunjung %s berhasil ditambahkan!\n", nama);
                }
            }
            else if (strcmp(status, "Reguler") == 0)
            {
                int cekAwal = 0;
                Pengunjung *temp = head;
                while (temp != NULL)
                {
                    if (strcmp(temp->status, "Reguler") == 0)
                    {
                        cekAwal = 1;
                        break;
                    }
                    temp = temp->nextAlamat;
                }
                if (cekAwal == 1)
                {
                    int pilih, target;
                    printf("1. Tambah Tengah Sebelum Nomor Tiket\n");
                    printf("2. Tambah Tengah Setelah Nomor Tiket\n");
                    printf("Pilih posisi: ");
                    scanf("%d", &pilih);
                    printf("Masukkan nomor tiket target: ");
                    scanf("%d", &target);

                    if (pilih == 1)
                    {
                        tambahSebelum(&head, nama, tiket, status, target);
                    }
                    else
                    {
                        tambahSetelah(&head, nama, tiket, status, target);
                    }

                    printf("Pengunjung %s berhasil ditambahkan!\n", nama);
                }
                else
                {
                    tambahAkhir(&head, nama, tiket, status);
                    printf("Pengunjung %s berhasil ditambahkan!\n", nama);
                }
            }
        }
        else if (pilihan == 2)
        {
            tampilPengunjung(&head);
        }
    } while (pilihan != 3);
    printf("Keluar dari program. Terima kasih!\n");
    return 0;
}