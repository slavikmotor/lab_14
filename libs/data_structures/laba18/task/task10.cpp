#include "combiningTwoStrings.h"

void reverseWords(char* str) {
    char buffer[100];
    int i, j, k;

    // Копирование строки в буфер
    for (i = 0; str[i] != '\0'; i++) {
        buffer[i] = str[i];
    }
    buffer[i] = '\0';

    i = i - 1;
    k = 0;

    while(i >= 0) {
        // Поиск пробела или начала строки
        while(i >= 0 && buffer[i] != ' ') {
            i--;
        }

        // Запись слова в исходную строку
        j = i + 1;
        while(buffer[j] != '\0' && buffer[j] != ' ') {
            str[k++] = buffer[j++];
        }

        // Добавление пробела, если это не конец строки
        if (i >= 0) {
            str[k++] = ' ';
        }

        i--;
    }

    // Завершение строки
    str[k] = '\0';
}

int main() {
    char str[] = "Пример строки для изменения порядка слов";
    reverseWords(str);
    combiningTwoStrings(str); // Используем вашу функцию combiningTwoStrings из библиотеки
    return 0;
}