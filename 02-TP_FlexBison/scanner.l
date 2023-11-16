*************definiciones****************

%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

void mostrarError();
%}

numero                  [0-9]
letra                   [a-zA-Z]
identificador           {letra}({letra}|{numero})*
constante               ({numero})+

*************reglas****************
%%
"inicio"                return INICIO;
"fin"                   return FIN;
"leer"                  return LEER;
"escribir"              return ESCRIBIR;


{identificador}         {yylval.id = strdup(yytext); return ID;} // copia caracteres correspondiente al identificador (capturada por yytext) en una nueva cn la función strdup.
{constante}             {yylval.cte = atoi(yytext); return CONSTANTE;} // convierte la constante a un valor numm
"("                     return '(';
")"                     return ')';
";"                     return  PUNTOYCOMA;
"+"                     return '+';
"-"                     return '-';
"*"                     return '*';
","                     return ',';
":="                    return ASIGNACION;
 
%%
*************codigo****************
void mostrarEror() {
  return 1
}
