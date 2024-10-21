#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 
#define NAME_LENGTH 100 

typedef struct {
    char name[NAME_LENGTH];
    float price; 
} Product;

void readProducts(const char *filename, Product products[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }
    
    *count = 0; 
    while (fscanf(file, "%99s %f", products[*count].name, &products[*count].price) == 2) {
        (*count)++;
        if (*count >= MAX_PRODUCTS) {
            break; // Предотвращаем переполнение массива
        }
    }
    fclose(file);
}

int compareProducts(const void *a, const void *b) { 
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return (productA->price > productB->price) - (productA->price < productB->price);
}

void writeProducts(const char *filename, Product products[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f\n", products[i].name, products[i].price); 
    }
    fclose(file);
}

int main() {
    Product products[MAX_PRODUCTS];
    int count; 
    readProducts("food_lab2task5.txt", products, &count);
    qsort(products, count, sizeof(Product), compareProducts);
    writeProducts("food_lab2task5(2).txt", products, count);
    return 0;
}
