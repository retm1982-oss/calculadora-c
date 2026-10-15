/* ============================================================
 * CALCULADORA EN LENGUAJE C
 * ------------------------------------------------------------
 * Programa que funciona como una calculadora interactiva de
 * consola: pide dos numeros y un operador, calcula el resultado
 * y lo muestra por pantalla, repitiendo hasta que el usuario
 * decida salir.
 *
 * Operadores soportados:
 *   +  suma
 *   -  resta
 *   *  multiplicacion
 *   /  division (detecta la division entre cero)
 *   %  modulo / residuo
 *   ^  potencia
 *
 * Restricciones:
 *   - Solo se permiten numeros de hasta 5 digitos.
 *   - Para salir escribe 'q' o 'Q' cuando pida un numero.
 *
 * Como compilar (usa la libreria matematica -lm):
 *   gcc   -std=c99 -Wall -Wextra -lm helloworld.c -o calculadora
 *   clang -std=c99 -Wall -Wextra -lm helloworld.c -o calculadora
 *
 * Como ejecutar:
 *   ./calculadora
 * ============================================================ */

/* Entrada/salida estandar: printf, fgets, puts */
#include <stdio.h>
/* Manejo de cadenas: strcspn (quitar salto de linea), strchr */
#include <string.h>
/* Conversiones y utilidades: strtod (texto a numero double) */
#include <stdlib.h>
/* Funciones matematicas: pow (potencia), fmod (modulo real) */
#include <math.h>
/* Clasificacion de caracteres: isdigit */
#include <ctype.h>

/* Maximo de digitos permitidos en cada numero ingresado */
#define MAX_DIGITOS 5

/* Cuenta cuantos digitos tiene una cadena (ignora signo, punto y espacios) */
static int contarDigitos(const char *s)
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit((unsigned char)s[i])) n++;
    }
    return n;
}

/* Lee un numero valido con maximo MAX_DIGITOS digitos.
   Devuelve 1 si se leyo bien, 0 si el usuario quiere salir (q). */
static int leerNumero(const char *mensaje, double *valor)
{
    char buffer[64];
    char *fin;
    double num;

    while (1) {
        printf("%s", mensaje);
        if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

        /* Quitar salto de linea */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* ¿Quiere salir? */
        if (buffer[0] == 'q' || buffer[0] == 'Q') return 0;

        /* ¿Vacio? */
        if (buffer[0] == '\0') {
            puts("  Entrada vacia. Intenta de nuevo.");
            continue;
        }

        /* ¿Tiene mas de MAX_DIGITOS digitos? */
        if (contarDigitos(buffer) > MAX_DIGITOS) {
            printf("  Error: solo se permiten hasta %d digitos.\n", MAX_DIGITOS);
            continue;
        }

        /* ¿Es un numero valido? */
        num = strtod(buffer, &fin);
        if (*fin != '\0') {
            puts("  Error: eso no es un numero valido.");
            continue;
        }

        *valor = num;
        return 1;
    }
}

int main(void)
{
    double a, b, r;
    char op;
    char linea[64];

    puts("===========================================");
    puts("   CALCULADORA C (maximo 5 digitos)");
    puts("===========================================");
    puts("Operadores: +  -  *  /  %%  ^");
    puts("Escribe 'q' en un numero para salir.\n");

    while (1) {
        /* 1) Pedir primer numero */
        if (!leerNumero("Primer numero : ", &a)) break;

        /* 2) Pedir operador */
        while (1) {
            printf("Operador      : ");
            if (!fgets(linea, sizeof(linea), stdin)) return 0;
            if (sscanf(linea, " %c", &op) == 1) {
                if (strchr("+-*/%%^", op)) break;
            }
            puts("  Operador invalido. Usa + - * / % ^");
        }

        /* 3) Pedir segundo numero */
        if (!leerNumero("Segundo numero: ", &b)) break;

        /* 4) Calcular */
        int error = 0;
        switch (op) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b; break;
            case '/':
                if (b == 0.0) { puts("  Error: division entre cero."); error = 1; }
                else r = a / b;
                break;
            case '%':
                if (b == 0.0) { puts("  Error: modulo entre cero."); error = 1; }
                else r = fmod(a, b);
                break;
            case '^':
                r = pow(a, b);
                break;
        }

        /* 5) Mostrar resultado */
        if (!error) {
            printf("  >>> %g %c %g = %g\n\n", a, op, b, r);
        }
    }

    puts("\nFin del programa.");
    return 0;
}