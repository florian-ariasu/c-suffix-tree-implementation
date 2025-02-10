#include "stree.h"
#include "stree_comp.h"

int main(int argc, char *argv[]) {

    int input = 2;
    int output = 3;

    if (argc != 4) {
        input++;
        output++;
    }

    FILE *fInput = fopen(argv[input], "r");
    FILE *fOutput = fopen(argv[output], "w");

    if (fInput == NULL || fOutput == NULL) {
        return -1;
    }

    if (strcmp(argv[1], "-c1") == 0) {
        int n;
        fscanf(fInput, "%d", &n);

        char **str = (char**)malloc(20 * sizeof(char*));
        for (int i = 0; i < 20; i++) {
            str[i] = (char*)malloc(20 * sizeof(char));
        }

        for (int i = 0; i < n; i++) {
            fscanf(fInput, "%s", str[i]);
        }        

        tree ST = initTree();
        createTree(ST, n, str);
        printTree(fOutput, ST);
    } else if (strcmp(argv[1], "-c2") == 0) {
        int n;
        fscanf(fInput, "%d", &n);

        char **str = (char**)malloc(20 * sizeof(char*));
        for (int i = 0; i < 20; i++) {
            str[i] = (char*)malloc(20 * sizeof(char));
        }

        for (int i = 0; i < n; i++) {
            fscanf(fInput, "%s", str[i]);
        }        

        int k = atoi(argv[2]);
        tree ST = initTree();
        createTree(ST, n, str);
        fprintf(fOutput, "%d\n", calculateNumOfLeaves(ST));
        fprintf(fOutput, "%d\n", countNodesOnLevel(ST, k + 1));
        fprintf(fOutput, "%d\n", maxNumOfDescendants(ST));
    } else if (strcmp(argv[1], "-c3") == 0) {
        int N, M;
        fscanf(fInput, "%d %d", &N, &M);

        char **str = (char**)malloc(20 * sizeof(char*));
        for (int i = 0; i < 20; i++) {
            str[i] = (char*)malloc(20 * sizeof(char));
        }

        char **suffixes = (char**)malloc(20 * sizeof(char*));
        for (int i = 0; i < 20; i++) {
            suffixes[i] = (char*)malloc(20 * sizeof(char));
        }

        for (int i = 0; i < N; i++) {
            fscanf(fInput, "%s", str[i]);
        }

        for (int i = 0; i < M; i++) {
            fscanf(fInput, "%s", suffixes[i]);
        }

        tree ST = initTree();
        createTree(ST, N, str);
        handleSuffixes(fOutput, ST, M, suffixes);
    } else {
        int n;
        fscanf(fInput, "%d", &n);

        char **str = (char**)malloc(20 * sizeof(char*));
        for (int i = 0; i < 20; i++) {
            str[i] = (char*)malloc(20 * sizeof(char));
        }

        for (int i = 0; i < n; i++) {
            fscanf(fInput, "%s", str[i]);
        }        

        tree ST = initTree();
        createTree(ST, n, str);

        treeC STC = initTreeC();
        STC = stToCst(ST, STC);
        printTreeC(fOutput, STC);
    }

    fclose(fInput);
    fclose(fOutput);

    return 0;
}
