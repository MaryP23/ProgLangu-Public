#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
//Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет случайными числами с плавающей точкой в интервале (0, 1) и выводит этот массив в консоль.
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("The size of the array is not entered");
     printf("\n");
        return 1; 
    }

    int size = atoi(argv[1]); 
    if (size <= 0) {
        printf("Invalid size of the array");
     printf("\n");
        return 1; 
    }

    float *randomFloats = malloc(size * sizeof(float));/*sizeof(float) возвращает
    размер одного элемента типа float в байтах. В итоге
    эта строка создает массив из size элементов типа float */
    if (randomFloats == NULL) {
        printf("Memory allocation failed");
     printf("\n");
        return 1; 
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        randomFloats[i] = (float)rand() / RAND_MAX; 
    }

    printf("Random numbers:");
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", randomFloats[i]); 
    }

    free(randomFloats); /* освобождение выделенной памяти ( Если вы не освободите память, это приведет к утечке памяти (memory leak), что означает, 
    что программа использует больше памяти, чем необходимо, и эта память не может быть повторно использована до завершения программы.) */
    return 0;
}
