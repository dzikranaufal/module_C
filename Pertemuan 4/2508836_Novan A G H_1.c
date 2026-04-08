#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    Node *head = NULL;
    int pilihan;
    do
    {
        printf("=== Sistem Manajemen Pasien ===\n");
        // soal no 1
        printf("1. Tambah di Awal Daftar\n");
        printf("2. Tambah di Akhir Daftar\n");
        // soal no 2
        printf("3. Tambah Sebelum Pasien Tertentu\n");
        // soal no 3
        printf("4. Tambah Setelah Pasien Tertentu\n");
        printf("5. Tampil Daftar Pasien\n");
        printf("6. Update Data Pasien\n");
        printf("7. Hapus Data Pasien Awal\n");
        printf("8. Hapus Data Pasien Akhir\n");
        // soal no 4
        printf("9. Hapus Data Pasien Tertentu\n");
        printf("10. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        Node *newNode = (Node *)malloc(sizeof(Node));
        int idTarget;
        char nama[20], penyakit[20];

        switch (pilihan)
        {
        case 1:
            // Soal no 1
            inputDataPasien(newNode);
            insertAtFront(&head, newNode->ID, newNode->nama, newNode->penyakit);
            free(newNode);
            break;
        case 2:
            // Soal no 1
            inputDataPasien(newNode);
            insertAtEnd(&head, newNode->ID, newNode->nama, newNode->penyakit);
            free(newNode);
            break;
        case 3:
            // soal no 2
            inputDataPasien(newNode);
            char targetNama[20];
            printf("Masukkan Pasien sebelum nama: ");
            scanf(" %[^\n]", targetNama);
            insertMiddleBefore(&head, targetNama, newNode->ID, newNode->nama, newNode->penyakit);
            free(newNode);
            break;
        case 4:
            // Soal no 3
            inputDataPasien(newNode);
            printf("Masukkan Pasien setelah ID: ");
            scanf("%d", &idTarget);
            insertMiddleAfter(&head, idTarget, newNode->ID, newNode->nama, newNode->penyakit);
            free(newNode);
            break;
        case 5:
            // Soal no 1
            printList(head);
            break;
        case 6:
            // Soal no 3
            printf("Masukkan ID Pasien yang ingin diupdate: ");
            scanf("%d", &idTarget);
            printf("Masukkan Nama Baru: ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Penyakit Baru: ");
            scanf(" %[^\n]", penyakit);
            updateNode(head, idTarget, nama, penyakit);
            break;
        case 7:
            // Soal no 3
            deleteAtFront(&head);
            break;
        case 8:
            // Soal no 3
            deleteAtEnd(&head);
            break;
        case 9:
            // Soal no 4
            printf("Masukkan ID Pasien yang ingin dihapus: ");
            scanf("%d", &idTarget);
            deleteMiddle(&head, idTarget);
            break;
        case 10:
            printf("Keluar dari Program...\n");
            break;
        default:
            printf("Input tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 10);

    return 0;
}