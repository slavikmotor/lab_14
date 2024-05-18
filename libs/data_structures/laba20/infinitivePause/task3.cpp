#include <stdio.h>
#include <stdlib.h>

// Функция для нахождения медианы в массиве
int findMedian(int arr[], int n) {
    // Сортировка массива
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Находим медиану
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}

// применение медианного фильтра к матрице
void applyMedianFilter(int matrix[][3], int size) {
    int windowSize = size * size;
    int window[windowSize];
    int k = size / 2;

    // Обход матрицы
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = 0;

            // окружающие пиксели
            for (int x = i - k; x <= i + k; x++) {
                for (int y = j - k; y <= j + k; y++) {
                    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                        window[index++] = matrix[x][y];
                    }
                }
            }

            // Нахождение медианы и присвоение текущему элементу
            matrix[i][j] = findMedian(window, windowSize);
        }
    }
}

// для печати матрицы
void printMatrix(int matrix[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][3] = {{10, 20, 30}, {25, 35, 45}, {15, 25, 35}};
    int filterSize = 3;

    printf("Исходная матрица:\n");
    printMatrix(matrix);

    applyMedianFilter(matrix, filterSize);

    printf("\nМатрица после применения медианного фильтра:\n");
    printMatrix(matrix);

    return 0;
}