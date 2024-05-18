#include <stdio.h>
#include <stdlib.h>

#define M 4 // Кол-во строк в матрице
#define N 3 // Кол-во столбцов в матрице

// Функция для подсчета живых соседей клетки
int countLiveNeighbors(int board[M][N], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < M && j >= 0 && j < N && !(i == row && j == col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

// Функция для эмуляции одного шага "Игры Жизнь"
void gameOfLife(int board[M][N]) {
    int nextBoard[M][N]; // Создаем временную матрицу для следующего состояния
    int i, j;
    // Проходим по каждой клетке текущей матрицы
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int liveNeighbors = countLiveNeighbors(board, i, j); // Подсчитываем живых соседей
            // Проверяем правила "Игры Жизнь" и обновляем состояние клетки во временной матрице
            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextBoard[i][j] = 0; // Клетка умирает
                } else {
                    nextBoard[i][j] = 1; // Клетка продолжает жить
                }
            } else {
                if (liveNeighbors == 3) {
                    nextBoard[i][j] = 1; // Новая клетка рождается
                } else {
                    nextBoard[i][j] = 0; // Клетка остается мертвой
                }
            }
        }
    }
    // Копируем временную матрицу в текущую матрицу
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = nextBoard[i][j];
        }
    }
}

// для печати матрицы
void printBoard(int board[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[M][N] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}}; // Исходное состояние доски

    printf("Исходное состояние:\n");
    printBoard(board); // исходное состояние доски

    gameOfLife(board); // один шаг "Игры Жизнь"

    printf("\nСледующее состояние:\n");
    printBoard(board); // следующее состояние доски

    return 0;
}