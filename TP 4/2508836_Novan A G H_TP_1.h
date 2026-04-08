#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifndef BIOSKOP_H
#define BIOSKOP_H

typedef struct Film
{
    int id;
    char judul[100];
    char jam_tayang[10];
    struct Film *nextFilm;
} Film;

void templateInput(int *id, char judul[], char jam_tayang[])
{
    printf("Masukkan ID Film: ");
    scanf("%d", id);
    printf("Masukkan Judul Film: ");
    scanf(" %[^\n]", judul);
    printf("Masukkan Jam Tayang (HH:MM): ");
    scanf(" %[^\n]", jam_tayang);
}

Film *createFilm(int id, char judul[], char jam_tayang[])
{
    Film *newFilm = (Film *)malloc(sizeof(Film));
    newFilm->id = id;
    strcpy(newFilm->judul, judul);
    strcpy(newFilm->jam_tayang, jam_tayang);
    newFilm->nextFilm = NULL;
    return newFilm;
}

Film *cariFilmById(Film *head, int id)
{
    Film *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->nextFilm;
    }
    return NULL;
}

bool cekIdUnik(Film *head, int id)
{
    if (cariFilmById(head, id) != NULL)
    {
        printf("ID sudah digunakan! Masukkan ID unik.\n");
        return false;
    }
    return true;
}

void tambahFilmAwal(Film **head, int id, char judul[], char jam_tayang[])
{
    if (!cekIdUnik(*head, id))
    {
        return;
    }

    Film *newFilm = createFilm(id, judul, jam_tayang);
    newFilm->nextFilm = *head;
    *head = newFilm;
    printf("Film berhasil ditambahkan di awal daftar!\n");
}

void tambahFilmAkhir(Film **head, int id, char judul[], char jam_tayang[])
{
    if (!cekIdUnik(*head, id))
    {
        return;
    }
    Film *newFilm = createFilm(id, judul, jam_tayang);
    if (*head == NULL)
    {
        *head = newFilm;
        return;
    }

    Film *temp = *head;
    while (temp->nextFilm != NULL)
    {
        temp = temp->nextFilm;
    }
    temp->nextFilm = newFilm;
    printf("Film berhasil ditambahkan di akhir daftar!\n");
}

void sisipkanFilmSetelah(Film **head, int id, char judul[], char jam_tayang[], int id_target)
{
    if (!cekIdUnik(*head, id))
    {
        return;
    }
    Film *newFilm = createFilm(id, judul, jam_tayang);
    Film *temp = cariFilmById(*head, id_target);
    if (temp == NULL)
    {
        printf("ID target tidak ditemukan!\n");
        free(newFilm);
        return;
    }
    newFilm->nextFilm = temp->nextFilm;
    temp->nextFilm = newFilm;
    printf("Film berhasil disisipkan setelah ID %d!\n", id_target);
}

void sisipkanFilmSebelum(Film **head, int id, char judul[], char jam_tayang[], int id_target)
{
    if (!cekIdUnik(*head, id))
    {
        return;
    }
    Film *newFilm = createFilm(id, judul, jam_tayang);
    if (*head == NULL || (*head)->id == id_target)
    {
        newFilm->nextFilm = *head;
        *head = newFilm;
        return;
    }

    Film *temp = *head;
    while (temp->nextFilm != NULL && temp->nextFilm->id != id_target)
    {
        temp = temp->nextFilm;
    }
    if (temp->nextFilm == NULL)
    {
        printf("ID target tidak ditemukan!\n");
        free(newFilm);
        return;
    }

    newFilm->nextFilm = temp->nextFilm;
    temp->nextFilm = newFilm;
    printf("Film berhasil disisipkan sebelum ID %d!\n", id_target);
}

void lihatJadwalTayang(Film *head)
{
    if (head == NULL)
    {
        printf("Jadwal tayang kosong!\n");
        return;
    }
    printf("DAFTAR JADWAL TAYANG BIOSKOP:\n");
    printf("=============================================\n");
    Film *temp = head;
    while (temp != NULL)
    {
        printf("ID: %-3d | %-20s | Pukul: %s\n", temp->id, temp->judul, temp->jam_tayang);
        temp = temp->nextFilm;
    }
    printf("=============================================\n");
}

void updateDataFilm(Film *head, int id, char judul_baru[], char jam_tayang_baru[])
{
    Film *temp = cariFilmById(head, id);
    if (temp == NULL)
    {
        printf("ID tidak ditemukan!\n");
        return;
    }
    strcpy(temp->judul, judul_baru);
    strcpy(temp->jam_tayang, jam_tayang_baru);
    printf("Data film dengan ID %d berhasil diperbarui!\n", id);
}
void hapusJadwalAwal(Film **head)
{
    if (*head == NULL)
    {
        printf("Jadwal tayang kosong!\n");
        return;
    }
    Film *temp = *head;
    *head = (*head)->nextFilm;
    free(temp);
    printf("Jadwal pertama berhasil dihapus!\n");
}
void hapusJadwalAkhir(Film **head)
{
    if (*head == NULL)
    {
        printf("Jadwal tayang kosong!\n");
        return;
    }
    if ((*head)->nextFilm == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Film *temp = *head;
    while (temp->nextFilm->nextFilm != NULL)
    {
        temp = temp->nextFilm;
    }
    free(temp->nextFilm);
    temp->nextFilm = NULL;
    printf("Jadwal terakhir berhasil dihapus!\n");
}

#endif