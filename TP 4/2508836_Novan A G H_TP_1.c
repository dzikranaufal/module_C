#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"

int main()
{
    Film *head = NULL;
    tambahFilmAkhir(&head, 101, "Avatar Endgame", "14:00");
    tambahFilmAkhir(&head, 102, "KKN di Desa Penari", "16:00");
    int pilihan;
    int id;
    char judul[100];
    char jam_tayang[10];
    do
    {
        printf("=== Manajemen Bioskop=== \n");
        printf("1. Tambah Film di Awal\n");
        printf("2. Tambah Film di Akhir\n");
        printf("3. Sisipkan Film (Sebelum/Sesudah ID tertentu)\n");
        printf("4. Lihat Jadwal Tayang\n");
        printf("5. Perbarui Data Film (berdasarkan ID)\n");
        printf("6. Hapus Jadwal (Awal/Akhir)\n");
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            templateInput(&id, judul, jam_tayang);
            tambahFilmAwal(&head, id, judul, jam_tayang);
            break;
        case 2:
            templateInput(&id, judul, jam_tayang);
            tambahFilmAkhir(&head, id, judul, jam_tayang);
            break;
        case 3:
            printf("Pilih opsi sisipkan: \n1. Setelah ID tertentu \n2. Sebelum ID tertentu\n");
            int opsi_sisip;
            printf("Pilihan: ");
            scanf("%d", &opsi_sisip);
            printf("Masukkan ID target: ");
            int id_target;
            scanf("%d", &id_target);
            templateInput(&id, judul, jam_tayang);
            if (opsi_sisip == 1)
            {
                sisipkanFilmSetelah(&head, id, judul, jam_tayang, id_target);
            }
            else if (opsi_sisip == 2)
            {
                sisipkanFilmSebelum(&head, id, judul, jam_tayang, id_target);
            }
            else
            {
                printf("Opsi tidak valid!\n");
            }
            break;
        case 4:
            lihatJadwalTayang(head);
            break;
        case 5:
            printf("Masukkan ID film yang ingin diperbarui: ");
            int id_update;
            scanf("%d", &id_update);
            printf("Masukkan Judul Film: ");
            scanf(" %[^\n]", judul);
            printf("Masukkan Jam Tayang (HH:MM): ");
            scanf(" %[^\n]", jam_tayang);
            updateDataFilm(head, id_update, judul, jam_tayang);
            break;
        case 6:
            printf("Pilih opsi hapus: \n1. Awal \n2. Akhir\n");
            printf("Pilihan: ");
            int opsi_hapus;
            scanf("%d", &opsi_hapus);
            if (opsi_hapus == 1)
            {
                hapusJadwalAwal(&head);
            }
            else if (opsi_hapus == 2)
            {
                hapusJadwalAkhir(&head);
            }
            else
            {
                printf("Opsi tidak valid!\n");
            }
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
        }

    } while (pilihan != 7);
    printf("Program Selesai\n");

    return 0;
}