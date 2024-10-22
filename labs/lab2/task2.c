#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15 
#define MAX_RANDOM 1000
//Написать программу, которая генерирует массив из псевдослучайных целых чисел и записывает в файл в обратном порядке.
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANDOM; 
    }
}

void writeArrayInReverseToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        fprintf(file, "%d\n", arr[i]); 
    }
    fclose(file);
}

int main() {
    int arr[ARRAY_SIZE]; 
    srand(time(NULL));

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
