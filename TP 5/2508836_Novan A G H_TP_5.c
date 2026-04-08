#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    Song *head = NULL;
    int pilihan = 1;
    while (pilihan != 0)
    {
        printf("=== MYVIBE PLAYLIST MANAGER ===\n");
        printf("1. Tambah Lagu\n");
        printf("2. Tampil Playlist (Forward)\n");
        printf("3. Tampil Playlist (Backward)\n");
        printf("4. Update Judul\n");
        printf("5. Update Durasi (re-sort)\n");
        printf("6. Hapus Lagu Pertama\n");
        printf("7. Hapus Lagu Terakhir\n");
        printf("8. Hapus berdasarkan Judul\n");
        printf("0. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &pilihan);
        char title[45], mood[15];
        int duration, target;
        switch (pilihan)
        {
        case 1:
            printf("\n=== Add Song ===\n");
            printf("Judul : ");
            scanf(" %[^\n]", title);
            printf("Mood : ");
            scanf(" %[^\n]", mood);
            printf("Durasi (detik) : ");
            scanf("%d", &duration);
            addSong(&head, title, mood, duration, 0);
            printf("Song added successfully!\n");
            break;
        case 2:
            showForward(head);
            break;
        case 3:
            showBackward(head);
            break;
        case 4:
            printf("ID target : ");
            scanf("%d", &target);
            updateTitle(&head, target);
            break;
        case 5:
            printf("ID target :");
            scanf("%d", &target);
            updateDuration(&head, target);
            break;

        case 6:
            deleteFirst(&head);
            break;

        case 7:
            deleteLast(&head);
            break;

        case 8:
            printf("Judul Target :");
            scanf(" %[^\n]", title);
            deleteBy(&head, title);
            break;

        default:
            break;
        }
    }
}