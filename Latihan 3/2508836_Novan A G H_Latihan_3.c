#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char nim[20];
    char nama[20];
    float nilai;
    struct Node *nextNode;

} Node;

Node *createNode(char nim[], char nama[], float nilai)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->nim, nim);
    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;
    newNode->nextNode = NULL;
    return newNode;
}
Node *cariNim(Node *head, char nim[])
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->nim, nim) == 0)
        {
            return temp;
        }
        temp = temp->nextNode;
    }
    return NULL;
}

void tambahAwal(Node **head, char nim[], char nama[], float nilai)
{
    Node *newNode = createNode(nim, nama, nilai);
    newNode->nextNode = *head;
    *head = newNode;
}

void tambahAkhir(Node **head, char nim[], char nama[], float nilai)
{
    Node *newNode = createNode(nim, nama, nilai);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->nextNode != NULL)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}

void tambahSebelum(Node **head, char targetNIM[], char nim[], char nama[], float nilai)
{
    Node *newNode = createNode(nim, nama, nilai);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    if (strcmp((*head)->nim, targetNIM) == 0)
    {
        newNode->nextNode = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->nim, targetNIM) != 0)
    {
        prev = temp;
        temp = temp->nextNode;
    }
    if (temp != NULL)
    {
        newNode->nextNode = temp;
        prev->nextNode = newNode;
    }
    else
    {
        printf("Data tidak ditemukan!\n");
    }
}

void tambahSetelah(Node **head, char targetNIM[], char nim[], char nama[], float nilai)
{
    Node *newNode = createNode(nim, nama, nilai);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNIM) != 0)
    {
        temp = temp->nextNode;
    }
    if (temp != NULL)
    {
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }
    else
    {
        printf("Data tidak ditemukan!\n");
        free(newNode);
    }
}

void cetakList(Node *head)
{
    printf("=== Daftar Mahasiswa ===\n");
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        printf("%d. NIM: %s, Nama: %s, Nilai: %.2f\n", i + 1, temp->nim, temp->nama, temp->nilai);
        temp = temp->nextNode;
        i++;
    }
}

int main()
{
    Node *head = NULL;

    while (1)
    {
        char pilihan;
        printf("=== Kelola Data Mahasiswa ===\n");
        printf("1. Tambah Data diAwal\n");
        printf("2. Tambah Data setelah NIM Tertentu\n");
        printf("3. Tambah Data sebelum NIM Tertentu\n");
        printf("4. Cari Data Berdasarkan NIM\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf(" %c", &pilihan);
        switch (pilihan)
        {
        case '1':
        {
            char nim[20];
            char nama[20];
            float nilai;
            printf("Masukkan data mahasiswa baru:\n");
            printf("NIM: ");
            scanf("%s", nim);
            printf("Nama: ");
            scanf("%s", nama);
            printf("Nilai: ");
            scanf("%f", &nilai);
            tambahAwal(&head, nim, nama, nilai);
            break;
        }
        case '2':
        {
            char targetNIM[20];
            char nim[20];
            char nama[20];
            float nilai;
            printf("Masukkan NIM acuan (data akan ditambah setelah NIM ini): ");
            scanf("%s", targetNIM);
            printf("Masukkan data mahasiswa baru:\n");
            printf("NIM: ");
            scanf("%s", nim);
            printf("Nama: ");
            scanf("%s", nama);
            printf("Nilai: ");
            scanf("%f", &nilai);
            tambahSetelah(&head, targetNIM, nim, nama, nilai);
            break;
        }
        case '3':
        {
            char targetNIM[20];
            char nim[20];
            char nama[20];
            float nilai;
            printf("Masukkan NIM acuan (data akan ditambah sebelum NIM ini): ");
            scanf("%s", targetNIM);
            printf("Masukkan data mahasiswa baru:\n");
            printf("NIM: ");
            scanf("%s", nim);
            printf("Nama: ");
            scanf("%s", nama);
            printf("Nilai: ");
            scanf("%f", &nilai);
            tambahSebelum(&head, targetNIM, nim, nama, nilai);
            break;
        }
        case '4':
        {
            char nim[20];
            printf("Masukkan NIM yang ingin dicari: ");
            scanf("%s", nim);
            Node *result = cariNim(head, nim);
            if (result != NULL)
            {
                printf("Data ditemukan: NIM: %s, Nama: %s, Nilai: %.2f\n", result->nim, result->nama, result->nilai);
            }
            else
            {
                printf("Data tidak ditemukan.\n");
            }
            break;
        }
        case '5':
        {
            cetakList(head);
            break;
        }
        case '6':
        {
            printf("Keluar dari program.\n");
            return 0;
        }
        default:
        {
            printf("Pilihan tidak valid.\n");
            break;
        }
        }
    }

    return 0;
}