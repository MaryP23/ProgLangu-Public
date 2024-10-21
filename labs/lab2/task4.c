#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
//*Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет случайными числами с плавающей 
//точкой в интервале (arg1, arg2), где arg1 и arg2 
//- также аргументы, вводимые при запуске программы, и выводит массив в консоль. Далее программа записывает массив в файл в отсортированном виде.
int compare(const void *a, const void *b) {
    float num1 = *(const float *)a;
    float num2 = *(const float *)b; 
    return (num1 > num2) - (num1 < num2);
}

float* createRandomArray(int size, float arg1, float arg2) {  
    float *array = malloc(size * sizeof(float)); 
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed");
     printf("\n");
        exit(1); 
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = arg1 + ((float)rand() / RAND_MAX) * (arg2 - arg1);
    }
    return array; 
}

void writeArrayToFile(const char *filename, float *array, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing");
     printf("\n");
        exit(1); 
    }
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%.2f", array[i]);
     printf("\n");
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) { 
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <size> <arg1> <arg2>", argv[0]);
     printf("\n");
        return 1;
    }

    int size = atoi(argv[1]); 
    float arg1 = atof(argv[2]); 
    float arg2 = atof(argv[3]);
    
    srand(time(NULL));
    float *array = createRandomArray(size, arg1, arg2); 

    printf("The generated array:");
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
     printf("\n");
    }
    qsort(array, size, sizeof(float), compare);
    
    writeArrayToFile("sorted_array.txt", array, size);
printf("\n");    
    free(array); 

    return 0;
}
