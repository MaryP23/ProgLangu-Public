/*Описать грамматику, позволяющую проводить трансляцию арифметических выражений, состоящих из вещественных чисел, знаков «+», «-», «*», «/» и скобок из инфиксной записи в постфиксную. */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define YYSTYPE double
int yyparse();
int yylex(void);
void yyerror(const char *str){
        fprintf(stderr,"ошибка: %s\n",str);
}
int yywrap(){
        return 1;
} 
int main(){
        yyparse();
}
%}
%union{
	double flo;
};
%token <flo> NUMBER
%token PLUS MINUS MULTYPLY DIVISION
%token OPEN CLOSE
%token EOL
%%
command: %empty
	| command exp EOL { printf(" "); } 
;
exp: factor
| exp PLUS factor { printf("+ "); }
| exp MINUS factor { printf("- "); }
;
factor: term
| factor MULTYPLY term { printf("* "); }
| factor DIVISION term { printf("/ "); }
;
term: NUMBER  { printf(" %.2f ",$1); }
| OPEN exp CLOSE{ }
;
%%
