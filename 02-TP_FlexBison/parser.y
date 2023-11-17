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
    INICIO listaSentencias FIN                      {if (yynerrs || yylexerrs) YYABORT; return -1;}
; 

listaSentencias:
    sentencia  
    | sentencia listaSentencias
;

sentencia:
    ID ASIGNACION expresion PUNTOYCOMA  { printf("MI SENTENCIA ES: %d,  %d\n", $1, $3); }
    | LEER '(' listaID ')' PUNTOYCOMA 
    | ESCRIBIR '(' listaExpresion ')' PUNTOYCOMA
;

listaID: 
    ID                                          { printf("MI ID EES: %d\n", $1); }
    | listaID  ',' ID                           { printf("MI ID DE LISTA ES: "); }
;

listaExpresion: 
    expresion {printf("expresion: %d\n", $1);} 
    | listaExpresion ',' expresion {printf("lista expresion: %d\n", $3);}
;

expresion: 
    primaria { printf("id de expr: ID, %d\n", $1); }  
    | expresion '+' primaria { printf("expresion: %d + %d\n", $1, $3); } | expresion '-' primaria { printf("expresion: %d - %d\n", $1, $3); }
; 

primaria: 
    ID { printf("primari id: ID, %d\n", atoi($1)); }  
    | CONSTANTE { printf("primaria: CONSTANTE, %d\n", $1); } 
    |'(' expresion ')' { printf("expresion: %d\n", $2); }
;

%%
int main() {
    yyparse();
}

void yyerror (char *s){
    printf ("mi error personalizado es %s\n",s);
}

