#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100 
/*Написать программу, реализующую перевод инфиксной записи арифметического выражения в постфиксную. Исходное арифметическое выражение состоит из цифр, знаков «+», «-», «*», «/» и скобок.*/
typedef struct stack {
    int arr[N]; 
    int top;      
} stack;

void zad(stack* s) {/*Инициализирует стек, устанавливая top в -1, что указывает на то, что стек пуст.*/
    s->top = -1; 
}

bool pust(stack* s) { /*Если стек полон, выводит сообщение об ошибке и возвращает false.
Если добавление успешно, увеличивает top на 1 и помещает sch в стек, возвращает true.*/
    return s->top == -1;
}

bool full(stack* s) {/*Возвращает true, если стек полон, и false в противном случае.*/
    return s->top == N - 1;
}

bool push(stack* s, int sch) {
    if (full(s)) {
        printf("Error.the stack is full.\n");
        return false;
    }
    s->arr[++(s->top)] = sch;/*Если добавление успешно, увеличивает top на 1 и помещает sch в стек, возвращает true.*/
    return true;
}

bool out(stack* s, int* sch) {
    if (pust(s)) {
        printf("Error.the stack is empty.\n");
        return false;
    }
    *sch = s->arr[(s->top)--];/*Если извлечение успешно, уменьшает top на 1 и возвращает true*/
    return true;
}

bool view(stack* s, int* sch) { /*Указатель на стек s и указатель на переменную sch, в которую будет помещено значение верхнего элемента.*/
    if (pust(s)) {
        printf("Error.The stack is empty..\n");
        return false;
    }
    *sch = s->arr[s->top];
    return true;
}

int main() {
    stack s;
    zad(&s); 

    push(&s, 15);

    int sch;

    if (view(&s, &sch)) {
        printf("the top value of the stack. %d\n", sch);
    }

    while (out(&s, &sch)) {
        printf("Extracing from the stack: %d\n", sch);
    }

    for (int i = 0; i < 105; ++i) {
        if (!push(&s, i)) {
            break;
        }
    }

    return 0;
}
