#ifndef C_H
#define C_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* search_max(Node* head);
Node* search_val(Node* node, int val);
void removal(Node* removed_node);
void search_deleted(Node* removed_node, int val);
void insert(Node** head, int value);
void printTree(Node* root);

#endif