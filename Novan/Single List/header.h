#ifndef HEADER_H
#define HEADER_H
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

void insertMiddleBefore(Node **head, char targetNIM[], char nim[], char name[], char major[], int age)
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
    }
    else
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
    while (temp != NULL)
    {
        printf("NIM: %s\nName: %s\nMajor: %s\nAge: %d\n", temp->nim, temp->name, temp->major, temp->age);
        temp = temp->nextNode;
    }
}

void updateNode(Node *head, char targetNIM[], char newName[], char newMajor[], int newAge)
{

    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && strcmp(temp->nim, targetNIM) != 0)
    {
        temp = temp->nextNode;
    }
    if (temp != NULL)
    {
        strcpy(temp->name, newName);
        strcpy(temp->major, newMajor);
        temp->age = newAge;
        printf("Student with NIM %s succesfully updated.\n", targetNIM);
    }
    else
    {
        printf("NIM %s not found!.\n", targetNIM);
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
    printf("First Student data successfully deleted.\n");
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
    printf("Last Student data successfully deleted.\n");
}

void deleteMiddle(Node **head, char targetNIM[])
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->nim, targetNIM) != 0)
    {
        prev = temp;
        temp = temp->nextNode;
    }
    if (temp == NULL)
    {
        printf("NIM %s not found!.\n", targetNIM);
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
    printf("Student with NIM %s successfully deleted.\n", targetNIM);
}


#endif