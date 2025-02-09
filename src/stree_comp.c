#include "STreeComp.h"
#include "STree.h"

int calculateDepthTreeC(treeC ST) {
    if (ST == NULL) {
        return 0;
    }

    int maxDepth = 0;

    for (int i = 0; i < 27; i++) {
        int depth = calculateDepthTreeC(ST->children[i]);
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    return maxDepth + 1;
}

int isSingleChild(tree ST) {
    if (ST == NULL) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < 27; i++) {
        if (ST->children[i] != NULL) {
            count++;
        }
    }

    return count == 1;
}

treeC initTreeC() {
    treeC newNode = (treeC)malloc(sizeof(struct nodeComp));
    newNode->label = NULL;
    for (int i = 0; i < 27; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

treeC astToCst(tree ST, treeC STC) {
    if (ST == NULL) {
        return NULL;
    }

    if (STC == NULL) {
        STC = initTreeC();
    }

    if (STC->label == NULL) {
        STC->label = (char*)malloc(20 * sizeof(char)); 
        STC->label[0] = '\0'; 
    }

    if (ST->c == '$' && STC->label == NULL) {
        strcat(STC->label, "$"); 
        return STC;
    }

    char temp[2] = {ST->c, '\0'};  
    strcat(STC->label, temp);

    int index = 0;
    while (countNumOfChildren(ST) == 1) {
        for (int i = 0; i < 27; i++) {
            if (ST->children[i] != NULL && ST->children[i]->c != '$') {
                ST = ST->children[i];
                
                char temp[2] = {ST->c, '\0'};
                strcat(STC->label, temp); 
                break;
            } else if (ST->children[i] != NULL && ST->children[i]->c == '$') {
                index = i;
                break;
            }
        }
        if (ST->children[index] && ST->children[index]->c == '$') {
            break;
        }
    }

    for (int i = 0; i < 27; i++) {
        if (ST->children[i] != NULL) {
            STC->children[i] = astToCst(ST->children[i], STC->children[i]);
        }
    }

    return STC;
}

void printLevelC(FILE *fOutput, treeC root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 0) {
        fprintf(fOutput, "%s ", root->label);
    } else {
        for (int i = 0; i < 27; i++) {
            printLevelC(fOutput, root->children[i], level - 1);
        }
    }
}

void printTreeC(FILE *fOutput, treeC root) {
    if (root == NULL) {
        return;
    }

    int k = 0;
    int depth = calculateDepthTreeC(root);

    while (k < depth) {
        for (int i = 0; i < 27; i++) {
            if (k < depth) {
                printLevelC(fOutput, root->children[i], k);
            }
        }

        if (k != depth - 1) {
            fprintf(fOutput, "\n");
        }

        k++;
    }
}
