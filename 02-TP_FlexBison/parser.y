%{
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);

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
    INICIO listaSentencias FIN                      
; 

listaSentencias:
    sentencia | sentencia listaSentencias
;

sentencia:
    ID ASIGNACION expresion PUNTOYCOMA | LEER '(' listaID ')' PUNTOYCOMA | ESCRIBIR '(' listaExpresion ')' PUNTOYCOMA
;

listaID: 
    ID | listaID  ',' ID
;

listaExpresion: 
    expresion {printf("expresion: %d\n", $1);} | listaExpresion ',' expresion {printf("lista expresion: %d\n", $3);}
;

expresion: 
    primaria | expresion '+' primaria { printf("expresion: %d + %d\n", $1, $3); } | expresion '-' primaria { printf("expresion: %d - %d\n", $1, $3); }
; 

primaria: 
    ID { $$ = atoi($1); printf("primaria: ID, $$ = %d\n", $$); }  | CONSTANTE { $$ = $1; printf("primaria: CONSTANTE, $$", $$); } |'(' expresion ')'  {$$ = $2; printf("expresion: (%d)\n", $$); }
;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
}
