#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Wisatawan
{
    char nama[30];
    int no_tiket;
    struct Wisatawan *nextAlamat;
} Wisatawan;
Wisatawan *head = NULL;
Wisatawan *createElement(char nama[30], int no_tiket)
{
    Wisatawan *wBaru = (Wisatawan *)malloc(sizeof(Wisatawan));
    strcpy(wBaru->nama, nama);
    wBaru->no_tiket = no_tiket;
    wBaru->nextAlamat = NULL;
    return wBaru;
}

void tambahAwal(char nama[30], int no_tiket)
{
    Wisatawan *temp = createElement(nama, no_tiket);
    temp->nextAlamat = head;
    head = temp;
    printf("Data berhasil ditambahkan!\n");
}

void tambahAkhir(char nama[30], int no_tiket)
{
    Wisatawan *wBaru = createElement(nama, no_tiket);
    if (head == NULL)
    {
        head = wBaru;
    }
    else
    {
        Wisatawan *temp = head;
        while (temp->nextAlamat != NULL)
        {
            temp = temp->nextAlamat;
        }
        temp->nextAlamat = wBaru;
        printf("Data berhasil ditambahkan!\n");
    }
}

void tambahSetelah(char nama[30], int no_tiket, int target)
{
    Wisatawan *wBaru = createElement(nama, no_tiket);
    if (head == NULL)
    {
        head = wBaru;
        return;
    }
    Wisatawan *temp = head;
    while (temp->no_tiket != target && temp != NULL)
    {
        temp = temp->nextAlamat;
    }
    if (temp != NULL)
    {
        wBaru->nextAlamat = temp->nextAlamat;
        temp->nextAlamat = wBaru;
        printf("Data berhasil ditambahkan!\n");
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void tambahSebelum(char nama[30], int no_tiket, int target)
{
    Wisatawan *wBaru = createElement(nama, no_tiket);
    if (head == NULL)
    {
        head = wBaru;
        return;
    }
    Wisatawan *temp = head;
    Wisatawan *prev = NULL;
    while (temp->no_tiket != target && temp != NULL)
    {
        prev = temp;
        temp = temp->nextAlamat;
    }
    if (temp != NULL)
    {
        prev->nextAlamat = wBaru;
        wBaru->nextAlamat = temp;
        printf("Data berhasil ditambahkan!\n");
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void tampilWisatawan()
{
    printf("Daftar Wisatawan Kereta : \n");
    if (head == NULL)
    {
        printf("Data Wisatawan Tidak Tersedia\n");
    }
    else
    {
        Wisatawan *temp = head;
        int i = 1;
        while (temp != NULL)
        {
            printf("%d. %s - %d\n", i, temp->nama, temp->no_tiket);
            temp = temp->nextAlamat;
            i++;
        }
    }
}

int main()
{
    int pilihan = 1;
    while (pilihan)
    {
        printf("=== Sistem Manajemen Wisatawan ===\n");
        printf("1. Tambah di Awal Daftar\n");
        printf("2. Tambah di Akhir Daftar\n");
        printf("3. Tambah Sebelum Wisatawan Tertentu\n");
        printf("4. Tambah Setelah Wisatawan Tertentu\n");
        printf("5. Tampil Daftar Wisatawan\n");
        printf("6. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        char nama[30];
        int no_tiket, target;
        switch (pilihan)
        {
        case 1:
            printf("Masukkan Nama : ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Nomor Tiket : ");
            scanf("%d", &no_tiket);
            tambahAwal(nama, no_tiket);
            break;
        case 2:
            printf("Masukkan Nama : ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Nomor Tiket : ");
            scanf("%d", &no_tiket);
            tambahAkhir(nama, no_tiket);
            break;
        case 3:
            printf("Masukkan Nama : ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Nomor Tiket : ");
            scanf("%d", &no_tiket);
            printf("Data akan dimasukan setelah nomor tiket : ");
            scanf("%d", &target);
            tambahSebelum(nama, no_tiket, target);
            break;
        case 4:
            printf("Masukkan Nama : ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Nomor Tiket : ");
            scanf("%d", &no_tiket);
            printf("Data akan dimasukan setelah nomor tiket : ");
            scanf("%d", &target);
            tambahSetelah(nama, no_tiket, target);
            break;

        case 5:
            tampilWisatawan();
            break;
        case 6:
            printf("Keluar dari Program...");
            return 0;
            break;

        default:
            printf("Input Tidak Valid\n");

            break;
        }
    }
    return 0;
}