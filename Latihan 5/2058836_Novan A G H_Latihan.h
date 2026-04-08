#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int isbn;
    char judul[50];
    char pengarang[30];
    int tahun_terbit;
    struct Node *next;
    struct Node *prev;
} Node;
int isbn = 1000;

Node *createNode(char judul[50], char pengarang[30], int tahun_terbit, int is_edit)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (is_edit == 0)
    {
        newNode->isbn = ++isbn;
    }
    else
    {
        newNode->isbn = is_edit;
    }
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahun_terbit = tahun_terbit;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void tambahBuku(Node **head, char judul[50], char pengarang[30], int tahun_terbit, int is_edit)
{

    Node *newNode = createNode(judul, pengarang, tahun_terbit, is_edit);

    if (*head == NULL)
    {
        *head = newNode;
        printf("Buku Berhasil Di tambahkan !\n");
        return;
    }
    Node *temp = *head;

    while (temp->next != NULL && temp->tahun_terbit <= newNode->tahun_terbit)
    {
        temp = temp->next;
    }
    if (newNode->tahun_terbit < temp->tahun_terbit)
    {
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
        {
            temp->prev->next = newNode;
        }
        else
        {
            *head = newNode;
        }
        temp->prev = newNode;
        newNode->next = temp;
    }
    else
    {
        newNode->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Buku Berhasil Di tambahkan !\n");
}

void updateBuku(Node **head, int target)
{
    Node *temp = *head;
    while (temp != NULL && temp->isbn != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Buku tidak ditemukan !\n");
    }
    else
    {
        char judul[50], pengarang[30];
        int tahun_terbit;
        printf("Data Baru\n");
        printf("Judul : ");
        scanf(" %[^\n]", judul);
        printf("Pengarang : ");
        scanf(" %[^\n]", pengarang);
        printf("Tahun : ");
        scanf("%d", &tahun_terbit);

        int old_isbn = temp->isbn;
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            *head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
        tambahBuku(head, judul, pengarang, tahun_terbit, old_isbn);
    }
}

void hapusAwal(Node **head)
{
    if (*head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        Node *temp = *head;
        if ((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            (*head) = (*head)->next;
            (*head)->prev = NULL;
        }

        free(temp);
        printf("Data Berhasil Dihapus!\n");
    }
}

void hapusAkhir(Node **head)
{
    if (*head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        if ((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            Node *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
        printf("Data Berhasil dihapus!\n");
    }
}

void hapusBy(Node **head, int target)
{
    if (*head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        Node *temp = *head;
        while (temp != NULL && temp->isbn != target)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Data tidak ditemukan\n");
        }
        else
        {
            if (temp->prev == NULL)
            {
                if ((*head)->next != NULL)
                {
                    (*head) = (*head)->next;
                    (*head)->prev = NULL;
                }
                else
                {
                    (*head) = NULL;
                }

                free(temp);
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            printf("Data Berhasil Dihapus!\n");
        }
    }
}

void tampilBuku(Node *head)
{
    printf("=== Daftar Buku ===\n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("[%d] %d - %s [%s]\n", temp->isbn, temp->tahun_terbit, temp->judul, temp->pengarang);
        temp = temp->next;
    }
    printf("\n");
}