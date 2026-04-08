#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char nim[20];
    char name[20];
    char major[20];
    int age;
    struct Node *nextNode;

} Node;

Node *createNode(char nim[], char name[], char major[], int age)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->nim, nim);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->age = age;
    newNode->nextNode = NULL;
    return newNode;
}

void insertAtFront(Node **head, char nim[], char name[], char major[], int age)
{
    Node *newNode = createNode(nim, name, major, age);
    newNode->nextNode = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, char nim[], char name[], char major[], int age)
{
    Node *newNode = createNode(nim, name, major, age);
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

void insertMiddleBefore(Node **head, char targetNIM[],  char nim[], char name[], char major[], int age)
{
    Node *newNode = createNode(nim, name, major, age);
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
    }else
    {
        printf("Target tidak ditemukan!\n");
    }
    
}

void insertMiddleAfter(Node **head, char targetNIM[], char nim[], char name[], char major[], int age)
{
    Node *newNode = createNode(nim, name, major, age);
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
    }else
    {
        printf("Target tidak ditemukan!\n");
        free(newNode);
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("NIM: %s\nName: %s\nMajor: %s\nAge: %d\n", temp->nim, temp->name, temp->major, temp->age);
        temp = temp->nextNode;
    }
}

int main()
{
    Node *head = NULL;
    
    insertAtFront(&head, "2508836", "Aufaa", "Pendidikan Ilmu Komputer", 20);
    insertAtFront(&head, "2508840", "Rina", "Pendidikan Ilmu Komputer", 19);

    insertAtEnd(&head, "2508837", "Mike", "Ilmu Komputer", 22);
    insertAtEnd(&head, "2508841", "Dedi", "Ilmu Komputer", 20);

    insertMiddleBefore(&head, "2508837", "2508838", "Zahid", "Sistem Informasi", 21);
    insertMiddleBefore(&head, "2508836", "2508842", "Nina", "Sistem Informasi", 21);

    insertMiddleAfter(&head, "2508836", "2508839", "Novan", "Teknik Informatika", 23);
    insertMiddleAfter(&head, "2508837", "2508843", "Rio", "Teknik Informatika", 22);

    printList(head);
    return 0;
}