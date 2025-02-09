#ifndef stree
#define stree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    struct node *children[27];
} node, *tree;

// Task 1

tree initTree();
node* createTree(tree ST, int n, char **str);
node *initChildren(node *temp);
int calculateDepthTree(tree ST);
int countNumOfChildren(tree ST);
void insertWord(tree ST, char *str);
void printTree(FILE *fOutput, tree ST);
char **decomposeWord(char *str);
void printTree(FILE *fOutput, tree ST);

// Task 2

int calculateNumOfLeaves(tree ST);
int countNodesOnLevel(tree ST, int level);
int maxNumOfDescendants(tree ST);

// Task 3

int findSuffixes(tree ST, char *str);
void handleSuffixes(FILE *fOutput, tree ST, int M, char **suffixes);

#endif
