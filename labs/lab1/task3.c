#include<stdio.h>
int main(int number, char *argv[]) { //массив массивов, целые числа
  if (number <2) { 
    printf("There are no arguments for output.\n");// переход на новую строку
    return 1; 
    }
  printf("Number of arguments %d\n", number - 1);
  printf("Arguments for output:\n");
  for (int i = 1; i < number; i++) { 
    printf("%d: %s\n", i, argv[i]); 
  }
  return 0; 
  }
