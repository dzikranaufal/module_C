#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int ID;
    char nama[20];
    char penyakit[20];
    struct Node *nextNode;

} Node;

Node *createNode(int ID, char nama[], char penyakit[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ID = ID;
    strcpy(newNode->nama, nama);
    strcpy(newNode->penyakit, penyakit);
    newNode->nextNode = NULL;
    return newNode;
}

void inputDataPasien(Node *node)
{
    printf("Masukkan ID: ");
    scanf("%d", &node->ID);
    printf("Masukkan Name: ");
    scanf(" %[^\n]", node->nama);
    printf("Masukkan Penyakit: ");
    scanf(" %[^\n]", node->penyakit);
}

void insertAtFront(Node **head, int ID, char nama[], char penyakit[])
{
    Node *newNode = createNode(ID, nama, penyakit);
    newNode->nextNode = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int ID, char nama[], char penyakit[])
{
    Node *newNode = createNode(ID, nama, penyakit);
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

void insertMiddleBefore(Node **head, char namaTarget[], int ID, char nama[], char penyakit[])
{
    Node *newNode = createNode(ID, nama, penyakit);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    if (strcmp((*head)->nama, namaTarget) == 0)
    {
        newNode->nextNode = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->nama, namaTarget) != 0)
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
        printf("Target tidak ditemukan!\n");
    }
}

void insertMiddleAfter(Node **head, int targetID, int ID, char nama[], char penyakit[])
{
    Node *newNode = createNode(ID, nama, penyakit);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp != NULL && temp->ID != targetID)
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
        printf("Target tidak ditemukan!\n");
        free(newNode);
    }
}

void printList(Node *head)
{
    Node *temp = head;
    printf("=== Daftar Pasien ===\n");
    while (temp != NULL)
    {
        printf("ID: %d | Name: %s\t| Penyakit: %s\n", temp->ID, temp->nama, temp->penyakit);
        temp = temp->nextNode;
    }
}

void updateNode(Node *head, int targetID, char newName[], char penyakit[])
{

    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->ID != targetID)
    {
        temp = temp->nextNode;
    }
    if (temp != NULL)
    {
        strcpy(temp->nama, newName);
        strcpy(temp->penyakit, penyakit);
        printf("Pasien with ID %d succesfully updated.\n", targetID);
    }
    else
    {
        printf("ID %d not found!.\n", targetID);
    }
}
void deleteAtFront(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->nextNode;
    temp->nextNode = NULL;
    free(temp);
    printf("First Pasien data successfully deleted.\n");
}

void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp->nextNode != NULL)
    {
        prev = temp;
        temp = temp->nextNode;
    }
    if (prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev->nextNode = NULL;
    }
    free(temp);
    printf("Last Pasien data successfully deleted.\n");
}

void deleteMiddle(Node **head, int targetID)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && temp->ID != targetID)
    {
        prev = temp;
        temp = temp->nextNode;
    }
    if (temp == NULL)
    {
        printf("ID %d not found!.\n", targetID);
        return;
    }
    if (prev == NULL)
    {
        *head = temp->nextNode;
    }
    else
    {
        prev->nextNode = temp->nextNode;
        temp->nextNode = NULL;
    }
    free(temp);
    printf("Pasien with ID %d successfully deleted.\n", targetID);
}

#endif