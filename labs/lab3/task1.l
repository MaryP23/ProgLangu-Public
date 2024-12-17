%{
#include <stdio.h>
%}
//Написать программу для генератора лексических анализаторов, выводящую в консоль переданный токен.
%%
[a-zA-Z]*    			          printf("WORD ");
[0-9]+        			        printf("NUMBERS ");
\"                      		printf("QUOTE ");
\{                      		printf("OBRACE ");
\}                      		printf("EBRACE ");
;                       		printf("SEMICOLON ");
\n                      		printf("\n");              
%%
