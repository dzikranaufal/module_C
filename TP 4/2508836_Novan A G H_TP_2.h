#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pelanggan
{
    int no_antrean;
    char nama[30];
    char pesanan[100];
    struct Pelanggan *nextPelanggan;
} Pelanggan;

void templateInput(int *no_antrean, char nama[], char pesanan[])
{
    printf("Masukkan Nomor Pelanggan: ");
    scanf("%d", no_antrean);
    printf("Masukkan Nama Pelanggan: ");
    scanf(" %[^\n]", nama);
    printf("Masukkan Pesanan: ");
    scanf(" %[^\n]", pesanan);
}

Pelanggan *createPelanggan(int no_antrean, char nama[], char pesanan[])
{
    Pelanggan *newPelanggan = (Pelanggan *)malloc(sizeof(Pelanggan));
    newPelanggan->no_antrean = no_antrean;
    strcpy(newPelanggan->nama, nama);
    strcpy(newPelanggan->pesanan, pesanan);
    newPelanggan->nextPelanggan = NULL;
    return newPelanggan;
}

Pelanggan *cariPelangganByNomor(Pelanggan *head, int no_antrean)
{
    Pelanggan *temp = head;
    while (temp != NULL)
    {
        if (temp->no_antrean == no_antrean)
        {
            return temp;
        }
        temp = temp->nextPelanggan;
    }
    return NULL;
}

bool cekNomorUnik(Pelanggan *head, int no_antrean)
{
    if (cariPelangganByNomor(head, no_antrean) != NULL)
    {
        printf("Nomor sudah digunakan!\n");
        return false;
    }
    return true;
}

void tambahPelangganAwal(Pelanggan **head, int no_antrean, char nama[], char pesanan[])
{
    if (!cekNomorUnik(*head, no_antrean))
    {
        return;
    }

    Pelanggan *newPelanggan = createPelanggan(no_antrean, nama, pesanan);
    newPelanggan->nextPelanggan = *head;
    *head = newPelanggan;
    printf("Pelanggan berhasil ditambahkan di awal daftar!\n");
}

void tambahPelangganAkhir(Pelanggan **head, int no_antrean, char nama[], char pesanan[])
{
    if (!cekNomorUnik(*head, no_antrean))
    {
        return;
    }
    Pelanggan *newPelanggan = createPelanggan(no_antrean, nama, pesanan);
    if (*head == NULL)
    {
        *head = newPelanggan;
        return;
    }

    Pelanggan *temp = *head;
    while (temp->nextPelanggan != NULL)
    {
        temp = temp->nextPelanggan;
    }
    temp->nextPelanggan = newPelanggan;
    printf("Pelanggan berhasil ditambahkan di akhir daftar!\n");
}

void sisipkanPelangganSetelah(Pelanggan **head, int no_antrean, char nama[], char pesanan[], int no_target)
{
    if (!cekNomorUnik(*head, no_antrean))
    {
        return;
    }
    Pelanggan *newPelanggan = createPelanggan(no_antrean, nama, pesanan);
    Pelanggan *temp = cariPelangganByNomor(*head, no_target);
    if (temp == NULL)
    {
        printf("Nomor target antrian tidak ditemukan!\n");
        free(newPelanggan);
        return;
    }
    newPelanggan->nextPelanggan = temp->nextPelanggan;
    temp->nextPelanggan = newPelanggan;
    printf("Pelanggan berhasil disisipkan setelah Nomor %d!\n", no_target);
}

void sisipkanPelangganSebelum(Pelanggan **head, int no_antrean, char nama[], char pesanan[], int no_target)
{
    if (!cekNomorUnik(*head, no_antrean))
    {
        return;
    }
    Pelanggan *newPelanggan = createPelanggan(no_antrean, nama, pesanan);
    if (*head == NULL || (*head)->no_antrean == no_target)
    {
        newPelanggan->nextPelanggan = *head;
        *head = newPelanggan;
        return;
    }

    Pelanggan *temp = *head;
    while (temp->nextPelanggan != NULL && temp->nextPelanggan->no_antrean != no_target)
    {
        temp = temp->nextPelanggan;
    }
    if (temp->nextPelanggan == NULL)
    {
        printf("Nomor target antrian tidak ditemukan!\n");
        free(newPelanggan);
        return;
    }

    newPelanggan->nextPelanggan = temp->nextPelanggan;
    temp->nextPelanggan = newPelanggan;
    printf("Pelanggan berhasil disisipkan sebelum Nomor %d!\n", no_target);
}

void tampilPelanggan(Pelanggan *head)
{
    if (head == NULL)
    {
        printf("Tidak ada pelanggan dalam list!\n");
        return;
    }
    printf("DAFTAR PELANGGAN\n");
    printf("=============================================\n");
    Pelanggan *temp = head;
    while (temp != NULL)
    {
        printf("[%d] %s - Pesanan: %s\n", temp->no_antrean, temp->nama, temp->pesanan);
        temp = temp->nextPelanggan;
    }
    printf("=============================================\n");
}

void updateDataPelanggan(Pelanggan *head, int no_antrean, char pesanan_baru[])
{
    Pelanggan *temp = cariPelangganByNomor(head, no_antrean);
    if (temp == NULL)
    {
        printf("Nomor antrian tidak ditemukan!\n");
        return;
    }
    strcpy(temp->pesanan, pesanan_baru);
    printf("Data pelanggan dengan Nomor %d berhasil diperbarui!\n", no_antrean);
}

void hapusPelangganByNomor(Pelanggan **head, int no_target)
{
    if (*head == NULL)
    {
        printf("Tidak ada pelanggan dalam list!\n");
        return;
    }
    if ((*head)->no_antrean == no_target)
    {
        Pelanggan *temp = *head;
        *head = (*head)->nextPelanggan;
        free(temp);
        printf("Pelanggan dengan Nomor %d berhasil dihapus!\n", no_target);
        return;
    }

    Pelanggan *temp = *head;
    while (temp->nextPelanggan != NULL && temp->nextPelanggan->no_antrean != no_target)
    {
        temp = temp->nextPelanggan;
    }
    if (temp->nextPelanggan == NULL)
    {
        printf("Nomor antrian tidak ditemukan!\n");
        return;
    }

    Pelanggan *pelanggan_hapus = temp->nextPelanggan;
    temp->nextPelanggan = pelanggan_hapus->nextPelanggan;
    free(pelanggan_hapus);
    printf("Pelanggan dengan Nomor %d berhasil dihapus!\n", no_target);
}
