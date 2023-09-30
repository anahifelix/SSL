#include "menu.h"

int main()
{

//mostrarMenu();
    /*

    char cadena[100] = "-01230$-01231$1A$012347$0xFFFF";
    char string[LEN] = "2+3*4/3-2";
    char stringA[LEN];
    char cadena_Archivo[100];
    char archivoTxt[20] = "automata.txt";
    FILE* automata = fopen(archivoTxt, "r");
    int opcion_Menu_Principal;
    int opcion_Menu_Secundario;
    int opcion_Menu_Parseado;
    Express e;

    do
    {
        mostrarMenuPrincipal(&opcion_Menu_Principal);

        switch (opcion_Menu_Principal)
        {
        case 1:
            mostrarMenuParseado(&opcion_Menu_Parseado);

            switch (opcion_Menu_Parseado)
            {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%s",stringA);
                initializeExpress(&e, stringA);
                parse(&e);
                printf("El resultado es: %d\n", solve(&e));
                break;
            case 2:
                printf("Operacion de Ejemplo: %s\n",string);
                initializeExpress(&e, string);
                parse(&e);
                printf("El resultado es: %d\n", solve(&e));
                break;
            }
            break;
        case 2:
            mostrarMenuSecundario(&opcion_Menu_Secundario);

                switch (opcion_Menu_Parseado) {
                    case 1:
                    printf("Ingrese un valor: ");
                    scanf("%s",stringA);
                    generaParser(e, stringA);
                    break;
                    case 2:
                    printf("Operacion de Ejemplo: %s\n",string);
                    generaParser(e, string);
                    break;
                }
                break;
            case 2:
                mostrarMenuSecundario(&opcion_Menu_Secundario);

                switch (opcion_Menu_Secundario) {
                    case 1:
                        printf("Recuerde que cada palabra debe finalizar con $");
                        procesar_palabra(cadena);
                        break;
                    case 2:
                        if (automata == NULL) {
                            printf("archivo no encontrado\n");
                            exit(1);
                        } else {
                            while (fgets(cadena_Archivo, sizeof(cadena_Archivo), automata) != NULL) {
                                procesar_palabra(cadena_Archivo);
                            }
                        }
                        break;
                    }
                }
                break;
            }
            break;
        case 3:
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
    while (opcion_Menu_Principal != 3);

    return 0;
    */
}
