#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
//Написать программу, которая генерирует массив из псевдослучайных целых чисел и выводит его в консоль.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("The size of the array is not enteredn");
        return 1; // Завершаем программу с кодом ошибки
    }

    int size = atoi(argv[1]); 
    if (size <= 0) {
        printf("Invalid size of the arrayn");
        return 1; // Завершаем программу с кодом ошибки
    }

    float *randomFloats = malloc(size * sizeof(float)); 
    if (randomFloats == NULL) {
        printf("Memory allocation failedn");
        return 1; // Завершаем программу с кодом ошибки
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        randomFloats[i] = (float)rand() / RAND_MAX; 
    }

    printf("Random numbers:n");
    for (int i = 0; i < size; i++) {
        printf("%fn", randomFloats[i]); 
    }

    free(randomFloats); 
    return 0;
}

