/*Описать грамматику, позволяющую проводить трансляцию арифметических выражений, состоящих из целых чисел, знаков «+», «-», «*», «/» и скобок из инфиксной записи в постфиксную.*/
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
%token NUMBER PLUS MINUS MULTYPLY DIVISION OPEN CLOSE EOL
%%
commands: 
| commands command
;
command: exp
| EOL { printf("\n"); } 
;
exp: factor
| exp PLUS factor { printf("+"); }
| exp MINUS factor { printf("-"); }
;
factor: term
| factor MULTYPLY term { printf("*"); }
| factor DIVISION term { printf("/"); }
;
term: NUMBER  { printf("%.2f",$1); }
| OPEN exp CLOSE{ $$ = $2; }
;
%%
