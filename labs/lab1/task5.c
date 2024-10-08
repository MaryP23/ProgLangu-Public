#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");// открываем файл на чтение , r - чтение нулевой арг это имя программы
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) { // посимвольное чтение файла и вывод ,пока не достигнут конец 
        putchar(ch);
    }

    fclose(file);
    return 0;
}
