#ifndef C0F61B15_B73C_4869_BAE9_8CB246D6C38E
#define C0F61B15_B73C_4869_BAE9_8CB246D6C38E
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id;
    char title[100];
    char time[6];
    struct Node* next;
} Node;

Node* createNode(int id, char title[], char time[]){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->id=id;
    strcpy(newNode->title, title);
    strcpy(newNode->time, time);
    newNode->next = NULL;
    
    return newNode;
}

int isIdExist(Node *head, int id){
    Node *temp = head;

    while (temp != NULL){
        if (temp->id == id){
            return 1;
        }
        temp = temp->next;
    }

    return 0; 
}

void addFirst(Node **head, int id, char title[], char time[]){
    Node *newNode = createNode(id, title, time);
    newNode->next = *head;
    *head = newNode;
}

void addLast(Node **head, int id, char title[], char time[]){
    Node *newNode = createNode(id, title, time);

    if (*head == NULL){
        *head = newNode;
    }else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addAfter(Node **head, int targetId, int id, char title[], char time[]){
    Node *newNode = createNode(id, title, time);

    Node *temp = *head;
    while (temp != NULL && temp->id != targetId){
        temp = temp->next;
    }

    if(temp != NULL){
        newNode->next= temp->next;
        temp->next= newNode;
    }else{
        printf("ID tidak ditemukan\n");
        free(newNode);
    }
}

void deleteFirst(Node **head){
    if (*head == NULL){
        printf("empty\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node **head){
    if (*head == NULL){
        printf("empty\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL){
        *head = NULL;
    }else{
        prev->next = NULL;
    }
    
    free(temp);
}

void update(Node **head, int targetId, int newId, char newTitle[], char newTime[]){
    Node *temp = *head;

    while (temp != NULL && temp->id != targetId){
        temp = temp->next;
    }
    
    if (temp != NULL){
        temp->id = newId;
        strcpy(temp->title, newTitle);
        strcpy(temp->time, newTime);
    }
}

void printList(Node *head){
    Node *temp = head;

    if (temp == NULL){
        printf("empty\n");
        return;
    }

    printf("\nDAFTAR JADWAL TAYANG BIOSKOP\n");
    printf("-------------------------------------------------\n");

    while (temp != NULL){
        printf("ID: %d | %-20s | Pukul: %-5s\n", temp->id, temp->title, temp->time);
        temp = temp->next;
    }

    printf("-------------------------------------------------\n");
}

void inputData(Node *head, int *id, char title[], char time[]){
    do{
        printf("ID Film: ");
        scanf("%d", id);

        if(isIdExist(head, *id)){
            printf("ID sudah digunakan! Masukkan ID lain.\n");
        }

    }while(isIdExist(head, *id));
    
    printf("Judul: ");
    scanf(" %[^\n]", title);
    
    printf("Jam Tayang: ");
    scanf(" %[^\n]", time);
}

void updateData(Node **head){
    int targetId;
    int newId;
    char newTitle[100];
    char newTime[6];

    if (*head == NULL){
        printf("empty\n");
        return;
    }

    printf("Masukkan ID yang ingin diupdate: ");
    scanf("%d", &targetId);

    inputData(*head, &newId, newTitle, newTime);

    update(head, targetId, newId, newTitle, newTime);
}

void addData(Node **head){
    int choice, id, targetId;
    char title[100];
    char time[6];

    printf("\n1. Awal\n");
    printf("2. Akhir\n");
    printf("3. Sesudah ID tertentu\n");
    printf("Pilih posisi: ");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        inputData(*head, &id, title, time);
        addFirst(head, id, title, time);
        break;
        
    case 2:
        inputData(*head, &id, title, time);
        addLast(head, id, title, time);
        break;
        
    case 3:
        inputData(*head, &id, title, time);
        printf("Masukkan ID acuan: ");
        scanf("%d", &targetId);
        addAfter(head, targetId, id, title, time);
        break;
        
    default:
        printf("tidak valid\n");
    }
}

void deleteData(Node **head){
    int choice;

    if (*head == NULL){
        printf("Data kosong\n");
        return;
    }

    printf("\n1. Hapus Awal\n");
    printf("2. Hapus Akhir\n");
    printf("Pilih: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            deleteFirst(head);
            break;

        case 2:
            deleteLast(head);
            break;

        default:
            printf("Pilihan tidak valid\n");
    }
}

#endif


#endif /* C0F61B15_B73C_4869_BAE9_8CB246D6C38E */
