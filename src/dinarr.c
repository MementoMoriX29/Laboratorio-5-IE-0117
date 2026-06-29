#include <stdio.h>
#include <stdlib.h>
#include "dinarr.h"

void da_init(DinaArray *da, size_t cap_inicial) {
    da->data = (int *) malloc(cap_inicial * sizeof(int));
    if (da->data == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria en da_init\n");
        exit(EXIT_FAILURE);
    }
    da->size = 0;
    da->capacidad = cap_inicial;
}

void da_push(DinaArray *da, int valor) {
    if (da->size == da->capacidad) {
        size_t nueva_cap = da->capacidad * 2;
        int *nuevo = (int *) realloc(da->data, nueva_cap * sizeof(int));
        if (nuevo == NULL) {
            fprintf(stderr, "Error: no se pudo expandir el arreglo\n");
            exit(EXIT_FAILURE);
        }
        da->data = nuevo;
        da->capacidad = nueva_cap;
    }
    da->data[da->size] = valor;
    da->size++;
}

int da_get(DinaArray *da, size_t i) {
    if (i >= da->size) {
        fprintf(stderr, "Error: indice %zu fuera de rango\n", i);
        exit(EXIT_FAILURE);
    }
    return da->data[i];
}

