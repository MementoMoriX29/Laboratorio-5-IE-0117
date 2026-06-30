#ifndef PILA_H
#define PILA_H
#include <stddef.h>

/* Nodo de la pila (implementada con lista enlazada) */
typedef struct NodoPila {
    int data;
    struct NodoPila *sig;
} NodoPila;

/* Pila (stack) */
typedef struct {
    NodoPila *tope;
    size_t    size;
} Pila;

/* Inicializa la pila vacía. */
void pila_init(Pila *p);

/* Agrega un elemento a la parte superior de la pila. */
void pila_push(Pila *p, int valor);

/* Elimina y devuelve el elemento en la parte superior de la pila. */
int pila_pop(Pila *p);

/* Devuelve el elemento en la parte superior sin eliminarlo. */
int pila_peek(Pila *p);

/* Verifica si la pila esta vacia. Retorna 1 si esta vacia, 0 si no. */
int pila_is_empty(Pila *p);

/* Imprime los elementos de la pila desde el tope. */
void pila_print(Pila *p);

/* Libera toda la memoria reservada y resetea la estructura. */
void pila_free(Pila *p);

#endif
