*** PROLOGO**

%{
#include <stdio.h>
%}

%union{
   char* cadena;
   int num;
} 

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA 
%token <id> ID
%token <cte> CONSTANTE

programa:
       INICIO listaSentencias FIN                       {if (yynerrs || yylexerrs) YYABORT; return -1}
; 
