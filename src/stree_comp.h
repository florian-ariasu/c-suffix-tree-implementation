#ifndef stree_comp
#define stree_comp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stree.h"

typedef struct nodeComp {
    char *label;
    struct nodeComp *children[27];
} nodeC, *treeC;

treeC initTreeC();
treeC astToCst(tree ST, treeC STC);
int calculateDepthTreeC(treeC ST);
int isSingleChild(tree ST);
void printLevelC(FILE *fOutput, treeC root, int level);
void printTreeC(FILE *fOutput, treeC root);

#endif
