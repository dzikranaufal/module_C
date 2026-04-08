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

    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char nim[20];
        char nama[20];
        float nilai;
        printf("Masukkan data mahasiswa ke-%d:\n", i + 1);
        printf("NIM: ");
        scanf("%s", nim);
        printf("Nama: ");
        scanf("%s", nama);
        printf("Nilai: ");
        scanf("%f", &nilai);
        tambahAkhir(&head, nim, nama, nilai);
    }
    cetakList(head);

    return 0;
}