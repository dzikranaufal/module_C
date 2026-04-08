#ifndef PENGUNJUNG_H
#define PENGUNJUNG_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Pengunjung
{
    char nama[30];
    int no_tiket;
    char status[10];
    struct Pengunjung *nextAlamat;
} Pengunjung;

Pengunjung *createElement(char nama[30], int no_tiket, char status[])
{
    Pengunjung *pBaru = (Pengunjung *)malloc(sizeof(Pengunjung));
    strcpy(pBaru->nama, nama);
    pBaru->no_tiket = no_tiket;
    strcpy(pBaru->status, status);
    pBaru->nextAlamat = NULL;
    return pBaru;
}

void tambahAwal(Pengunjung **head, char nama[30], int no_tiket, char status[])
{
    Pengunjung *pBaru = createElement(nama, no_tiket, status);
    pBaru->nextAlamat = *head;
    *head = pBaru;
}

void tambahAkhir(Pengunjung **head, char nama[30], int no_tiket, char status[])
{
    Pengunjung *pBaru = createElement(nama, no_tiket, status);
    if (*head == NULL)
    {
        *head = pBaru;
    }
    else
    {
        Pengunjung *temp = *head;
        while (temp->nextAlamat != NULL)
        {
            temp = temp->nextAlamat;
        }
        temp->nextAlamat = pBaru;
    }
}

void tambahSetelah(Pengunjung **head, char nama[30], int no_tiket, char status[], int target)
{
    Pengunjung *pBaru = createElement(nama, no_tiket, status);
    if (*head == NULL)
    {
        *head = pBaru;
        return;
    }
    Pengunjung *temp = *head;
    while (temp != NULL && temp->no_tiket != target)
    {
        temp = temp->nextAlamat;
    }
    if (temp != NULL)
    {
        pBaru->nextAlamat = temp->nextAlamat;
        temp->nextAlamat = pBaru;
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void tambahSebelum(Pengunjung **head, char nama[30], int no_tiket, char status[], int target)
{
    Pengunjung *pBaru = createElement(nama, no_tiket, status);
    if (*head == NULL)
    {
        *head = pBaru;
        return;
    }
    Pengunjung *temp = *head;
    Pengunjung *prev = NULL;
    while (temp != NULL && temp->no_tiket != target)
    {
        prev = temp;
        temp = temp->nextAlamat;
    }
    if (temp != NULL)
    {
        if (prev == NULL)
        {
            pBaru->nextAlamat = *head;
            *head = pBaru;
        }
        else
        {
            prev->nextAlamat = pBaru;
            pBaru->nextAlamat = temp;
        }
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}

void tampilPengunjung(Pengunjung **head)
{
    printf("Daftar Pengunjung : \n");
    if (*head == NULL)
    {
        printf("Data Pengunjung Tidak Ada\n");
    }
    else
    {
        Pengunjung *temp = *head;
        int i = 1;
        while (temp != NULL)
        {
            printf("%d. %s - %s - nomor tiket %d\n", i, temp->nama, temp->status, temp->no_tiket);
            temp = temp->nextAlamat;
            i++;
        }
    }
}

#endif