#ifndef DINARR_H
#define DINARR_H

#include <stddef.h>

/* Arreglo dinámico de enteros */
typedef struct {
    int    *data;
    size_t  size;       /* elementos actualmente almacenados */
    size_t  capacidad;  /* elementos que caben antes de expandir */
} DinaArray;

/* Inicializa el arreglo con una capacidad inicial dada. */
void da_init(DinaArray *da, size_t cap_inicial);

/* Agrega un elemento al final. Expande (duplica capacidad) si es necesario. */
void da_push(DinaArray *da, int valor);

/* Elimina el elemento en la posición i, recorriendo los demás hacia atrás. */
void da_eliminar(DinaArray *da, size_t i);

/* Retorna el elemento en la posición i. */
int da_get(DinaArray *da, size_t i);

/* Imprime todos los elementos del arreglo. */
void da_print(DinaArray *da);

/* Libera la memoria reservada y resetea la estructura. */
void da_free(DinaArray *da);

#endif

