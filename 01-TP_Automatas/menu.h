#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluation_utils.h"
#include "parser.h"

void mostrarMenuParseado(void);
void mostrar_sub_menu(int);
void solve(char *expresionInfix);
void procesar_palabra(char *cadena);

char stringA[40];
char *expresionInfix = NULL;
char *expresionPostfix = NULL;
void mostrarMenu()
{
    int opcion_menu_principal;
    do
    {
        printf("1. Parsear operaciones matematicas.\n");
        printf("2. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal\n");
        printf("3. Salir.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_menu_principal);

        switch (opcion_menu_principal)
        {
        case 1:
        case 2:
            mostrar_sub_menu(opcion_menu_principal);
            break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
    while (opcion_menu_principal != 3);
}

void mostrar_sub_menu(int opcion_menu_principal)
{
    int opcion_Menu_Secundario;
    char cadena[100];
    FILE* fileBase;
    char archivoTxt[20];
    char *flagMenu;
    char expresionInfix[100];
    if (opcion_menu_principal == 1) {
        flagMenu = "1";
        strcpy(archivoTxt, "operaciones.txt");
    } else {
        flagMenu = "2";
        strcpy(archivoTxt, "automata.txt");
    }
    fileBase = fopen(archivoTxt, "r");
    if (fileBase == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    do
    {
        printf("1. Ingresar por consola.\n");
        printf("2. Ingresar por archivo.\n");
        printf("3. Volver al menu anterior.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_Menu_Secundario);
        //se maneja de igual forma que la pantalla principal
        switch (opcion_Menu_Secundario)
        {
        case 1:
            if (strcmp(flagMenu, "1") == 0){
                printf("Ingrese una expresion aritmetica: ");
                scanf("%s", expresionInfix);
                strcpy(archivoTxt,expresionInfix);
                solve(expresionInfix);
            }
            else{
            printf("ingrese una cadena: ");
            scanf("%s",cadena);
            procesar_palabra(cadena);
            }
            break;
        case 2:
            if (strcmp(flagMenu, "1") == 0){
                fgets(expresionInfix, sizeof(expresionInfix), fileBase);
                strcpy(archivoTxt,expresionInfix);
                solve(expresionInfix);
            }
            else{

            fgets(cadena, sizeof(cadena), fileBase);
            procesar_palabra(cadena);}
            break;
        case 3:
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
    while (opcion_Menu_Secundario != 3);

    fclose(fileBase);
    }