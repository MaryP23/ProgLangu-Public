#include <stdio.h> 
#include <stdlib.h>// работа с файлами
#include <string.h> // со строками

/*

*/

int main() {
    char filename[100], info[100];
    FILE *fp, *temp; // указатель на файл , хранение его имени и содержимого 
    printf("Enter the file name: ");
    scanf("%s", filename);
    //strcpy(filename,"checktask8.txt");

    printf("Enter sentence: ");
    scanf(" %[^\n]", info); 
    //strcpy(info,"jrsjryskrysk");
  
    fp = fopen(filename, "r");//для чтения
    temp = fopen("time.txt", "w");// для записи
    fprintf(temp, "%s\n", info);// считываем информацию
    
    char line[256];
      while (fgets(line, sizeof(line), fp) != NULL) {
          fprintf(temp, "%s", line);
     }
     fclose(fp);
     fclose(temp);
     
    remove(filename);// замена временного файла
    rename("time.txt", filename);
     
    printf("The sentence added to the beginnig of the file %s.\n", filename);
    printf("\nSoderzhimoe fajla %s:\n", filename);
     fp = fopen(filename, "r");
     while (fgets(line, sizeof(line), fp) != NULL) {
         printf("%s", line);
     }
     fclose(fp);


    return 0;
}
