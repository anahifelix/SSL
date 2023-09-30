#include <stdio.h>
#include <ctype.h>
void procesar_palabra(char *cadena)
{
    int contador_numeros_decimales = 0;
    int contador_numeros_octales = 0;
    int contador_numeros_hexadecimales = 0;

    char * token = strtok(cadena, "$");
    printf("---------------------------------");

    while( token != NULL )
    {
        int resultado_evaluar_palabra = evaluar_palabra(token);
        if(resultado_evaluar_palabra == 1)
        {
            contador_numeros_decimales++;
        }
        else if(resultado_evaluar_palabra == 2)
        {
            contador_numeros_octales++;
        }
        else if(resultado_evaluar_palabra == 3)
        {
            contador_numeros_hexadecimales++;
        }

        token = strtok(NULL, "$");

        printf("---------------------------------");
    }
    printf("\n\n DECIMALES : %d , OCTALES: %d , HEXADECIMALES: %d\n", contador_numeros_decimales, contador_numeros_octales, contador_numeros_hexadecimales);
}

int evaluar_palabra(char *palabra)
{

    if (evaluar_decimal(palabra))
    {
        printf("\n%s verifica decimal \n",palabra);
        return 1;
    }
    if (evaluar_octal(palabra))
    {   
        printf("\n%s verifica octal \n",palabra);
        return 2;
    }
    if (evaluar_hexadecimal(palabra))
    {
        return 3;
    }

    return -1;
}

int evaluar_decimal(char *palabra)
{
    int respuesta_verifica_alfabeto_decimal = verifica_alfabeto_decimal(palabra);
    int respuesta_es_palabra_decimal = 0;

    if(respuesta_verifica_alfabeto_decimal==1)
    {
        respuesta_es_palabra_decimal =es_palabra_decimal(palabra);
    }
    return respuesta_es_palabra_decimal;
}

int verifica_alfabeto_decimal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(s[i]=='+'|| s[i]=='-'||isdigit(s[i])))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_decimal(char *palabra)
{
    const int estadoB = 2;
    const int estadoC = 2;
    const int estadoD = 3;

const int tt[4][12] =
{
    {estadoD, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoB, estadoB},
    {estadoD, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoD, estadoD},
    {estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoD, estadoD},
    {estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD, estadoD}
};


    int estado = 0;
    int i=0;
    int c= palabra[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_decimal(c)];
        c = palabra[++i];
    }

    if(estado == estadoC)
    {
        return 1;
    }
    return 0;
}

int columna_decimal(int c)
{
    switch(c)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;

    case '2':
        return 2;
        break;

    case '3':
        return 3;
        break;

    case '4':
        return 4;
        break;

    case '5':
        return 5;
        break;

    case '6':
        return 6;
        break;

    case '7':
        return 7;
        break;

    case '8':
        return 8;
        break;

    case '9':
        return 9;
        break;

    case '+':
        return 10;
        break;

    case '-':
        return 11;
        break;
    }
}
/******************* OCTAL ************************/
int evaluar_octal(char *palabra)
{
    int respuesta_verifica_alfabeto_octal = verifica_alfabeto_octal(palabra);
    int respuesta_es_palabra_octal= 0;


    if(respuesta_verifica_alfabeto_octal==1)
    {
        respuesta_es_palabra_octal = es_palabra_octal(palabra);
    }
    return respuesta_es_palabra_octal;
}

int verifica_alfabeto_octal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_octal(char *palabra)
{
    const int estadoB = 1;
    const int estadoC = 2;

    const int tt[3][8] =
    {
    {estadoB, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC},
    {estadoB, estadoB, estadoB, estadoB, estadoB, estadoB, estadoB, estadoB},
    {estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC, estadoC}
    };

    int estado = 0;
    int i=0;
    int c= palabra[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_octal(c)];
        c = palabra[++i];
    }

    if(estado == estadoB)
    {
        return 1;
    }
    return 0;
}

int columna_octal(int c)
{
    switch(c)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    }
}

/******************* HEXADECIMAL ************************/
int evaluar_hexadecimal(char *palabra)
{
    int respuesta_verifica_alfabeto_hexadecimal = verifica_alfabeto_hexadecimal(palabra);
    printf("verifica alfabeto hexadecimal %s? %d\n",palabra,respuesta_verifica_alfabeto_hexadecimal);
    int respuesta_es_palabra_hexadecimal= 0;

    if(respuesta_verifica_alfabeto_hexadecimal==1)
    {
        respuesta_es_palabra_hexadecimal = es_palabra_hexadecimal(palabra);
        printf("es palabra hexadecimal %s? %d\n",palabra,respuesta_es_palabra_hexadecimal);

    }
    else
    {
        printf("No se evalua la palabra %s porque no verifica alfabeto hexadecimal\n", palabra);
    }
    return respuesta_es_palabra_hexadecimal;
}

int verifica_alfabeto_hexadecimal(char *s)
{
    unsigned int i;

    for(i=0; s[i]; i++)
    {
        if(!(toupper(s[i])== 'A'||toupper(s[i])== 'B'||toupper(s[i])== 'C'||toupper(s[i])== 'D'||toupper(s[i])== 'E'||toupper(s[i])== 'F'||toupper(s[i])== 'X'||isdigit(s[i])))
        {
            return 0;
        }
    }

    return 1;
}

int es_palabra_hexadecimal(char *palabra)
{
    const int FINAL_STATE = 2;
    const int INVALID_STATE = 3;

    const int tt[4][24]=
    {
        {INVALID_STATE,INVALID_STATE,1,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
        {FINAL_STATE,FINAL_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
        {INVALID_STATE,INVALID_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE,FINAL_STATE},
        {INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE,INVALID_STATE},
    };

    int estado = 0;
    int i=0;
    int c= palabra[i];
    while(c!='\0')
    {
        estado=tt[estado][columna_hexadecimal(c)];
        c = palabra[++i];
    }

    if(estado == FINAL_STATE)
    {
        return 1;
    }
    return 0;
}

int columna_hexadecimal(int c)
{
    switch(c)
    {
    case 'x':
        return 0;
        break;
    case 'X':
        return 1;
        break;
    case '0':
        return 2;
        break;
    case '1':
        return 3;
        break;
    case '2':
        return 4;
        break;
    case '3':
        return 5;
        break;
    case '4':
        return 6;
        break;
    case '5':
        return 7;
        break;
    case '6':
        return 8;
        break;
    case '7':
        return 9;
        break;
    case '8':
        return 10;
        break;
    case '9':
        return 11;
        break;
    case 'a':
        return 12;
        break;
    case 'A':
        return 13;
        break;
    case 'b':
        return 14;
        break;
    case 'B':
        return 15;
        break;
    case 'c':
        return 16;
        break;
    case 'C':
        return 17;
        break;
    case 'd':
        return 18;
        break;
    case 'D':
        return 19;
        break;
    case 'e':
        return 20;
        break;
    case 'E':
        return 21;
        break;
    case 'f':
        return 22;
        break;
    case 'F':
        return 23;
        break;
    }
}
