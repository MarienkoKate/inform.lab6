#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main() {
    Node* root = NULL;
    insert(&root, 10);
    insert(&root, 12);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 4);
    search_deleted(root, 12);
    printTree(root);
    return 0;
}