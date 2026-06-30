#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void pila_init(Pila *p) {
    p->tope = NULL;
    p->size = 0;
}

void pila_push(Pila *p, int valor) {
    NodoPila *nuevo = (NodoPila *) malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria en pila_push\n");
        exit(EXIT_FAILURE);
    }
    nuevo->data = valor;
    nuevo->sig  = p->tope;
    p->tope = nuevo;
    p->size++;
}

int pila_pop(Pila *p) {
    if (pila_is_empty(p)) {
        fprintf(stderr, "Error: no se puede hacer pop, la pila esta vacia\n");
        exit(EXIT_FAILURE);
    }
    NodoPila *nodo = p->tope;
    int valor = nodo->data;
    p->tope = nodo->sig;
    free(nodo);
    p->size--;
    return valor;
}

int pila_peek(Pila *p) {
    if (pila_is_empty(p)) {
        fprintf(stderr, "Error: no se puede hacer peek, la pila esta vacia\n");
        exit(EXIT_FAILURE);
    }
    return p->tope->data;
}

int pila_is_empty(Pila *p) {
    return p->size == 0;
}

void pila_print(Pila *p) {
    NodoPila *actual = p->tope;
    printf("tope -> [ ");
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->sig;
    }
    printf("] size=%zu\n", p->size);
}

void pila_free(Pila *p) {
    NodoPila *actual = p->tope;
    while (actual != NULL) {
        NodoPila *siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
    p->tope = NULL;
    p->size = 0;
}
