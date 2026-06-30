# Laboratorio 5 — IE-0117

## Descripción

Este repositorio contiene la implementación en lenguaje C de cuatro estructuras de datos dinámicas, desarrolladas como parte del Laboratorio 5 del curso IE-0117 (Programación Bajo Plataformas Abiertas), Universidad de Costa Rica.

Las estructuras implementadas son:

- **Arreglo dinámico**: creación, inserción, eliminación, obtención por índice e impresión.
- **Lista enlazada simple**: inserción al inicio, al final y en posición específica; eliminación basada en valor; búsqueda; impresión hacia adelante.
- **Lista doblemente enlazada**: las mismas operaciones de la lista simple, más impresión hacia atrás.
- **Pila (Stack)**: push, pop, peek/top e isEmpty.

El proyecto está organizado de forma modular:

- `include/` → archivos de cabecera (.h) con la interfaz de cada estructura
- `src/` → archivos de implementación (.c) y el main.c con la demostración
- `Makefile` → automatización de la compilación

Cada estructura cuenta con su respectivo `.h` en `include/` y su `.c` en `src/`. El `main.c` demuestra todas las operaciones de las cuatro estructuras mediante impresiones en consola.

## Compilación

Desde la raíz del repositorio, ejecutar:

```bash
make
```

Esto genera el ejecutable `main` en la raíz del proyecto.

Para limpiar los archivos generados (objetos `.o` y el ejecutable):

```bash
make clean
```

## Ejecución

Una vez compilado, ejecutar:

```bash
./main
```

El programa imprimirá en consola la demostración de cada operación de las cuatro estructuras de datos.

## Verificación de memoria

El código fue verificado con Valgrind para confirmar la ausencia de memory leaks:

```bash
valgrind --leak-check=full ./main
```

Los resultados de esta verificación se incluyen en el reporte del laboratorio.

## Autor

Jónatan Arauz Jarquín — C5C527
