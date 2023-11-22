%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

void yyerror(char *s);
int yylex();

%}

letra                   [a-zA-Z]
numero                  [0-9]
identificador           {letra}({letra}|{numero})*
constante               {numero}({numero})*

%%

"inicio"                {return INICIO;}
"fin"                   {return FIN;}
"leer"                  {return LEER;}
"escribir"              {return ESCRIBIR;}

{identificador}         {return ID;} 
{constante}             {yylval.cte = atoi(yytext); return CONSTANTE;}
"("                     {return '(';}
")"                     {return ')';}
";"                     { return  PUNTOYCOMA;}
"+"                     {return '+';}
"-"                     {return '-';}
","                     {return ',';}
":="                    {return ASIGNACION;}

%%

int yywrap(void) {
    return 1;
}
