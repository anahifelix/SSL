%{
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);

extern int *yytext;

%}

%token INICIO FIN LEER ESCRIBIR PUNTOYCOMA 
%token <cte> CONSTANTE 
%token <id> ID 

%union {
    char* id;
    int cte;
}

%left '+' '-' ',' 
%right ASIGNACION

%type <cte> expresion primaria 

%% 

programa:
    INICIO listaSentencias FIN                      {
; 

listaSentencias:
    sentencia  
    | sentencia listaSentencias
;

sentencia:
    ID ASIGNACION expresion PUNTOYCOMA             
    | LEER '(' listaID ')' PUNTOYCOMA 
    | ESCRIBIR '(' listaExpresion ')' PUNTOYCOMA    
;

listaID: 
    ID                                                                          
    | listaID  ',' ID                             
;

listaExpresion: 
    expresion                                       { printf("Mi expresion es: %d\n", $1); } 
    | listaExpresion ',' expresion                  { printf("Mi lista de la expresion es: %d\n", $3); }
;

expresion: 
    primaria                                        
    | expresion '+' primaria                        { $$ = $1 + $3; printf("Mi suma es: %d\n", $$);} 
    | expresion '-' primaria                        { $$ = $1 - $3; ; printf("Mi resta es: %d\n", $$);}
; 

primaria: 
    ID                                              { $$ = $1; } 
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
