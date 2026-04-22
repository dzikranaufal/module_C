#ifndef header_h
#define header_h

#include <stdio.h>

typedef struct node{
    struct node *right;
    struct node *left;
    int data;
} Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
} 

void insert(Node **root, int data) {
    if(!*root) *root = createNode(data);
    else insert((data <= (*root)->data) ? &(*root)->left : &(*root)->right, data);
}

void addLeft(Node **t, int data) {
    if (!*t) *t = createNode(data);
    else {
        Node **pos = &(*t)->left;
        while (*pos) pos = &(*pos)->left;
        *pos = createNode(data);
    }
}

void addRight(Node **t, int data) {
    if (!*t) *t = createNode(data);
    else {
        Node **pos = &(*t)->right;
        while (*pos) pos = &(*pos)->right;
        *pos = createNode(data);
    }
}

void preOrder(Node *t){
    if(t){
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(Node *t){
    if(t){
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
}

void postOrder(Node *t){
    if(t){
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}

void deleteAll(Node **t){
    if(*t){
        deleteAll(&(*t)->left);
        deleteAll(&(*t)->right);
        free(*t);
        *t = NULL;
    }
}

void deleteRight(Node **t){
    if(*t) deleteAll(&(*t)->right);
}

void deleteLeft(Node **t){
    if(*t) deleteAll(&(*t)->left);
}

#endif