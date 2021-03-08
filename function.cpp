#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

Node* search_max(Node* head) {
    while (head->right)
        head = head->right;
    return head;
}

Node* search_val(Node* node, int val) {
    while (node) {
        if (node->data < val) {
            node = node->right;
            continue;
        }
        else if (node->data > val) {
            node = node->left;
            continue;
        }
        else return node;
    }
    return NULL;
}

void removal(Node* removed_node) {
    if (removed_node->left && removed_node->right) {
        Node* localMax = search_max(removed_node->left);
        removed_node->data = localMax->data;
        removal(localMax);
        return;
    }
    else if (removed_node->left) {
        if (removed_node == removed_node->parent->left)
            removed_node->parent->left = removed_node->left;
        else removed_node->parent->right = removed_node->left;
    }
    else if (removed_node->right) {
        if (removed_node == removed_node->parent->left)
            removed_node->parent->left = removed_node->right;
        else removed_node->parent->right = removed_node->right;
    }
    else {
        if (removed_node == removed_node->parent->right) {
            removed_node->parent->right = NULL;

        }
        else
            removed_node->parent->left = NULL;
    }
    free(removed_node);
}

void search_deleted(Node* removed_node, int val) {
    Node* rn = search_val(removed_node, val);
    removal(rn);
}

void insert(Node** head, int value) {

    Node* tmp = NULL;

    Node* n = (Node*)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->data = value;

    if (*head == NULL) {
        *head = n;
        n->parent = NULL;
        return;
    }

    tmp = *head;

    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            }
            else {
                n->parent = tmp;
                tmp->right = n;
                return;
            }
        }
        else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            }
            else {
                n->parent = tmp;
                tmp->left = n;
                return;
            }
        }
        else {
            exit(-2);
        }
    }
}

void printTree(Node* root) {
    if (root) {
        printf("%d\n", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}