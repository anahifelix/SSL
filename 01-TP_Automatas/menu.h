#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"
#include "evaluation_utils.h"
#include "parser.h"

char cadenaPrueba[100] = "-01230$-01231$1A$012347$0xFFFF";
char operation_string[40] = "2+3*4/3-2";
char stringA[40];
void mostrar_menu()
{
    int opcion_menu;
    do
    {
        printf("1. Parsear operaciones matematicas desde archivo.\n");
        printf("2. Parsear operaciones matematicas desde consola.\n");

        printf("3. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal desde archivo\n");
        printf("4. Evaluar una cadena en los sistemas numericos Decimales, Octales y Hexadecimal desde consola\n");

        printf("5. Salir.\n\n\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion_menu);

        switch (opcion_menu)
        {
        case 1:
            //mostrarMenuParseado();
            break;
        case 2:
            //mostrarMenuSecundario();
            break;
        case 3:
           // printf("Saliendo del programa.\n");
            break;
        case 4:
           // printf("Saliendo del programa.\n");
            break;
        case 5:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
    while (opcion_menu != 5);
}





char obtenerDatosArchivo()
{
    char cadena_Archivo[40];
    char archivoTxt[20] = "automata.txt";
    FILE* automata = fopen(archivoTxt, "r");
    if (automata == NULL)
    {
        printf("archivo no encontrado\n");
        exit(1);
    }
    else
    {
        fgets(cadena_Archivo, sizeof(cadena_Archivo), automata);
        return cadena_Archivo;
    }
}

char* obtenerDatosConsola ()
{
    char cadena_consola[100];
    printf("ingrese una cadena: ");
    scanf("%s",&cadena_consola);
    return cadena_consola;
}
