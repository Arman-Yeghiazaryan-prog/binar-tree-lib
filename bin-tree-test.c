#include <stdio.h>
#include "bin-tree-lib.h"

int main(){
    printf("\nStarting test-run for binary tree header file.\n");
    bintnode* root = NULL;
    int i = 0;
    int testarray[12] = {7, 4, 2, 3, 6, 5, 12, 9, 8, 10, 13, 15};
    int testlen = 12;
    root = NULL;

    for(i = 0; i < testlen; i++){
        root = addnode(root, testarray[i]);
    }
    printf("\nTest array:\n");
    for(i = 0; i < testlen; i++){
        printf(" %d ", testarray[i]);
    }
    printf("\n\nTree created from test array:");
    printf("\n Prefix print:\n");
    treeprint_pre(root);
    printf("\n\n Infix print:\n");
    treeprint_in(root);
    printf("\n\n Postfix print:\n");
    treeprint_pos(root);
    printf("\n");

    bintnode* minnode = minValuenode(root);
    printf("\n Minimal value in the tree:\n %d\n", minnode->value);
    printf("\n Adding new node with value = 1...\n");
    root = addnode(root, 1);
    testlen++;
    minnode = minValuenode(root);
    printf("\n Minimal value after adding new node:\n %d\n", minnode->value);
    bintnode* maxnode = maxValuenode(root);
    printf("\n Maximal value in the tree:\n %d\n", maxnode->value);
    printf("\n Adding node with value equal to existing one (value = %d)...\n", testarray[testlen/2]);
    root = addnode(root, testarray[testlen/2]);  

    bintnode* lostnode = NULL;
    printf("\n Searching for a node with the value = 10 (existing value)...\n");
    lostnode = findnode(root, 10);
    if(lostnode != NULL){
        printf("\n Value found = %d\n", lostnode->value);
    }
    lostnode = NULL;
    printf("\n Searching for a node with the value = 11 (not existing value)\n");
    lostnode = findnode(root, 11);
    if(lostnode != NULL){
        printf("\n Value found = %d\n", lostnode->value);
    }
    
    printf("\n Tree:\n");
    treeprint_pre(root);
    printf("\n\n Deleting the node with value = 9 ...\n");
    root = deletenode(root, 9);
    printf("\n Tree after deleting a node:\n");
    treeprint_pre(root);

    freemem(root);
    return 0;
}