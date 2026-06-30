#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void le_init(ListaEnl *l) {
    l->cabeza = NULL;
    l->size = 0;
}

static Nodo *le_crear_nodo(int valor) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevo->data = valor;
    nuevo->sig = NULL;
    return nuevo;
}

void le_insertar_inicio(ListaEnl *l, int valor) {
    Nodo *nuevo = le_crear_nodo(valor);
    nuevo->sig = l->cabeza;
    l->cabeza = nuevo;
    l->size++;
}

void le_insertar_final(ListaEnl *l, int valor) {
    Nodo *nuevo = le_crear_nodo(valor);
    if (l->cabeza == NULL) {
        l->cabeza = nuevo;
    } else {
        Nodo *actual = l->cabeza;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevo;
    }
    l->size++;
}

void le_insertar_pos(ListaEnl *l, size_t i, int valor) {
    if (i > l->size) {
        fprintf(stderr, "Error: posicion %zu fuera de rango\n", i);
        return;
    }
    if (i == 0) {
        le_insertar_inicio(l, valor);
        return;
    }
    Nodo *nuevo = le_crear_nodo(valor);
    Nodo *actual = l->cabeza;
    for (size_t j = 0; j < i - 1; j++) {
        actual = actual->sig;
    }
    nuevo->sig = actual->sig;
    actual->sig = nuevo;
    l->size++;
}

void le_eliminar(ListaEnl *l, int valor) {
    Nodo *actual = l->cabeza;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->data != valor) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual == NULL) {
        /* no se encontró el valor */
        return;
    }

    if (anterior == NULL) {
        /* el nodo a eliminar es la cabeza */
        l->cabeza = actual->sig;
    } else {
        anterior->sig = actual->sig;
    }

    free(actual);
    l->size--;
}

int le_buscar(ListaEnl *l, int valor) {
    Nodo *actual = l->cabeza;
    while (actual != NULL) {
        if (actual->data == valor) {
            return 1;
        }
        actual = actual->sig;
    }
    return 0;
}

void le_print(ListaEnl *l) {
    Nodo *actual = l->cabeza;
    printf("[ ");
    while (actual != NULL) {
        printf("%d ", actual->data);
        actual = actual->sig;
    }
    printf("] size=%zu\n", l->size);
}

void le_free(ListaEnl *l) {
    Nodo *actual = l->cabeza;
    while (actual != NULL) {
        Nodo *siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
    l->cabeza = NULL;
    l->size = 0;
}
