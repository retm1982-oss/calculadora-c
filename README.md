# Calculadora en C

Calculadora interactiva de consola escrita en **lenguaje C** (estándar C99).

## Características

- Operaciones con números reales (admite decimales):
  - `+` suma
  - `-` resta
  - `*` multiplicación
  - `/` división (detecta la división entre cero)
  - `%` módulo / residuo
  - `^` potencia
- Validación de entrada: rechaza números inválidos, entradas vacías y números con más de 5 dígitos.
- Bucle interactivo: puedes encadenar varias operaciones sin reiniciar el programa.
- Salida escribiendo `q` o `Q` cuando pide un número.

## Compilar

El programa usa la librería matemática (`pow`, `fmod`), por lo que hay que enlazarla con `-lm`.

Con **gcc**:

```bash
gcc -std=c99 -Wall -Wextra -lm helloworld.c -o calculadora
```

Con **clang**:

```bash
clang -std=c99 -Wall -Wextra -lm helloworld.c -o calculadora
```

## Ejecutar

```bash
./calculadora
```

## Ejemplo de uso

```
===========================================
   CALCULADORA C (maximo 5 digitos)
===========================================
Operadores: +  -  *  /  %  ^
Escribe 'q' en un numero para salir.

Primer numero : 5
Operador      : +
Segundo numero: 3
  >>> 5 + 3 = 8

Primer numero : 2
Operador      : ^
Segundo numero: 10
  >>> 2 ^ 10 = 1024

Primer numero : q

Fin del programa.
```

## Estructura del código

- `contarDigitos()` → cuenta cuántos dígitos tiene una cadena (ignora signo, punto y espacios).
- `leerNumero()` → lee y valida un número desde `stdin`, aplicando el límite de dígitos y detectando la salida (`q`).
- `main()` → bucle principal: pide primer número, operador y segundo número, calcula y muestra el resultado.

## Pruebas realizadas

El programa fue **compilado y probado** antes de subirlo. Compila sin warnings con
`clang -std=c99 -Wall -Wextra -lm` (y con `gcc` usando el flag `-lm`).

Casos verificados con sus resultados reales:

| Entrada                  | Resultado                    |
|--------------------------|------------------------------|
| `5 + 3`                  | `8`                          |
| `10 - 4`                 | `6`                          |
| `7 * 6`                  | `42`                         |
| `8 / 2`                  | `4`                          |
| `2 ^ 10`                 | `1024`                       |
| `9 % 4`                  | `1`                          |
| `3.5 + 2.25`             | `5.75`                       |
| `5 / 0`                  | Error: división entre cero   |
| `5 ? 3`                  | Error: operador inválido     |
| `123456 + 1`             | Error: más de 5 dígitos      |
| `q` (salir)              | Fin del programa             |
| (entrada vacía)          | Aviso: entrada vacía         |

## Autoría

Este código fue **generado y probado por un asistente de IA** (LM Studio Bionic).
La IA se encargó de escribir el código, compilarlo, ejecutar y verificar cada uno
de los casos de prueba listados arriba, y preparar el repositorio. El resultado
fue revisado operación por operación y funciona correctamente.
