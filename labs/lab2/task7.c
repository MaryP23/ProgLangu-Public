#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // работа с символами и цифрами
/*Написать программу, вычисляющую значение выражения, записанного в постфиксной (обратной польской) записи, 
считываемого из входного файла. Считать, что выражение может содержать только цифры и знаки «+», «-», «*» и «/».*/
#define MAX_SIZE 100

typedef struct { // typedef создание нов типа данных
// struct пользовательский тип данных
    int items[MAX_SIZE]; // элементы стека
    int top; // индекс верхнего элем стека
} Stack;

void initStack(Stack *s) { // инициализация стека
    s->top = -1;
    // устанавливает значение, означающее, что стек пуст
}

int isFull(Stack *s) { // проверяет, полон ли стек
    return s->top == MAX_SIZE - 1;
// если индекс верхнего элемента соотв макс размеру
// то стек полон, иначе возвращает 0
}

int isEmpty(Stack *s) { // проверяет, пуст ли стек
    return s->top == -1; // булевой
}

void push(Stack *s, int value) {
// добавление элемента в стек
// принимает указатель на стек и значение, которое добавить
    if (!isFull(s)) { // если стек не полон, то...
        s->items[++(s->top)] = value;
/* Сначала увеличивается значение top на 1,
а затем используется этот новый индекс для
доступа к массиву items. Элемент будет помещён
в следующую доступную позицию стека */
    }
}

int pop(Stack *s) {
// удаляет элемент из стека и возвращ его знач
    if (!isEmpty(s)) { // если стек не пуст, то...
        return s->items[(s->top)--];
/* Сначала берётся текущее значение top, для получения
элемента из массива items. Затем значение top уменьшается
на 1. Мы извлекаем верхний элемент стека и сразу же 
указываем, что теперь верхний элемент находится ниже. */
    }
    return -1; // возвращаем -1, если стек пуст
}

int evaluatePostfix(const char *expression) {
// принимает строку (выражение)
    Stack stack; // локальная переменная стека
// хранение состояния стека
    initStack(&stack); // инициализация пустого стека
    
    const char *p = expression; // указатель для итерации
// expression - строка

    while (*p) {
        if (isdigit(*p)) {
// если символ - цифра, преобразуем в число и помещаем в стек
            push(&stack, *p - '0');
// вычитание ASCII-кода символа '0' из ASCII-кода текущего символа (преобразование)
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
// если символ - оператор, извлекаем два значения из стека
            int right = pop(&stack); // извлечение
            int left = pop(&stack); 
            int result;

            switch (*p) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
// предполагается, что деление на ноль не произойдет
                    break;
            }
            // помещаем результат обратно в стек
            push(&stack, result);
        }
        p++;
    }

    // в конце в стеке должно остаться одно значение - результат
    return pop(&stack); // возвращает верхний элемент стека
// как результат выполнения функции evaluatePostfix
}

int main() {
    FILE *file = fopen("input1.txt", "r");
 if (file == NULL) {
        printf("Error: Could not open file\n");
        return EXIT_FAILURE;
 }
    char expression[MAX_SIZE];
// создание массива для хранения выражения
    fgets(expression, sizeof(expression), file);
// считывание строки из файла и помещение в массив
    fclose(file);

    int result = evaluatePostfix(expression);
// вызод функции
     if (result != -1) {
        printf("Result: %d\n", result);
    }

    return EXIT_SUCCESS; // успешное завершение программы
}
