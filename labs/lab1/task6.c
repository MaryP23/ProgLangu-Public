#include <stdio.h> 
#include <stdlib.h>
#define MAX_LINE_LENGTH 256 

void copy_first_three_lines(const char *input_filename, const char *output_filename) { 
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    char line[MAX_LINE_LENGTH]; // массив для хранения строки
    int line_count = 0; 
    while (fgets(line, sizeof(line), input_file) != NULL && line_count < 3) { // читаем строку и храним , если конец файла не достигнут и кол-во строчек меньше 3 ,то продолжаем цикл
        fputs(line, output_file); // запись строки
        line_count++;
    }
     fclose(input_file);
     fclose(output_file);
}

void print_file_contents(const char *filename) { 
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH]; // массив символов фиксированной длины
    while (fgets(line, sizeof(line), file) != NULL) { 
        printf("%s", line); 
    }
    fclose(file);
}

int main() {
    const char *input_filename = "checktask6.txt"; 
    const char *output_filename = "output.txt"; 
    copy_first_three_lines(input_filename, output_filename); 
    printf("The contents of the input file:\n");
    print_file_contents(input_filename);
    printf("\nThe contents of the output file:\n");
    print_file_contents(output_filename);
}
