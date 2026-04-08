#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Gerbong
{
    char kode_gerbong[10];
    char bawaan_gerbong[30];
    struct Gerbong *nextAlamat;
} Gerbong;

Gerbong *head = NULL;

void tambahDataGerbong()
{
    char kode_gerbong[10], bawaan_gerbong[30];
    printf("Masukkan Kode Gerbong : ");
    scanf(" %[^\n]", kode_gerbong);
    printf("Masukkan Barang bawaan Gerbong : ");
    scanf(" %[^\n]", bawaan_gerbong);
    Gerbong *gerbongBaru = (Gerbong *)malloc(sizeof(Gerbong));
    strcpy(gerbongBaru->kode_gerbong, kode_gerbong);
    strcpy(gerbongBaru->bawaan_gerbong, bawaan_gerbong);
    gerbongBaru->nextAlamat = NULL;
    if (head == NULL)
    {
        head = gerbongBaru;
    }
    else
    {
        Gerbong *temp = head;
        while (temp->nextAlamat != NULL)
        {
            temp = temp->nextAlamat;
        }
        temp->nextAlamat = gerbongBaru;
        printf("Data berhasil ditambahkan!\n");
    }
}

void tampilDataGerbong()
{
    printf("Urutan Gerbong Kereta Logistik : \n");
    if (head == NULL)
    {
        printf("Belum ada data Gerbong\n");
        return;
    }
    Gerbong *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("%d. %s - %s\n", i, temp->kode_gerbong, temp->bawaan_gerbong);
        temp = temp->nextAlamat;
        i++;
    }
    printf("\n");
    
}

int main()
{
    int pilihan = 1;

    while (pilihan)
    {
        printf("=== Manajemen Daftar Gerbong Kereta Logistik ===\n");
        printf("1. Tambah Data Gerbong\n");
        printf("2. Tampilkan Daftar Gerbong\n");
        printf("3. Keluar\n");
        printf("Pilih Menu : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            tambahDataGerbong();
            break;
        case 2:
            tampilDataGerbong();
            break;
        case 3:
            printf("Keluar dari program");
            return 0;
            break;
        default:
        printf("Kode tidak Valid");
            break;
        }
    }

    return 0;
}