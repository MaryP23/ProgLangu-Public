#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 
#define NAME_LENGTH 100 
//Создать структуру для хранения данных о названии и цене товара. Считать из входного файла данные о товарах. Написать функцию для сортировки товаров по цене. Вывести отсортированные данные в выходной файл.
typedef struct {
// создаем новый тип данных и структуру, содержащую два поля //
    char name[NAME_LENGTH];
    float price; 
} Product;// новый тип данных назв товара + цена

void readProducts(const char *filename, Product products[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("File opening error");
        exit(EXIT_FAILURE);
    }
    
    *count = 0; 
    while (fscanf(file, "%99s %f", products[*count].name, &products[*count].price) == 2) {
        /* fscanf считываем данные из файла, %99s строки длинной
99 символов, последний - терминатор, %f тип данных для
цены товара, обращаемся к массиву по номерам *count,
записываем назв товара в поле name, == 2 это проверка, что
считаны оба элемента, ноль терминатор - обозначение
конца строки, обращаемся к товару, получаем его цену,
& - получение адреса переменной */
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
    // получаем доступ к ценам и сравниваем, возвращает отрицательное значение, если первый продукт дешевле
}

void writeProducts(const char *filename, Product products[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("File opening error");
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
    /* вызываем стандартную функцию сортировки,
принимающую массив, кол-во элем и размер одного элем,
имя функции сравнения - compareProducts */
    writeProducts("food_lab2task5(2).txt", products, count);
    return 0;
}
