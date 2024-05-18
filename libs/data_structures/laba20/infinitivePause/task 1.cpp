#include <stdio.h>

void addSubmatrix(int matrix[][n], int row1, int col1, int row2, int col2, int n) {
    int i, j;
    for (i = row1; i <= row2; i++) {
        for (j = col1; j <= col2; j++) {
            matrix[i][j]++;
        }
    }
}

void processQueries(int matrix[][n], int queries[][4], int numQueries, int n) {
    int i;
    for (i = 0; i < numQueries; i++) {
        addSubmatrix(matrix, queries[i][0], queries[i][1], queries[i][2], queries[i][3], n);
    }
}

void printMatrix(int matrix[][n], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int matrix[3][3] = {0};
    int queries[2][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    int numQueries = 2;

    processQueries(matrix, queries, numQueries, n);
    printMatrix(matrix, n);

    return 0;
}