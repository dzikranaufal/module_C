#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1.h"

int main()
{
    Stack stack;
    init(&stack);
    int pilihan = 1;
    while (pilihan != 0)
    {
        printf("=== Menu Playlist ===\n");
        printf("1. Tambah Lagu\n");
        printf("2. Menghapus (Skip) Lagu\n");
        printf("3. Tampil Lagu\n");
        printf("0. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        char judul[50];
        switch (pilihan)
        {
        case 1:
            printf("Masukkan Judul Lagu : ");
            scanf(" %[^\n]", judul);
            push(&stack, judul);
            break;
        case 2:
        {
            char *data = pop(&stack);
            if (data != NULL)
            {
                printf("%s telah di-skip dari playlist\n", data);
            }
            break;
        }
        case 3:
            tampilPlaylist(&stack);
            break;
        case 0:
            printf("Keluar...\n");
            break;
        default:
            printf("Input tidak valid !!\n");
            break;
        }
    }
}