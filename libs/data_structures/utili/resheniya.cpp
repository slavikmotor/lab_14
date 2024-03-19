#include "libs/data_structures/matrix/matrix.h"
#include <minmax.h>
#include "libs/utili/utiligit add ..h"
#include <math.h>

void swapMaxElementRowAndMinElementRow(matrix matrix) {
    int min = INT_MAX, minRow = -1, max = 0, maxRow = -1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            int value = matrix.cells[i][j];

            if (value < min) {
                min = value;
                minRow = i;
            } else if (value > max) {
                max = value;
                maxRow = i;
            }
        }
    }

    swapRows(matrix, minRow, maxRow);
}

void sortRowsByMinElement(matrix matrix) {
    sortRowsByCriteria(matrix, findMax);
}

void sortColsByMinElement(matrix matrix) {
    sortColumnsByCriteria(matrix, findMin);
}

void getSquareOfMatrixIfSymmetric(matrix* matrix) {
    if (isSymmetricMatrix(matrix)) {
        *matrix = multiply(*matrix, *matrix);
    }
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix* matrix) {
    long long sums[matrix->rows];

    for (int i = 0; i < matrix->rows; ++i) {
        sums[i] = sum(matrix->cells[i], matrix->columns);
    }

    if (isSet(sums, matrix->rows)) {
        transposeMatrix(matrix);
    }
}

bool isMutuallyInverseMatrices(matrix left, matrix right) {
    matrix multiplication = multiply(left, right);

    return isEMatrix(&multiplication);
}

long long findSumOfMaxesOfPseudoDiagonal(matrix matrix) {
    int arraySize = matrix.rows + matrix.columns - 1;
    int maxes[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        maxes[i] = INT_MIN;
    }

    int increment = matrix.columns - 1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            int index = i - j + increment;

            maxes[index] = max(maxes[index], matrix.cells[i][j]);
        }
    }

    long long sum = 0;

    for (int i = 0; i < arraySize; ++i) {
        if (i != increment) {
            sum += maxes[i];
        }
    }

    return sum;
}

int getMinInArea(matrix matrix) {
    position maximumPosition = getMaxValuePos(matrix);
    int min = INT_MAX;

    for (int i = 0; i <= maximumPosition.rowIndex; ++i) {
        int columnOffset = (maximumPosition.rowIndex - i) << 1;
        int startColumn = max(0, maximumPosition.colIndex - columnOffset);
        int endColumn = min(matrix.columns - 1, maximumPosition.colIndex + columnOffset);

        for (int j = startColumn; j <= endColumn; ++j) {
            min = min(min, matrix.cells[i][j]);
        }
    }

    return min;
}

float getDistance(const int* values, int valueAmount) {
    float squaredDistance = 0;

    for (int i = 0; i < valueAmount; ++i) {
        int value = values[i];

        squaredDistance += ((float) (value * value));
    }

    return sqrtf(squaredDistance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix matrix, float (*criteria)(const int*, int)) {
    for (int i = 0; i < matrix.rows; i++) {
        int* row = matrix.cells[i];
        float weight = criteria(row, matrix.columns);
        int j = i + 1;
        float currentWeight;

        while (j >= 0 && (currentWeight = criteria(matrix.cells[j], matrix.columns)) > weight) {
            matrix.cells[j + 1] = matrix.cells[j];
            weight = currentWeight;
            j--;
        }

        matrix.cells[j + 1] = row;
    }
}

void sortByDistances(matrix matrix) {
    insertionSortRowsMatrixByRowCriteriaF(matrix, getDistance);
}

int countEqClassesByRowsSum(matrix matrix) {
    long long rowSums[matrix.rows];

    for (int i = 0; i < matrix.rows; ++i) {
        rowSums[i] = sum(matrix.cells[i], matrix.columns);
    }

    return countUniques(rowSums, matrix.rows);
}

int countSpecialElements(matrix matrix) {
    int count = 0;

    for (int i = 0; i < matrix.columns; ++i) {
        int* row = matrix.cells[i];

        for (int j = 0; j < matrix.rows; ++j) {
            int sumOfOther = 0;

            for (int k = 0; k < matrix.rows; k++) {
                if (k != j) {
                    sumOfOther += row[k];
                }
            }

            if (row[j] > sumOfOther) {
                count++;
                break;
            }
        }
    }

    return count;
}

void swapPenultimateRow(matrix matrix) {
    if (matrix.rows == 1) {
        return;
    }

    int minColumn = getMinValuePos(matrix).colIndex;
    int column[matrix.rows];

    for (int i = 0; i < matrix.rows; ++i) {
        column[i] = matrix.cells[i][minColumn];
    }

    int destinationRow = matrix.rows - 2;

    for (int i = 0; i < matrix.columns; ++i) {
        matrix.cells[destinationRow][i] = column[i];
    }
}

static bool hasAllNonDescendingRows(matrix matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        if (!isNonDescending(matrix.cells[i], matrix.columns)) {
            return false;
        }
    }

    return true;
}

int countNonDescendingRowsMatrices(const matrix* matrices, int matrixAmount) {
    int count = 0;

    for (int i = 0; i < matrixAmount; ++i) {
        if (hasAllNonDescendingRows(matrices[i])) {
            count++;
        }
    }

    return count;
}

void printMatrixWithMaxZeroRows(const matrix* matrices, int matrixAmount) {
    int maxAmount;
    int zeroRowAmounts[matrixAmount];

    for (int i = 0; i < matrixAmount; ++i) {
        int amount = countZeroRows(matrices[i]);

        zeroRowAmounts[i] = amount;
        maxAmount = max(maxAmount, amount);
    }

    for (int i = 0; i < matrixAmount; ++i) {
        if (zeroRowAmounts[i] == maxAmount) {
            outputMatrix(matrices[i]);
        }
    }
}

int getMatrixNorm(matrix matrix) {
    int max = 0;

    for (int i = 0; i < matrix.rows; ++i) {
        int* row = matrix.cells[i];

        for (int j = 0; j < matrix.columns; ++j) {
            max = max(max, abs(row[j]));
        }
    }

    return max;
}

void printMatricesWithMinNorm(matrix* matrices, int matrixAmount) {
    int matrixNorms[matrixAmount];

    for (int i = 0; i < matrixAmount; ++i) {
        matrixNorms[i] = getMatrixNorm(matrices[i]);
    }

    int minNorm = findMin(matrixNorms, matrixAmount);

    for (int i = 0; i < matrixAmount; ++i) {
        if (matrixNorms[i] == minNorm) {
            outputMatrix(matrices[i]);
        }
    }
}

static bool isSpecial2(const int* array, int size, int index) {
    int value = array[index];

    for (int i = 0; i < index; i++) {
        if (array[i] >= value) {
            return false;
        }
    }

    for (int i = index + 1; i < size; i++) {
        if (array[i] <= value) {
            return false;
        }
    }

    return true;
}

int countSpecialElements2(matrix matrix) {
    int count = 0;

    for (int i = 0; i < matrix.rows; ++i) {
        int* row = matrix.cells[i];

        for (int j = 0; j < matrix.columns; j++) {
            if (isSpecial2(row, matrix.columns, j)) {
                count++;
            }
        }
    }

    return count;
}

static double getScalarProduct(const int* leftVector, const int* rightVector, int vectorValueAmount) {
    double product = 0;

    for (int i = 0; i < vectorValueAmount; ++i) {
        product += leftVector[i] * rightVector[i];
    }

    return product;
}

double getVectorLength(const int* vector, int vectorValueAmount) {
    double squaredValuesSum = 0;

    for (int i = 0; i < vectorValueAmount; ++i) {
        squaredValuesSum += pow(vector[i], 2);
    }

    return sqrt(squaredValuesSum);
}

double getCosine(const int* leftVector, const int* rightVector, int vectorValueAmount) {
    double scalarProduct = getScalarProduct(leftVector, rightVector, vectorValueAmount);
    double leftVectorLength = getVectorLength(leftVector, vectorValueAmount);
    double rightVectorLength = getVectorLength(rightVector, vectorValueAmount);

    return scalarProduct / (leftVectorLength * rightVectorLength);
}

double getAngle(const int* leftVector, const int* rightVector, int vectorValueAmount) {
    return acos(getCosine(leftVector, rightVector, vectorValueAmount));
}

int getVectorIndexWithMaxAngle(matrix vectorsMatrix, const int* vector) {
    int maxIndex = 0;
    double maxAngle = getAngle(vectorsMatrix.cells[0], vector, vectorsMatrix.columns);

    for (int i = 1; i < vectorsMatrix.rows; ++i) {
        double angle = getAngle(vectorsMatrix.cells[i], vector, vectorsMatrix.columns);

        if (angle > maxAngle) {
            maxIndex = i;
            maxAngle = angle;
        }
    }

    return maxIndex;
}

long long getScalarProductRowAndCol(matrix matrix, int rowIndex, int columnIndex) {
    int column[matrix.rows];

    for (int i = 0; i < matrix.rows; ++i) {
        column[i] = matrix.cells[i][columnIndex];
    }

    return (long long) getScalarProduct(column, matrix.cells[rowIndex], matrix.rows);
}

long long getSpecialScalarProduct(matrix matrix) {
    return getScalarProductRowAndCol(matrix,getMaxValuePos(matrix).rowIndex,getMinValuePos(matrix).colIndex);
}
