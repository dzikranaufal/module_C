// Nama : Novan Arrijal Ghifari Hakim S
// NIM  : 2508836
// Tanggal : 16-03-2026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char nim[10];
    char nama[50];
    char prodi[50];
    struct Node *prevNode;
    struct Node *nextNode;
} Node;

Node *createNode(char nim[], char nama[], char prodi[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->nim, nim);
    strcpy(newNode->nama, nama);
    strcpy(newNode->prodi, prodi);
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

void insertAtFront(Node **head, char nim[], char nama[], char prodi[])
{
    Node *newNode = createNode(nim, nama, prodi);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    (*head)->prevNode = newNode;
    newNode->nextNode = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, char nim[], char nama[], char prodi[])
{

    Node *newNode = createNode(nim, nama, prodi);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
    newNode->prevNode = temp;
}

void insertMiddleBefore(Node **head, char nimTarget[], char nim[], char nama[], char prodi[])
{
    Node *newNode = createNode(nim, nama, prodi);

    if (*head == NULL)
    {
        printf("List Kosong\n");
        return;
    }

    Node *temp = *head;
    while (temp != NULL && strcmp(temp->nim, nimTarget) != 0)
    {
        temp = temp->nextNode;
    }

    if (temp == NULL)
    {
        printf("Target NIM tidak ditemukan.\n");
        return;
    }

    if (temp->prevNode == NULL)
    {
        newNode->nextNode = temp;
        temp->prevNode = newNode;
        *head = newNode;
        return;
    }

    newNode->nextNode = temp;
    newNode->prevNode = temp->prevNode;
    temp->prevNode->nextNode = newNode;
    temp->prevNode = newNode;
}

void insertMiddleAfter(Node **head, char targetNim[], char nim[], char nama[], char prodi[])
{

    Node *newNode = createNode(nim, nama, prodi);

    if (*head == NULL)
    {
        printf("List is empty. cannot insert after a target.\n");
        return;
    }

    Node *temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0)
    {
        temp = temp->nextNode;
    }

    if (temp == NULL)
    {
        printf("Target nim not found.\n");
        return;
    }

    if (temp->nextNode == NULL)
    {
        temp->nextNode = newNode;
        newNode->prevNode = temp;
        newNode->nextNode = NULL;
        return;
    }

    newNode->nextNode = temp->nextNode;
    newNode->prevNode = temp;
    temp->nextNode->prevNode = newNode;
    temp->nextNode = newNode;
}

void update(Node *head, char targetNIM[], char namaBaru[], char prodiBaru[]){
    Node *temp = head;
    while (temp != NULL && strcmp(temp->nim, targetNIM) != 0)
    {
        temp = temp->nextNode;
    }
    
}

void printForward(Node *head)
{
    Node *temp = head;
    printf("Forward List:\n");
    while (temp != NULL)
    {
        printf("NIM: %s | Nama: %s | Prodi: %s\n", temp->nim, temp->nama, temp->prodi);
        temp = temp->nextNode;
    }
    printf("\n");
}

void printBackward(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List masih kosong.\n");
        return;
    }
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    printf("Reverse List:\n");
    while (temp != NULL)
    {
        printf("NIM: %s | Nama: %s | Prodi: %s\n", temp->nim, temp->nama, temp->prodi);
        temp = temp->prevNode;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    insertAtEnd(&head, "240101", "Wise", "Informatika");
    insertAtEnd(&head, "240838", "Belle", "Kalkulus");
    insertAtEnd(&head, "250408", "Stelle", "SistemInformasi");
    printForward(head);

    insertMiddleAfter(&head, "240838", "240923", "Caelus", "Seni");
    insertMiddleBefore(&head, "240838", "248883", "Kafka", "IndustriKomputer");
    printForward(head);
    printBackward(head);
}