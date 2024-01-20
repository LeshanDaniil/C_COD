/*
Ввести с клавиатуры номер дня недели. 
Вывести на экран название. Использовать перечисления (enum)

Выполнил Лешан Даниил 32ис-21 20.01.2024
*/

#include <stdio.h>

enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    int dayNumber;

    printf("Введите номер дня недели (1 - понедельник, 2 - вторник, ..., 7 - воскресенье): ");
    scanf("%d", &dayNumber);

    if (dayNumber < 1 || dayNumber > 7) {
        printf("Некорректный номер дня недели.\n");
        return 1; // Возвращаем код ошибки
    }

    enum Weekday day = (enum Weekday)(dayNumber - 1);

    switch (day) {
        case MONDAY:
            printf("Понедельник\n");
            break;
        case TUESDAY:
            printf("Вторник\n");
            break;
        case WEDNESDAY:
            printf("Среда\n");
            break;
        case THURSDAY:
            printf("Четверг\n");
            break;
        case FRIDAY:
            printf("Пятница\n");
            break;
        case SATURDAY:
            printf("Суббота\n");
            break;
        case SUNDAY:
            printf("Воскресенье\n");
            break;
    }

    return 0;
}