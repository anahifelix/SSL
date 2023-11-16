*** PROLOGO**

%{
#include <stdio.h>
#include <stdlib.h> 
%}

// DECLARACIONES BISON

%union {
    char* id;
    int cte;
}

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA 
%token <id> ID
%token <cte> CONSTANTE

// REGLAS GRAMATICALES

programa:
       INICIO listaSentencias FIN                       {if (yynerrs || yylexerrs) YYABORT; return -1} // verifica si ha habido errores durante el análisis lex o sintact
; 

listaSetencias:
   sentencia | sentencia listaSentencias;

sentencia:
   ID {if(yyleng>32) yyerror("MUY LARGO");} ASIGNACION expresion PUNTOYCOMA | leer '(' listaID ')' PUNTOYOMA | escribir '(' listaExpresion ')' PUNTOYCOMA
;
// no es necesario declarar todos los tokens, podemos usar comillas

listaID: ID | listaID  ',' listaID ID
;

listaExpresion: expresion | listaExpresion  ',' listaExpresion expresion
;

expresion: primaria | expresion operadorAditivo primaria 
; 

primaria: ID |CONSTANTE |'(' expresion '('
;

operadorAditivo: '+' | '-'
;
