%{
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);

extern int yynerrs;
extern int yylexerrs;

%}

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA IMPRIMIR
%token <id> ID
%token <cte> CONSTANTE

%union {
    char* id;
    int cte;
}

%left '+' '-' ',' 
%right ASIGNACION

%type <cte> expresion primaria 

%% 

programa:
    INICIO listaSentencias FIN                      { if (yynerrs || yylexerrs) YYABORT; return -1;}
; 

listaSentencias:
    sentencia  
    | sentencia listaSentencias
;

sentencia:
    ID ASIGNACION expresion PUNTOYCOMA              { printf("Mi expresion de la sentencia es: %d\n", $3); }
    | LEER '(' listaID ')' PUNTOYCOMA 
    | ESCRIBIR '(' listaExpresion ')' PUNTOYCOMA
;

listaID: 
    ID                                               
    | listaID  ',' ID                                
;

listaExpresion: 
    expresion                                       { printf("Mi expresion es: %d\n", $1); } 
    | listaExpresion ',' expresion                  { printf("Mi lista expresion: %d\n", $3); }
;

expresion: 
    primaria                                        
    | expresion '+' primaria                        { $$ = $1 + $3; } 
    | expresion '-' primaria                        { $$ = $1 - $3; }
; 

primaria: 
    ID                                              { $$ = obtenerValor($1); }
    | CONSTANTE                                     { $$ = $1; } 
    |'(' expresion ')'                              { $$ = $2; }
;

%%


int main() {
    yyparse();
}

void yyerror (char *s){
    printf ("Mi error es %s\n",s);
}
