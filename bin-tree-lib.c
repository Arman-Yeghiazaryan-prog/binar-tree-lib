#include <stdio.h>
#include <stdlib.h>
#include "bin-tree-lib.h"

//Free used memory
void freemem(bintnode *tree) {
    if(tree!=NULL) {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}

//Add new node or create the root for new tree with given value
bintnode * addnode(bintnode *tree, int x) {
    if (tree == NULL) { 
        tree = (bintnode*)malloc(sizeof(bintnode)); 
        tree->value = x;   
        tree->left =  NULL;
        tree->right = NULL; 
    }
    else if (x == tree->value)
        printf("\n This value already exists!\n");
        else  if (x < tree->value)  
                tree->left = addnode(tree->left, x);
            else   
                tree->right = addnode(tree->right, x);
    return tree;
}

//Find the node with smallest value
bintnode* minValuenode(bintnode *tree){
    bintnode* tmp = tree;
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}

//Find the node with biggest value
bintnode* maxValuenode(bintnode *tree){
    bintnode* tmp = tree;
    while(tmp->right != NULL){
        tmp = tmp->right;
    }
    return tmp;
}

//Delete the node with given value
bintnode* deletenode(bintnode* tree, int x){
    if (tree == NULL) { 
        printf("\n No node with such value in the tree!\n");
        return tree;
    }
    if (x < tree->value) {
        tree->left = deletenode(tree->left, x);
    }
    else if (x > tree->value) {
        tree->right = deletenode(tree->right, x);
        }
        else{
            if((tree->left == NULL) && (tree->right == NULL)){
                free(tree);
                return NULL;
            }
            if(tree->left == NULL){
                bintnode* tmp = tree->right;
                free(tree);
                return tmp;
            }
            if(tree->right == NULL){
                bintnode* tmp = tree->left;
                free(tree);
                return tmp;
            }
            bintnode* tmp = minValuenode(tree->right);
            tree->value = tmp->value;
            tree->right = deletenode(tree->right, tmp->value);
        }
    return tree;
}

//Find the node with given value
bintnode* findnode(bintnode *tree, int x){
    if (tree == NULL) {
        printf("\n Value not found!\n");
        return tree;
    }
    if(x == tree->value) {
        return tree;
    }
    else if (x < tree->value)   
            return findnode(tree->left, x);
        else    
            return findnode(tree->right, x);
}

//Prefix print
void treeprint_pre(bintnode *tree) {
    if (tree!=NULL) { 
        printf(" %d ", tree->value); 
        treeprint_pre(tree->left); 
        treeprint_pre(tree->right); 
    }
}

//Infix print
void treeprint_in(bintnode *tree) {
    if (tree!=NULL) { 
        treeprint_in(tree->left); 
        printf(" %d ", tree->value); 
        treeprint_in(tree->right); 
    }
}

//Postfix print
void treeprint_pos(bintnode *tree) {
    if (tree!=NULL) { 
        treeprint_pos(tree->left); 
        treeprint_pos(tree->right); 
        printf(" %d ", tree->value); 
    }
}