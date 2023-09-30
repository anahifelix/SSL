#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Estructura para la pila de operandos
typedef struct {
    int *items;
    int top;
    int size;
} OperandStack;

// Estructura para la pila de operadores
typedef struct {
    char *items;
    int top;
    int size;
} OperatorStack;

// Funciones para la pila de operandos
OperandStack *createOperandStack() {
    OperandStack *stack = (OperandStack *)malloc(sizeof(OperandStack));
    stack->items = (int *)malloc(sizeof(int));
    stack->top = -1;
    stack->size = 1;
    return stack;
}

void pushOperand(OperandStack *stack, int value) {
    stack->top++;
    if (stack->top >= stack->size) {
        // Aumentar el tamaño de la pila si es necesario
        stack->size *= 2;
        stack->items = (int *)realloc(stack->items, sizeof(int) * stack->size);
    }
    stack->items[stack->top] = value;
}

int popOperand(OperandStack *stack) {
    if (stack->top >= 0) {
        int value = stack->items[stack->top];
        stack->top--;
        return value;
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
        printf("Error: Pila de operandos vacía.\n");
        exit(1);
    }
}

void freeOperandStack(OperandStack *stack) {
    free(stack->items);
    free(stack);
}

// Funciones para la pila de operadores
OperatorStack *createOperatorStack() {
    OperatorStack *stack = (OperatorStack *)malloc(sizeof(OperatorStack));
    stack->items = (char *)malloc(sizeof(char));
    stack->top = -1;
    stack->size = 1;
    return stack;
}

void pushOperator(OperatorStack *stack, char value) {
    stack->top++;
    if (stack->top >= stack->size) {
        // Aumentar el tamaño de la pila si es necesario
        stack->size *= 2;
        stack->items = (char *)realloc(stack->items, sizeof(char) * stack->size);
    }
    stack->items[stack->top] = value;
}

char popOperator(OperatorStack *stack) {
    if (stack->top >= 0) {
        char value = stack->items[stack->top];
        stack->top--;
        return value;
    } else {
        // Manejar error de desbordamiento de la pila (puedes implementar manejo de errores adecuado)
        printf("Error: Pila de operadores vacía.\n");
        exit(1);
    }
}

void freeOperatorStack(OperatorStack *stack) {
    free(stack->items);
    free(stack);
}

int evaluarExpresionRPN(const char *expresionRPN) {
    OperandStack *stack = createOperandStack();

    for (int i = 0; expresionRPN[i] != '\0'; i++) {
        char caracter = expresionRPN[i];

        if (isdigit(caracter) || (caracter == '-' && isdigit(expresionRPN[i + 1]))) {
            // Leer un número
            int numero = strtol(&expresionRPN[i], NULL, 10);
            pushOperand(stack, numero);
            // Mover el índice 'i' al final del número
            while (isdigit(expresionRPN[i]) || expresionRPN[i] == '-') {
                i++;
            }
            i--;
        } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
            int operand2 = popOperand(stack);
            int operand1 = popOperand(stack);
            switch (caracter) {
                case '+':
                    pushOperand(stack, operand1 + operand2);
                    break;
                case '-':
                    pushOperand(stack, operand1 - operand2);
                    break;
                case '*':
                    pushOperand(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        pushOperand(stack, operand1 / operand2);
                    } else {
                        printf("Error: División por cero.\n");
                        exit(1);
                    }
                    break;
            }
        }
    }

    int resultado = popOperand(stack);

    // Liberar la memoria de la pila de operandos
    freeOperandStack(stack);

    return resultado;
}

// Función para determinar la prioridad de los operadores
int getPriority(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }

    return 0; // Operador no reconocido

}

// Función para convertir expresión infija a posfija sin paréntesis
void infixToPostfix(const char *expresionInfix, char **expresionPostfix) {
    OperatorStack *stack = createOperatorStack();
    int outputIndex = 0;
    int postfixSize = 1; // Tamaño inicial de la expresión posfija
    *expresionPostfix = (char *)malloc(sizeof(char) * postfixSize);

    for (int i = 0; expresionInfix[i] != '\0'; i++) {
        char caracter = expresionInfix[i];

        if (isdigit(caracter)) {
            // Si es un dígito, agregarlo directamente a la salida
            while (isdigit(expresionInfix[i])) {
                (*expresionPostfix)[outputIndex++] = expresionInfix[i++];
                // Aumentar el tamaño de la expresión posfija si es necesario
                if (outputIndex >= postfixSize) {
                    postfixSize *= 2;
                    *expresionPostfix = (char *)realloc(*expresionPostfix, sizeof(char) * postfixSize);
                }
            }
            (*expresionPostfix)[outputIndex++] = ' '; // Separador
            i--; // Retroceder un paso para compensar el incremento en el bucle for
        } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
            // Si es un operador, desapilar operadores de mayor o igual prioridad y agregarlos a la salida
            while (stack->top >= 0 && getPriority(stack->items[stack->top]) >= getPriority(caracter)) {
                (*expresionPostfix)[outputIndex++] = popOperator(stack);
                // Aumentar el tamaño de la expresión posfija si es necesario
                if (outputIndex >= postfixSize) {
                    postfixSize *= 2;
                    *expresionPostfix = (char *)realloc(*expresionPostfix, sizeof(char) * postfixSize);
                }
                (*expresionPostfix)[outputIndex++] = ' '; // Separador
            }
            pushOperator(stack, caracter); // Apilar el operador actual
        }
    }

    // Desapilar cualquier operador restante en la pila
    while (stack->top >= 0) {
        (*expresionPostfix)[outputIndex++] = popOperator(stack);
        // Aumentar el tamaño de la expresión posfija si es necesario
        if (outputIndex >= postfixSize) {
            postfixSize *= 2;
            *expresionPostfix = (char *)realloc(*expresionPostfix, sizeof(char) * postfixSize);
        }
        (*expresionPostfix)[outputIndex++] = ' '; // Separador
    }

    (*expresionPostfix)[outputIndex] = '\0'; // Terminar la cadena

    // Liberar la memoria de la pila de operadores
    freeOperatorStack(stack);

    printf("traduccion fin");
    printf("%d",expresionPostfix);
}

void solve(char *expresionInfix,char *expresionPostfix){

    printf("Ingrese una expresion aritmetica: ");

    size_t len = 0;
    expresionInfix = (char *)malloc(sizeof(char) * 100); // Reservar memoria para la entrada
    if (expresionInfix == NULL) {
        printf("Error: No se pudo asignar memoria para la entrada.\n");
        return 1;
    }

    if (fgets(expresionInfix, 100, stdin) == NULL) {
        printf("Error al leer la entrada.\n");
        return 1;
    }

    expresionInfix[strlen(expresionInfix) - 1] = '\0'; // Eliminar el salto de línea al final

    infixToPostfix(expresionInfix, &expresionPostfix);
    printf("Expresión en notación posfija: %s\n", expresionPostfix);

    int resultado = evaluarExpresionRPN(expresionPostfix);
    printf("Resultado: %d\n", resultado);

    free(expresionInfix); // Liberar la memoria de la entrada
    free(expresionPostfix); // Liberar la memoria de la expresión posfija
}
