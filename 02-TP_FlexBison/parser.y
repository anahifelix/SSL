%{
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);
extern int yyleng;

%}

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA 
%token <id> ID
%token <cte> CONSTANTE

%union {
    char* id;
    int cte;
}

%right ASIGNACION

%% 
programa:
      INICIO listaSentencias FIN                      
; 

listaSentencias:
    sentencia | sentencia listaSentencias
;

sentencia:
    ID {printf("la longitud es: %d",yyleng);if(yyleng>32) yyerror("muy largo che");} ASIGNACION expresion PUNTOYCOMA | LEER '(' listaID ')' PUNTOYCOMA | ESCRIBIR '(' listaExpresion ')' PUNTOYCOMA
;

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

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
