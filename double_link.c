// Dzikra Naufal Baihaqi
// 2504189
// 3/16/2026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nim[10];
    char nama[50];
    char prodi[50];
    struct Node *prevNode;
    struct Node *nextNode;
} Node;

Node* createNode(char nim[], char nama[], char prodi[]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->nim, nim);
    strcpy(newNode->nama, nama);
    strcpy(newNode->prodi, prodi);
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    
    return newNode;
}

void insertAtFront(Node** head, char nim[], char nama[], char prodi[]){
    Node* newNode = createNode(nim, nama, prodi);
    
    if (*head == NULL) {
        *head = newNode;
    return;
    }

    (*head)->prevNode = newNode;
    newNode->nextNode = *head;
    *head = newNode;
}

void insertAtEnd (Node** head, char nim[], char nama[], char prodi[]){
    Node* newNode = createNode(nim, nama, prodi);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }

    temp->nextNode = newNode;
    newNode->prevNode = temp;
}

void insertMiddleBefore(Node** head, char targetNim[], char nim[], char nama[], char prodi[]){
    Node* newNode = createNode(nim, nama, prodi);

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("Target NIM tidak ditemukan.\n");
        return;
    }

    if (temp->prevNode == NULL) {
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

void insertMiddleAfter (Node** head, char targetNim[], char nim[], char nama[], char prodi[]){
    Node* newNode = createNode(nim, nama, prodi);
    
    if (*head == NULL) {
        printf("List is empty. Cannot insert after a target.\n");
        return;
    }
    
    Node* temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->nextNode;
    }
    
    if (temp == NULL) {
        printf("Target NIM not found.\n");
        return;
    }
    
    if (temp->nextNode == NULL) {
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

void printForward(Node* head){
    Node* temp = head;

    printf("Forward List:\n");
    while (temp != NULL) {
        printf("NIM: %s | Nama: %s | Prodi: %s\n", temp->nim, temp->nama, temp->prodi);
        temp = temp->nextNode;
    }
    printf("\n");
}

void printBackward (Node* head){
    Node* temp = head;
    if (temp == NULL) {
        printf("List mahasiswa kosong.\n");
        return;
    }
    
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }

    printf("Reverse List:\n");
    while (temp != NULL) {
        printf("NIM: %s | Nama: %s | Prodi: %s\n", temp->nim, temp->nama, temp->prodi);
        temp = temp->prevNode;
    }
    printf("\n");
}

//iseng kang

void updateDataNode(Node* head, char targetNim[], char newNama[], char newProdi[]) {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("Data dengan NIM %s tidak ditemukan.\n", targetNim);
        return;
    }

    strcpy(temp->nama, newNama);
    strcpy(temp->prodi, newProdi);

    printf("Data berhasil diupdate.\n");
}

void deleteAwal(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;

    if ((*head)->nextNode == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    *head = (*head)->nextNode;
    (*head)->prevNode = NULL;

    free(temp);
}

void deleteAkhir(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;

    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }

    if (temp->prevNode == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    temp->prevNode->nextNode = NULL;
    free(temp);
}

void deleteBerdasarkanNIM(Node** head, char targetNim[]) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;

    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("NIM tidak ditemukan.\n");
        return;
    }

    //klo node pertama
    if (temp->prevNode == NULL) {
        *head = temp->nextNode;
        if (*head != NULL)
            (*head)->prevNode = NULL;
        free(temp);
        return;
    }

    //klo node terakhir
    if (temp->nextNode == NULL) {
        temp->prevNode->nextNode = NULL;
        free(temp);
        return;
    }

    // node tengah
    temp->prevNode->nextNode = temp->nextNode;
    temp->nextNode->prevNode = temp->prevNode;

    free(temp);
}


int main() {
    Node *head = NULL;

    insertAtEnd(&head, "240101", "Jikra", "Informatika");
    insertAtEnd(&head, "240038", "Naufal", "Teknik Jepang");
    insertAtEnd(&head, "250408", "Baihaqi", "Sastra mesin");
    printForward(head);

    insertMiddleBefore(&head, "240038", "240923", "Caelus", "Manajemen Overthinking");
    insertMiddleBefore(&head, "240038", "248883", "Kafka", "Ilmu Menghilang");
    printForward(head);

    updateDataNode(head, "240038", "Belle Updated", "Ilmu Komunis");
    printForward(head);

    deleteAwal(&head);
    printForward(head);

    deleteAkhir(&head);
    printForward(head);

    deleteBerdasarkanNIM(&head, "240923");
    printForward(head);

    printBackward(head);

    return 0;
}
