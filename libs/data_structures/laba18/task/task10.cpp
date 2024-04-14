#include "combiningTwoStrings.h"

void reverseWords(char* str) {
    char buffer[100];
    int i, j, k;


    for (i = 0; str[i] != '\0'; i++) {
        buffer[i] = str[i];
    }
    buffer[i] = '\0';

    i = i - 1;
    k = 0;

    while(i >= 0) {
        while(i >= 0 && buffer[i] != ' ') {
            i--;
        }

        j = i + 1;
        while(buffer[j] != '\0' && buffer[j] != ' ') {
            str[k++] = buffer[j++];
        }

        if (i >= 0) {
            str[k++] = ' ';
        }

        i--;
    }

    str[k] = '\0';
}

int main() {
    char str[] = "Пример строки для изменения порядка слов";
    reverseWords(str);
    combiningTwoStrings(str); // Используем вашу функцию combiningTwoStrings из библиотеки
    return 0;
}