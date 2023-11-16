*************definiciones****************

%{
#include <stdio.h>
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
