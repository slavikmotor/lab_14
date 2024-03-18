#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

matrix createMatrixFromArray(const int* array, size_t rows, size_t columns) {
    matrix matrix = getMemMatrix(rows, columns);
    int arrayIndex = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix.cells[i][j] = array[arrayIndex++];
        }
    }

    return matrix;
}

matrix* createArrayOfMatrixFromArray(const int* array, size_t matrixAmount, size_t rows, size_t columns) {
    matrix* matrices = getMemArrayOfMatrices(matrixAmount, rows, columns);
    int arrayIndex = 0;

    for (size_t k = 0; k < matrixAmount; k++) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                matrices[k].cells[i][j] = array[arrayIndex++];
            }
        }
    }