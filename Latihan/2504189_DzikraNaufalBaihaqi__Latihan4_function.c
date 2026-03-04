#include "header.h"

Node* createNode(int id, char name[], char penyakit[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->penyakit, penyakit);
    newNode->next = NULL;

    return newNode;
}

void insertAwal(Node **head, int id, char name[], char penyakit[]) {
    Node *newNode = createNode(id, name, penyakit);
    newNode->next = *head;
    *head = newNode;
}

void insertAkhir(Node **head, int id, char name[], char penyakit[]) {
    Node *newNode = createNode(id, name, penyakit);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertTengahSebelum(Node **head, int targetId, int id, char name[], char penyakit[]) {
    Node *newNode = createNode(id, name, penyakit);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if ((*head)->id == targetId) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;
    
    while (temp != NULL && temp->id != targetId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = newNode;
        newNode->next = temp;
    } else {
        printf("ID %d tidak ditemukan!\n", targetId);
        free(newNode);
    }
}

void insertTengahSesudah(Node **head, int targetId, int id, char name[], char penyakit[]) {
    Node *newNode = createNode(id, name, penyakit);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    
    while (temp != NULL && temp->id != targetId) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("ID %d tidak ditemukan!\n", targetId);
        free(newNode);
    }
}

void update(Node **head, int targetId, char newName[], char newPenyakit[]) {
    Node *temp = *head;

    if (temp == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    while (temp != NULL && temp->id != targetId) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (strcmp(temp->name, newName) != 0) printf("Data pasien dengan id %d telah diperbarui\n", targetId);
        else printf("Data pasien %s telah diperbarui.\n", newName);

        strcpy(temp->name, newName);
        strcpy(temp->penyakit, newPenyakit);
    } else {
        printf("ID %d tidak ditemukan!\n", targetId);
    }
}

void deleteAwal(Node **head) {
    if (*head == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAkhir(Node **head) {
    if (*head == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    
    free(temp);
}

void deleteTengah(Node **head, int targetId) {
    if (*head == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && temp->id != targetId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("ID %d tidak ditemukan!\n", targetId);
        return;
    }
    
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void printList(Node *head) {
    Node *temp = head;
    int i = 1;
    
    if (head == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("\nDaftar antrian pasien:\n");
    printf("=========================================\n");
    
    while (temp != NULL) {
        printf("ID: %-3d | Nama: %-10s| Penyakit: %s\n", temp->id, temp->name, temp->penyakit);
        temp = temp->next;
    }
    printf("=========================================\n\n");
}

void freeList(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}