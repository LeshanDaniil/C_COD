/*
С клавиатуры ввести строку, состоящую из нескольких слов, разделенных одним пробелом. 
Для хранение строки использовать новый тип данных TEXT, введенный с помощью typedef. 
Написать функцию подсчета количества слов в строке.

Выполнил Лешан Даниил 32ис-21 20.01.2024
*/

#include <stdio.h>
#include <string.h>

typedef char TEXT[100];

int countWords(TEXT str) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            inWord = 1;
        } else if (inWord) {
            count++;
            inWord = 0;
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

int main() {
    TEXT inputString;

    printf("Введите строку из нескольких слов: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';

    int wordCount = countWords(inputString);
    printf("Количество слов в строке: %d\n", wordCount);

    return 0;
}
