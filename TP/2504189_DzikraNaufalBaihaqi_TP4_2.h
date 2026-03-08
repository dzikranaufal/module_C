#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int nomor;
    char nama[100];
    char pesanan[100];
    struct Node *next;
} Node;

Node* createNode(int nomor, char nama[], char pesanan[]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    newNode->nomor = nomor;
    strcpy(newNode->nama, nama);
    strcpy(newNode->pesanan, pesanan);
    newNode->next = NULL;
    return newNode;
}

int isExist(Node *head, int nomor){
    Node *temp = head;
    while(temp != NULL){
        if(temp->nomor == nomor) return 1;
        temp = temp->next;
    }
    return 0;
}

void insertFirst(Node **head, int nomor, char nama[], char pesanan[]){
    Node *newNode = createNode(nomor,nama,pesanan);
    newNode->next = *head;
    *head = newNode;
}

void insertLast(Node **head, int nomor, char nama[], char pesanan[]){
    Node *newNode = createNode(nomor,nama,pesanan);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBefore(Node **head,int target,int nomor,char nama[],char pesanan[]){

    if(*head == NULL) return;

    Node *newNode = createNode(nomor,nama,pesanan);

    if((*head)->nomor == target){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while(temp != NULL && temp->nomor != target){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Nomor antrean tidak ditemukan\n");
        free(newNode);
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

void insertAfter(Node **head,int target,int nomor,char nama[],char pesanan[]){

    Node *temp = *head;

    while(temp != NULL && temp->nomor != target){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Nomor antrean tidak ditemukan\n");
        return;
    }

    Node *newNode = createNode(nomor,nama,pesanan);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByNumber(Node **head,int nomor){

    Node *temp = *head;
    Node *prev = NULL;

    while(temp != NULL && temp->nomor != nomor){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Nomor antrean tidak ditemukan\n");
        return;
    }

    if(prev == NULL){
        *head = temp->next;
    }else{
        prev->next = temp->next;
    }

    free(temp);
}

void updatePesanan(Node *head,int nomor,char pesananBaru[]){
    
    Node *temp = head;

    while(temp != NULL && temp->nomor != nomor){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Nomor antrean tidak ditemukan\n");
        return;
    }

    strcpy(temp->pesanan,pesananBaru);
}

void printList(Node *head){

    if(head == NULL){
        printf("Antrean kosong\n");
        return;
    }

    printf("\n---- DAFTAR ANTREAN KOPI WESKER ----\n");

    Node *temp = head;

    while(temp != NULL){
        printf("[%d] %s - Pesanan: %s\n",
        temp->nomor,temp->nama,temp->pesanan);
        temp = temp->next;
    }

    printf("----------------------------------------\n");
}

#endif