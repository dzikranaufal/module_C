#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char nim[20];
    char name[50];
    char major[20];
    int age;
    struct Node *nextNode;
} Node;

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


void deleteLast(){
    
}

void printList(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%s %s %s %d\n", temp->nim, temp->name, temp->major, temp->age);
        temp = temp->nextNode;
    }
    
}

int main(){
    
    Node* mhs = NULL;

    addFirst(&mhs, "2504189", "Dzikra", "Komputer", 20);
    addLast(&mhs, "2505558", "Fuad", "Pendidikan", 12);
    
    printList(mhs);

    addMiddleAfter(&mhs,"2504189", "2504675", "sigit", "Komputer", 20);
    
    printList(mhs);
    return 0; 
}