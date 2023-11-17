%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

void yyerror(char *s);
int yylex();

char buffer[32];
int yylexerrs;
%}

letra                   [a-zA-Z]
numero                  [0-9]
identificador           {letra}({letra}|{numero})*
constante               ({numero})+

%%

"inicio"                 {return INICIO;}
"fin"                   {return FIN;}
"leer"                  {return LEER;}
"escribir"              {return ESCRIBIR;}

{identificador}         {yylval.id = strdup(yytext); return ID;} 
{constante}             {yylval.cte = atoi(yytext); return CONSTANTE;}
"("                     {return '(';}
")"                     {return ')';}
";"                     { return  PUNTOYCOMA;}
"+"                     {return '+';}
"-"                     {return '-';}
","                     {return ',';}
":="                    {return ASIGNACION;}
[ \t\n]                 ;
.                       {yylexerrs++; sprintf(buffer,"Error Lexico: %s es un caracter invalido", yytext); yyerror(buffer);}

%%

int yywrap(void) {
    return 1;
}
