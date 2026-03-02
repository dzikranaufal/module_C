#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Node* createNode(char nim[], char name[], char major[], int age){
    Node *newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->nim, nim);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->age= age;
    newNode->nextNode = NULL;

    return newNode;
}

void addFirst(Node **head, char nim[], char name[], char major[], int age){
    Node  *newNode = createNode(nim, name, major, age);
    newNode->nextNode = *head;
    *head = newNode;
}

void addLast(Node **head, char nim[], char name[], char major[], int age){
    Node *newNode = createNode(nim, name, major, age);

    if(*head == NULL){
        *head = newNode;
    }else{
        Node *temp = *head;
        while (temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}

void addMiddleBefore(Node **head, char targetNim[], char nim[], char name[], char major[], int age){
    Node *newNode = createNode(nim, name, major, age);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    if (strcmp((*head)->nim, targetNim) == 0){
        newNode->nextNode = *head;
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0){
        prev = temp;
        temp = temp->nextNode;
    }
}

void addMiddleAfter(Node **head, char targetNim[], char nim[], char name[], char major[], int age){
    Node *newNode = createNode(nim, name, major, age);

    if (*head == NULL){
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0){
        temp = temp->nextNode;
    }

    if(temp != NULL){
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }else{
        printf("Target tidak ditemukan");
        free(newNode);
    }
    
}

void update(Node **head, char targetNim[], char newName[], char newMajor[], int newAge){
    Node *temp = head;

    if(temp == NULL){
        printf("kosong");
    }

    while(temp != NULL && strcmp(temp->nim, targetNim) != 0){
        temp = temp->nextNode;
    }

    if(temp!=NULL){
        strcpy(temp->name, newName);
        strcpy(temp->major, newMajor);
        temp->age = newAge;
        print("NIM %s succesfully updated", targetNim);
    }else{
        printf("NIM not found");
    }
}

void deleteFirst(Node **head){
    if(*head){
        printf("empty");
        return;
    }

    Node *temp = *head;
    *head = (*head)->nextNode;
    temp->nextNode = NULL;
    free(temp);
    printf("Deleted success");
}


void deleteLast(Node **head){
    if(*head == NULL){
        printf("empty");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp->nextNode != NULL){
        prev = temp;
        temp = temp->nextNode;
    }

    if (prev == NULL){
        *head = NULL;
    }else{
        prev->nextNode = NULL;
    }
    
    free(temp);
    printf("deleted success");
}

void deleteMid(Node **head,char targetNim[]){
    if(*head == NULL){
        printf("empty");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && strcmp(temp->nim, targetNim) != 0){
        prev = temp;
        temp = temp->nextNode;
    }

    if (temp == NULL){
        printf("NIM tidak ditemukan");
        return;
    }
    
    if (prev == NULL){
        *head = temp->nextNode;
    }else{
        prev->nextNode = temp->nextNode;
        temp->nextNode = NULL;
    }

    free(temp);
    printf("deleted success");
}

void printList(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%s %s %s %d\n", temp->nim, temp->name, temp->major, temp->age);
        temp = temp->nextNode;
    }
    
}