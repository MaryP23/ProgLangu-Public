%{
#include <stdio.h>
%}

%%
[a-zA-Z]*    			          printf("WORD ");
[0-9]+        			        printf("NUMBERS ");
\"                      		printf("QUOTE ");
\{                      		printf("OBRACE ");
\}                      		printf("EBRACE ");
;                       		printf("SEMICOLON ");
\n                      		printf("\n");
[ \t]+                 
%%
