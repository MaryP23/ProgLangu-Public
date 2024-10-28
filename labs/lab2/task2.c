#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15 
#define MAX_RANDOM 1000
//Написать программу, которая генерирует массив из псевдослучайных целых чисел и записывает в файл в обратном порядке.
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANDOM; // генерация случайного числа
// генерируем число и берем осток от деления, чтобы войти в диапазон
    }
}

void writeArrayInReverseToFile(const char *filename, int arr[], int size) {
    // const char *filename указатель на неизм строку (имя файла)
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        fprintf(file, "%d\n", arr[i]);  // запись в файл в обратном порядке
        // %d - целое число
    }
    fclose(file);
}

int main() {
    int arr[ARRAY_SIZE]; 
    srand(time(NULL));
/* инициализация генератора случайных чисел, возвращает время с начала
эпохи, stand устанавливает изначальное значение, это все позволяет
генерировать разные последовательности */
    generateRandomArray(arr, ARRAY_SIZE); 

    // Вывод массива в терминал
    printf("The array of random numbers is:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("n");

    writeArrayInReverseToFile("random_numbers.txt", arr, ARRAY_SIZE);
    printf("The array of random numbers is written in reverse order in the file random_numbers.txt.\n");

    return 0;
}
