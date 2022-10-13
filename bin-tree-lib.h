#ifndef BIN_TREE_LB
#define BIN_TREE_LB

//Node structure
typedef struct bintnode{
    int value;
    struct bintnode *left;
    struct bintnode *right;
} bintnode;

//Free used memory
void freemem(bintnode *tree);

//Add new node or create the root for new tree with given value
bintnode * addnode(bintnode *tree, int x);

//Find the node with smallest value
bintnode* minValuenode(bintnode *tree);

//Find the node with biggest value
bintnode* maxValuenode(bintnode *tree);

//Delete the node with given value
bintnode* deletenode(bintnode* tree, int x);

//Find the node with given value
bintnode* findnode(bintnode *tree, int x);

//Prefix print
void treeprint_pre(bintnode *tree);

//Infix print
void treeprint_in(bintnode *tree);

//Postfix print
void treeprint_pos(bintnode *tree);

#endif