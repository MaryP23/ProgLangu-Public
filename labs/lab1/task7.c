#include <stdio.h>
#include <stdlib.h>

void displayFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");

    char line[256]; // массив новой строки
    printf("The contents of the filel: '%s':\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    const char *filename = "task7/checktask7.txt"; 
    char newLine[256]; 

    printf("The contents of the file before the changes:\n");// вывод до измениений
    displayFileContent(filename);

    printf("Enter the line you want to add to the file: ");// новая строка
    scanf(" %[^\n]", newLine); 
  
    FILE *file = fopen(filename, "a"); // a- добавление в конец

    fprintf(file, "%s\n", newLine); // записываем строку в файл
    fclose(file); 

    printf("\nThe contents of the with the entered sentence:\n");// вывод 
    displayFileContent(filename);

    return 0;
