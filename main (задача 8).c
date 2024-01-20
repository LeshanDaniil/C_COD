/*
Смоделировать диалог покупки произвольного товара в магазине.
При этом у покупателя есть возможность расплатиться либо по карточке либо по чеку.
Информацию о платеже хранить в объединение (Union).

Выполнил Лешан Даниил 32ис-21 20.01.2024
*/

#include <stdio.h>

union PaymentInfo {
    float cardPayment;
    char checkNumber[10];
};

struct Product {
    char name[50];
    float price;
};

void makePurchase(struct Product product, union PaymentInfo payment) {
    printf("Вы выбрали товар: %s\n", product.name);
    printf("Цена товара: $%.2f\n", product.price);

    if (payment.cardPayment > 0) {
        printf("Оплачено картой\n");
    } else if (payment.checkNumber[0] != '\0') {
        printf("Оплачено чеком: %s\n", payment.checkNumber);
    } else {
        printf("Не выбран способ оплаты.\n");
        return;
    }

    printf("Спасибо за покупку!\n");
}

int main() {
    struct Product item;
    union PaymentInfo payment;

    printf("Введите название товара: ");
    scanf("%s", item.name);
    printf("Введите цену товара: ");
    scanf("%f", &item.price);

    int paymentMethod;
    printf("\nВыберите способ оплаты:\n");
    printf("1. Карта\n");
    printf("2. Чек\n");
    scanf("%d", &paymentMethod);

    switch (paymentMethod) {
        case 1:
            payment.cardPayment = item.price;
            break;
        case 2:
            printf("Введите номер чека: ");
            scanf("%s", payment.checkNumber);
            break;
        default:
            printf("Некорректный выбор способа оплаты.\n");
            return 1;
    }

    makePurchase(item, payment);

    return 0;
}
