/*Описать грамматику, позволяющую проводить трансляцию арифметических выражений, состоящих из вещественных чисел, знаков «+», «-», «*», «/» и скобок из инфиксной записи в постфиксную. */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task4.tab.h"
%}
%%
[0-9]+[\.]?[0-9]* { yylval.flo= atof(yytext);return NUMBER; }
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULTYPLY;}
"/" {return DIVISION;}
"(" {return OPEN;}
")" {return CLOSE;}
\n  {return EOL;}
%%
