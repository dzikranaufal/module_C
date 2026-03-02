#ifndef HEADER_H
#define HEADER_H

typedef struct Node{
    char nim[20];
    char name[50];
    char major[20];
    int age;
    struct Node *nextNode;
} Node;

Node* createNode(char nim[], char name[], char major[], int age);
void addFirst(Node **head, char nim[], char name[], char major[], int age);
void addLast(Node **head, char nim[], char name[], char major[], int age);
void addMiddleBefore(Node **head, char targetNim[], char nim[], char name[], char major[], int age);
void addMiddleAfter(Node **head, char targetNim[], char nim[], char name[], char major[], int age);
void update(Node **head, char targetNim[], char newName[], char newMajor[], int newAge);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteMid(Node **head,char targetNim[]);
void printList(Node *head);


#endif /* HEADER_H */
