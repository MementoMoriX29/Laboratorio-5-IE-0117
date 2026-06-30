#include <stdio.h>
#include <stdlib.h>
#include "listadbl.h"

void ld_init(ListaDbl *l) {
    l->cabeza = NULL;
    l->cola   = NULL;
    l->size   = 0;
}

static NodoDbl *ld_crear_nodo(int valor) {
    NodoDbl *nuevo = (NodoDbl *) malloc(sizeof(NodoDbl));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevo->data = valor;
    nuevo->ant  = NULL;
    nuevo->sig  = NULL;
    return nuevo;
}

void ld_insertar_inicio(ListaDbl *l, int valor) {
    NodoDbl *nuevo = ld_crear_nodo(valor);
    if (l->cabeza == NULL) {
        l->cabeza = nuevo;
        l->cola   = nuevo;
    } else {
        nuevo->sig      = l->cabeza;
        l->cabeza->ant  = nuevo;
        l->cabeza       = nuevo;
    }
    l->size++;
}

void ld_insertar_final(ListaDbl *l, int valor) {
    NodoDbl *nuevo = ld_crear_nodo(valor);
    if (l->cola == NULL) {
        l->cabeza = nuevo;
        l->cola   = nuevo;
    } else {
        nuevo->ant   = l->cola;
        l->cola->sig = nuevo;
        l->cola      = nuevo;
    }
    l->size++;
}

void ld_insertar_pos(ListaDbl *l, size_t i, int valor) {
    if (i > l->size) {
        fprintf(stderr, "Error: posicion %zu fuera de rango\n", i);
        return;
    }
    if (i == 0) {
        ld_insertar_inicio(l, valor);
        return;
    }
    if (i == l->size) {
        ld_insertar_final(l, valor);
        return;
    }
    NodoDbl *nuevo  = ld_crear_nodo(valor);
    NodoDbl *actual = l->cabeza;
    for (size_t j = 0; j < i; j++) {
        actual = actual->sig;
    }
    /* insertar antes de actual */
    nuevo->sig       = actual;
    nuevo->ant       = actual->ant;
    actual->ant->sig = nuevo;
    actual->ant      = nuevo;
    l->size++;
}

void ld_eliminar(ListaDbl *l, int valor) {
    NodoDbl *actual = l->cabeza;
    while (actual != NULL && actual->data != valor) {
        actual = actual->sig;
    }
    if (actual == NULL) return;  /* no encontrado */

    if (actual->ant != NULL) {
        actual->ant->sig = actual->sig;
    } else {
        l->cabeza = actual->sig;  /* era la cabeza */
    }

    if (actual->sig != NULL) {
        actual->sig->ant = actual->ant;
    } else {
        l->cola = actual->ant;    /* era la cola */
    }

    free(actual);
    l->size--;
}

int ld_buscar(ListaDbl *l, int valor) {
    NodoDbl *actual = l->cabeza;
    while (actual != NULL) {
        if (actual->data == valor) return 1;
        actual = actual->sig;
    }
    return 0;
}

void ld_print_adelante(ListaDbl *l) {
    NodoDbl *actual = l->cabeza;
    printf("adelante [ ");
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->sig;
    }
    printf("] size=%zu\n", l->size);
}

void ld_print_atras(ListaDbl *l) {
    NodoDbl *actual = l->cola;
    printf("atras    [ ");
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->ant;
    }
    printf("] size=%zu\n", l->size);
}

void ld_free(ListaDbl *l) {
    NodoDbl *actual = l->cabeza;
    while (actual != NULL) {
        NodoDbl *siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
    l->cabeza = NULL;
    l->cola   = NULL;
    l->size   = 0;
}
