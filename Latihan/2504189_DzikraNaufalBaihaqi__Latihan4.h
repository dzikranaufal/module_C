#ifndef C7BF623E_F309_4D12_BBDB_D4F5A0C8162B
#define C7BF623E_F309_4D12_BBDB_D4F5A0C8162B
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    char penyakit[50];
    struct Node* next;
} Node;

Node* createNode(int id, char name[], char penyakit[]);
void insertAwal(Node **head, int id, char name[], char penyakit[]);
void insertAkhir(Node **head, int id, char name[], char penyakit[]);
void insertTengahSebelum(Node **head, int targetId, int id, char name[], char penyakit[]);
void insertTengahSesudah(Node **head, int targetId, int id, char name[], char penyakit[]);
void update(Node **head, int targetId, char newName[], char newPenyakit[]);
void deleteAwal(Node **head);
void deleteAkhir(Node **head);
void deleteTengah(Node **head, int targetId);
void printList(Node *head);
void freeList(Node **head);

#endif


#endif /* C7BF623E_F309_4D12_BBDB_D4F5A0C8162B */
