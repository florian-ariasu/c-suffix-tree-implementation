#include "stree.h"

int findSuffixes(tree ST, char *str) {
    tree temp = ST;

    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a' + 1;

        if (temp->children[index] == NULL) {
            return 0;
        }

        temp = temp->children[index];
    }

    if (temp->children[0] && temp->children[0]->c == '$') {
        return 1;
    } else {
        return 0;
    }
}

void handleSuffixes(FILE *fOutput, tree ST, int M, char **suffixes) {
    for (int i = 0; i < M; i++) {
        if (findSuffixes(ST, suffixes[i])) {
            fprintf(fOutput, "%d\n", 1);
        } else {
            fprintf(fOutput, "%d\n", 0);
        }
    }
}

int countNumOfChildren(tree ST) {
    if (ST == NULL) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < 27; i++) {
        if (ST->children[i] != NULL) {
            count++;
        }
    }

    return count;
}

int maxNumOfDescendants(tree ST) {
    if (ST == NULL) {
        return 0;
    }

    int max = countNumOfChildren(ST);

    for (int i = 0; i < 27; i++) {
        int count = maxNumOfDescendants(ST->children[i]);
        if (count > max) {
            max = count;
        }
    }

    return max;
}

int countNodesOnLevel(tree ST, int level) {
    if (ST == NULL) {
        return 0;  
    }

    if (level == 0) {
        if (ST->c == '$') {
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = 0; i < 27; i++) {
        count += countNodesOnLevel(ST->children[i], level - 1);
    }

    return count;
}

int calculateNumOfLeaves(tree ST) {
    if (ST == NULL) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < 27; i++) {
        count += calculateNumOfLeaves(ST->children[i]);
    }

    if (ST->c == '$') {
        return count + 1;
    }

    return count;
}

int calculateDepthTree(tree ST) {
    if (ST == NULL) {
        return 0;
    }

    int maxDepth = 0;

    for (int i = 0; i < 27; i++) {
        int depth = calculateDepthTree(ST->children[i]);
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    return maxDepth + 1;
}

char **decomposeWord(char *str) {
    char **words = (char **)malloc(sizeof(char *) * 20);

    for (int i = 0; i < 20; i++) {
        words[i] = (char *)malloc(sizeof(char) * 20);
    }

    int k = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        words[k++] = str + i;
    }

    return words;
}

tree initTree() {
    tree ST = (tree)malloc(sizeof(node));

    if (ST == NULL) {
        return NULL;
    }

    ST->c = '\0';

    for (int i = 0; i < 27; i++) {
        if (i == 0) {
            ST->children[i] = (node*)malloc(sizeof(node));
            ST->children[i]->c = '$';
            ST->children[i] = initChildren(ST->children[i]);
        } else {
            ST->children[i] = NULL;
        }
    }
    
    return ST;
}

node *initChildren(node *temp) {
    for (int i = 0; i < 27; i++) {
        temp->children[i] = NULL;
    }

    return temp;
}

void insertWord(tree ST, char *str) {
    tree temp = ST;

    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a' + 1;

        if (temp->children[index] == NULL) {
            temp->children[index] = (node*)malloc(sizeof(node));
            temp->children[index]->c = str[i];
            temp->children[index] = initChildren(temp->children[index]);
        }

        temp = temp->children[index];
    }

    temp->children[0] = (node*)malloc(sizeof(node));
    temp->children[0]->c = '$';
}

node* createTree(tree ST, int n, char **str) {

    if (n == 0) {
        return NULL;
    }

    tree temp = ST;

    for (int i = 0; i < n; i++) {
        char **words = decomposeWord(str[i]);
        for (int j = 0; j < strlen(str[i]); j++) {
            insertWord(temp, words[j]);
        }
    }

    return ST;
}

void printLevel(FILE *fOutput, tree ST, int level) {
    if (ST == NULL) {
        return;
    }

    if (level == 0) {
        fprintf(fOutput, "%c ", ST->c);
    } else {
        for (int i = 0; i < 27; i++) {
            printLevel(fOutput, ST->children[i], level - 1);
        }
    }
}

void printTree(FILE *fOutput, tree ST) {
    if (ST == NULL) {
        return;
    }

    int k = 0;
    int depth = calculateDepthTree(ST);

    while (k < depth) {
        for (int i = 0; i < 27; i++) {
            if (k < depth) {
                printLevel(fOutput, ST->children[i], k);
            }
        }

        if (k != depth - 1) {
            fprintf(fOutput, "\n");            
        }

        k++;
    }
}
