#include <stdio.h> //ввод-вывод
#include <stdlib.h> //стандартные функции
#include <time.h> //работа с временем
//Написать программу, которая генерирует массив из псевдослучайных целых чисел и выводит его в консоль.

int main(int argc, char *argv[]) {
    if (argc < 2) {// первый элемент название программы 
        printf("The size of the array is not entered\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    int size = atoi(argv[1]); // 0-название программы , atoi- преобразует строку в число
    if (size <= 0) {
        printf("Invalid size of the array\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    float *randomFloats = malloc(size * sizeof(float)); //добавление размера массива
    if (randomFloats == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    srand(time(NULL)); // инициализация генератора случайных чисел, возвращает время с начала эпохи
    // stand устанавливает изначальное значение, это все позволяет генерировать разные последовательности
    for (int i = 0; i < size; i++) {
        randomFloats[i] = (float)rand() / RAND_MAX; 
    }

    printf("Random numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%fn", randomFloats[i]); 
    }

    free(randomFloats); 
    return 0;
}

